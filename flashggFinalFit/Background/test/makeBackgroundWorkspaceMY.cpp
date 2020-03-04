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

    int periods[] = {0};
    int period_names[] = {2016};

    int channels[] = {0, 1, 2}; 
    std::string channel_names[] = {"mu", "ele", "ele_mu"};

    //int categories[] = {51, 52, 1, 2, 3};
    //std::string cat_names[] = {"dijet_1", "dijet_2", "untagged_1", 
    //                           "untagged_2", "untagged_3"};
    
    //std::string cat_names[] = {"untagged_1"};

    int categories[] = {1, 2, 3, 4, 501, 502, 503};
    for (unsigned int i = 0; i < sizeof(periods)/sizeof(int); i++) {

        for (unsigned int j = 0; j < sizeof(channels)/sizeof(int); j++) {
            RooWorkspace *w = new RooWorkspace("cms_hzg_workspace");
            RooRealVar *IntLumi = new RooRealVar("IntLumi", "IntLumi", 0, 359000);
            RooRealVar *CMS_hzg_mass = new RooRealVar("CMS_hzg_mass", "CMS_hzg_mass", 115, 170);
            RooArgSet *mass_argset = new RooArgSet(*CMS_hzg_mass);
            w->import(*CMS_hzg_mass);
            w->import(*IntLumi);
            char filename[50];
            sprintf(filename, "hzg_data_MY/output_%s_%i.root", channel_names[j].c_str(), period_names[i]);
            TFile *inFile = TFile::Open(filename);

            if (j == 0 || j == 1) {
                for (unsigned int k = 0; k < sizeof(categories)/sizeof(int); k++) {
                    char treename[50];
                    sprintf(treename, "data_%d", categories[k]);
                    TTree *dataTree = (TTree *)inFile->Get(treename);              
                    char dataname[50];
                    sprintf(dataname, "Data_13TeV_%d", categories[k]);
                    RooDataSet *data = new RooDataSet(dataname, dataname, dataTree, *mass_argset);
                    w->import(*data);
                }
            }
            else {
                char treename[50];
                sprintf(treename, "data_6789");
                TTree *dataTree = (TTree *)inFile->Get(treename);              
                char dataname[50];
                sprintf(dataname, "Data_13TeV_6789");
                RooDataSet *data = new RooDataSet(dataname, dataname, dataTree, *mass_argset);
                w->import(*data);
            }

            w->Print();
            char outname[50];
            sprintf(outname, "workspaces_MY/WS_%s_%i.root", channel_names[j].c_str(), period_names[i]);
            w->SaveAs(outname);
        }
    }
    
    return 0;
}
