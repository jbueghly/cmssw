#!/bin/sh

echo "making bg workspaces"
./bin/makeBackgroundWorkspaceMY_newcats

echo "running fTests for hzg analysis"

# LOOP OVER UPPER BOUND OF FIT RANGE
for maxVal in 135 140 145 150 155 160 165 170
#for maxVal in 170
do 
    echo "running combined categories for rangeMax = ${maxVal}"
    ./bin/fTest -i workspaces_MY/WS_combined.root --saveMultiPdf pdfs_MY/pdf_combined_${maxVal}.root -D plots_MY/combined/${maxVal} -f 6789,501,502,503,1,2,3,4 --isData 1 --verbose 1 --channel combined --era combined --rangeMin 115 --rangeMax $maxVal #--sidebandOnly 
    echo "combined categories complete for rangeMax = ${maxVal}"
done

