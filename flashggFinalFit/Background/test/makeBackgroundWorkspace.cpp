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

    int periods[] = {0, 1, 2};
    int period_names[] = {2016, 2017, 2018};

    int channels[] = {0, 1, 2}; // mmg
    std::string channel_names[] = {"mmg", "eeg", "lepton"};

    int categories[] = {51, 52, 53, 1, 2, 3, 4, 6789};
    std::string cat_names[] = {"dijet_1", "dijet_2", "dijet_3", "untagged_1", 
                               "untagged_2", "untagged_3", "untagged_4", "lepton"};

    for (unsigned int i = 0; i < sizeof(periods)/sizeof(int); i++) {

        for (unsigned int j = 0; j < sizeof(channels)/sizeof(int); j++) {
            RooWorkspace *w = new RooWorkspace("cms_hzg_workspace");
            RooRealVar *IntLumi = new RooRealVar("IntLumi", "IntLumi", 0, 359000);
            RooRealVar *CMS_hzg_mass = new RooRealVar("CMS_hzg_mass", "CMS_hzg_mass", 115, 170);
            RooArgSet *mass_argset = new RooArgSet(*CMS_hzg_mass);
            w->import(*CMS_hzg_mass);
            w->import(*IntLumi);
            char filename[50];
            sprintf(filename, "hzg_data/output_%s_%i.root", channel_names[j].c_str(), period_names[i]);
            TFile *inFile = TFile::Open(filename);

            for (unsigned int k = 0; k < sizeof(categories)/sizeof(int); k++) {
                char treename[50];
                sprintf(treename, "data_%s", cat_names[k].c_str());
                TTree *dataTree = (TTree *)inFile->Get(treename);              
                char dataname[50];
                sprintf(dataname, "Data_13TeV_%s", cat_names[k].c_str());
                RooDataSet *data = new RooDataSet(dataname, dataname, dataTree, *mass_argset);
                w->import(*data);
            }
            w->Print();
            char outname[50];
            sprintf(outname, "workspaces/WS_%s_%i.root", channel_names[j].c_str(), period_names[i]);
            w->SaveAs(outname);
        }
    }
    
    return 0;
}
