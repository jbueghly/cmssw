#!/bin/sh

echo "making bg workspaces"
./bin/makeBackgroundWorkspaceMY_newcats

echo "running fTests for hzg analysis"

# LOOP OVER UPPER BOUND OF FIT RANGE
#for maxVal in 135 140 145 150 155 160 165 170
for maxVal in 170
do 
    for year in 2016 2017 2018
    do
        for channel in ele mu
        do

            ./bin/fTest -i workspaces_MY/WS_${channel}_${year}.root --saveMultiPdf pdfs_MY_sideband_only/pdf_${channel}_${year}_${maxVal}.root -D plots_MY_sideband_only/${channel}_${year}/${maxVal} -f 1,2,3,4 --isData 1 --verbose 1 --channel ${channel} --era ${year} --rangeMin 115 --rangeMax $maxVal --sidebandOnly 
            echo "${channel} ${year} complete for rangeMax = ${maxVal}"
        done
    done

    ./bin/fTest -i workspaces_MY/WS_combined.root --saveMultiPdf pdfs_MY_sideband_only/pdf_combined_${maxVal}.root -D plots_MY_sideband_only/combined/${maxVal} -f 501,502,503,6789 --isData 1 --verbose 1 --channel combined --era combined --rangeMin 115 --rangeMax $maxVal --sidebandOnly 
    echo "combined categories complete for rangeMax = ${maxVal}"
done

