#!/usr/bin/env python

import numpy as np
import ROOT as r

if __name__ == '__main__':

    bkg_ref = r.TFile('pdfs_MY/reference/bkg_ele_mu_2.root')
    #bkg_test = r.TFile('pdfs_MY/pdf_combined_170.root')
    bkg_test = r.TFile('pdfs_MY_sideband/pdf_combined_170.root')

    ws_ref = bkg_ref.Get('multipdf')
    ws_test = bkg_test.Get('multipdf')

    #ws_ref.Print()
    #ws_test.Print()

    args_ref = ws_ref.allVars()
    iter_ref = args_ref.createIterator()
    var = iter_ref.Next()
    while var:
        print(var.GetName())
        print(var.getValV())
        var = iter_ref.Next()
    
    args_test = ws_test.allVars()
    iter_test = args_test.createIterator()
    var = iter_test.Next()
    while var:
        print(var.GetName())
        print(var.getValV())
        var = iter_test.Next()

    #for var in ws_ref.allVars():
    #    print(var.GetValV())
