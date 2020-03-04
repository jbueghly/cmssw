#!/bin/sh

echo "making bg workspaces"
./bin/makeBackgroundWorkspaceMY

echo "running fTests for hzg analysis"

# LOOP OVER UPPER BOUND OF FIT RANGE
#for maxVal in 135 140 145 150 155 160 165 170
for maxVal in 170
do 
./bin/fTest -i workspaces_MY/WS_mu_2016.root --saveMultiPdf pdfs_MY/pdf_mu_2016_${maxVal}.root -D plots_MY/mu_2016/${maxVal} -f 1,2,3,4,501,502,503 --isData 1 --verbose 1 --channel mu --era 2016 --rangeMin 115 --rangeMax $maxVal --sidebandOnly 
    echo "mu 2016 complete for rangeMax = ${maxVal}"
    
./bin/fTest -i workspaces_MY/WS_ele_2016.root --saveMultiPdf pdfs_MY/pdf_ele_2016_${maxVal}.root -D plots_MY/ele_2016/${maxVal} -f 1,2,3,4,501,502,503 --isData 1 --verbose 1 --channel ele --era 2016 --rangeMin 115 --rangeMax $maxVal --sidebandOnly 
    echo "ele 2016 complete for rangeMax = ${maxVal}"
    
    ./bin/fTest -i workspaces_MY/WS_ele_mu_2016.root --saveMultiPdf pdfs_MY/pdf_ele_mu_2016_${maxVal}.root -D plots_MY/ele_mu_2016/${maxVal} -f 6789 --isData 1 --verbose 1 --channel ele_mu --era 2016 --rangeMin 115 --rangeMax $maxVal --sidebandOnly 
    echo "ele_mu 2016 complete for rangeMax = ${maxVal}"
done

