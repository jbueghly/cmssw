#!/bin/sh

echo "making bg workspaces"
./bin/makeBackgroundWorkspace

echo "running fTests for hzg analysis"

echo "starting mmg 2016"
./bin/fTest -i workspaces/WS_mmg_2016.root --saveMultiPdf pdfs/pdf_mmg_2016.root -D plots/mmg_2016 -f dijet_1,dijet_2,dijet_3,untagged_1,untagged_2,untagged_3,untagged_4,lepton --isData 1 --verbose 1 --channel mmg --era 2016
echo "mmg 2016 complete"

echo "starting eeg 2016"
./bin/fTest -i workspaces/WS_eeg_2016.root --saveMultiPdf pdfs/pdf_eeg_2016.root -D plots/eeg_2016 -f dijet_1,dijet_2,dijet_3,untagged_1,untagged_2,untagged_3,untagged_4,lepton --isData 1 --verbose 1 --channel eeg --era 2016
echo "eeg 2016 complete"

echo "starting lepton 2016"
./bin/fTest -i workspaces/WS_lepton_2016.root --saveMultiPdf pdfs/pdf_lepton_2016.root -D plots/lepton_2016 -f dijet_1,dijet_2,dijet_3,untagged_1,untagged_2,untagged_3,untagged_4,lepton --isData 1 --verbose 1 --channel lepton --era 2016
echo "lepton 2016 complete"

#echo "starting mmg 2017"
#./bin/fTest -i workspaces/WS_mmg_2017.root --saveMultiPdf pdfs/pdf_mmg_2017.root -D plots/mmg_2017 -f dijet_1,dijet_2,dijet_3,untagged_1,untagged_2,untagged_3,untagged_4,lepton --isData 1 --verbose 1 --channel mmg --era 2017
#echo "mmg 2017 complete"
#
#echo "starting eeg 2017"
#./bin/fTest -i workspaces/WS_eeg_2017.root --saveMultiPdf pdfs/pdf_eeg_2017.root -D plots/eeg_2017 -f dijet_1,dijet_2,dijet_3,untagged_1,untagged_2,untagged_3,untagged_4,lepton --isData 1 --verbose 1 --channel eeg --era 2017
#echo "eeg 2017 complete"
#
#echo "starting lepton 2017"
#./bin/fTest -i workspaces/WS_lepton_2017.root --saveMultiPdf pdfs/pdf_lepton_2017.root -D plots/lepton_2017 -f dijet_1,dijet_2,dijet_3,untagged_1,untagged_2,untagged_3,untagged_4,lepton --isData 1 --verbose 1 --channel lepton --era 2017
#echo "lepton 2017 complete"
#
#echo "starting mmg 2018"
#./bin/fTest -i workspaces/WS_mmg_2018.root --saveMultiPdf pdfs/pdf_mmg_2018.root -D plots/mmg_2018 -f dijet_1,dijet_2,dijet_3,untagged_1,untagged_2,untagged_3,untagged_4,lepton --isData 1 --verbose 1 --channel mmg --era 2018
#echo "mmg 2018 complete"
#
#echo "starting eeg 2018"
#./bin/fTest -i workspaces/WS_eeg_2018.root --saveMultiPdf pdfs/pdf_eeg_2018.root -D plots/eeg_2018 -f dijet_1,dijet_2,dijet_3,untagged_1,untagged_2,untagged_3,untagged_4,lepton --isData 1 --verbose 1 --channel eeg --era 2018
#echo "eeg 2018 complete"
#
#echo "starting lepton 2018"
#./bin/fTest -i workspaces/WS_lepton_2018.root --saveMultiPdf pdfs/pdf_lepton_2018.root -D plots/lepton_2018 -f dijet_1,dijet_2,dijet_3,untagged_1,untagged_2,untagged_3,untagged_4,lepton --isData 1 --verbose 1 --channel lepton --era 2018
#echo "lepton 2018 complete"
