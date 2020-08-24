// Title: CSV Dataset directory separator tool (/test & /training)
// Author: Manuel Fernandez
//********************************************************************************
// Instructions:
// 1) Uncomment the 'WIN' macro if using Windows
// 2) Add your samples images in 'jpg' format to a folder
// 3) Label your images as 'sample{xx}.jpg' where xx is a numeric sequence
// 4) Use the 'absolute path' of the folder containing the samples when prompted
//*********************************************************************************

// Uncomment the 'WIN' macro if using Windows Operating System
// #define WIN

#include <iostream>
#include <string>
#include "datasetUtil.h"

int main (int argc, char *argv[]) {
    std::string path {};
    int samples {};
    
    path = promptSamplesPath();
    samples = promptSampleCount();
    
    int perc = (int)(samples * 0.7);
    int numbers[perc + 1];
    
    srand(static_cast<int>(time(0)));
    randGenerator(numbers, samples, perc);
    move(numbers, perc, path);
    
    generateTrainingCsv(path);
    generateTestCsv(path);
    
    return 0;
}
