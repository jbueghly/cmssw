#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "TFile.h"
#include "TTree.h"

#include "RooWorkspace.h"
#include "RooRealVar.h"
#include "RooDataSet.h"
#include "RooArgSet.h"

int main() {

    int categories[] = {6789, 501, 502, 503, 1, 2, 3, 4};

    RooWorkspace *w = new RooWorkspace("cms_hzg_workspace");
    RooRealVar *IntLumi = new RooRealVar("IntLumi", "IntLumi", 0, 359000);
    RooRealVar *CMS_hzg_mass = new RooRealVar("CMS_hzg_mass", "CMS_hzg_mass", 115, 170);
    RooArgSet *mass_argset = new RooArgSet(*CMS_hzg_mass);
    w->import(*CMS_hzg_mass);
    w->import(*IntLumi);
    char filename[50];
    sprintf(filename, "hzg_data_MY/output_combined.root");
    TFile *inFile = TFile::Open(filename);

    for (unsigned int i = 0; i < sizeof(categories)/sizeof(int); i++) {
        char treename[50];
        sprintf(treename, "data_%d", categories[i]);
        TTree *dataTree = (TTree *)inFile->Get(treename);              
        char dataname[50];
        sprintf(dataname, "Data_13TeV_%d", categories[i]);
        RooDataSet *data = new RooDataSet(dataname, dataname, dataTree, *mass_argset);
        w->import(*data);
    }

    w->Print();
    char outname[50];
    sprintf(outname, "workspaces_MY/WS_combined.root");
    w->SaveAs(outname);
         
    return 0;
}
