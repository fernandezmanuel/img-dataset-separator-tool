#include "datasetUtil.h"
#include <stdio.h>
#include <iostream>
#include <fstream>

std::string promptSamplesPath() {
    std::string path {};
    std::cout << "Please idicate the path that contains your samples: ";
    std::cin >> path;
    return path;
}

int promptSampleCount() {
    int samples {};
    std::cout << "Please indicate how many samples are available in the folder: ";
    std::cin >> samples;
    return samples;
}

void randGenerator(int rNum[], int samples, int perc) {
    for (size_t i = 0; i < perc; i++) {
        bool same = true;
        do {
            same = false;
            rNum[i] = rand() % samples + 1;
            // Verifies that each random number is unique
            for (size_t j = 0; j < i; j++) {
                if (rNum[i] == rNum[j]) {
                    same = true;
                    break;
                }
            }
        } while (same);
    }
}

void move(int rNum[], int perc, std::string path){
    
    // Creates both training and test folders using the provided path
#ifdef WIN
    system(("md " + path + "/training " + path + "/test").c_str());
#else
    system(("mkdir -p " + path + "/training " + path + "/test").c_str());
#endif
    
    // Moves 70% of the total samples to the training folder
    for (size_t i = 0; i < perc; i++) {
        std::string filename = "/sample" + std::to_string(rNum[i]) + ".jpg";
        std::string mvTrain;
#ifdef WIN
        mvTrain = "move " + path + filename + " " + path + "/training" + filename;
#else
        mvTrain = "mv " + path + filename + " " + path + "/training" + filename;
#endif
        system(mvTrain.c_str());
        std::cout << mvTrain << std::endl;
    }
    
    // Moves the rest of the samples to the test folder for later use
    std::string mvTest;
#ifdef WIN
    mvTest = "move " + path + "/*.* " + path + "/test";
#else
    mvTest = "mv " + path + "/*.* " + path + "/test";
#endif
    system(mvTest.c_str());
    std::cout << mvTest << std::endl;
}

void generateTrainingCsv (std::string path) {
    std::string npath(path);
    npath += "/training";
    std::cout << "\nGenerating 'training.csv' file ..." << std::endl;
    
    DIR *dp;
    struct dirent *ep;
    
    dp = opendir (npath.c_str());
    
    if (dp != NULL) {
        std::ofstream myfile;
        myfile.open(path + "/training.csv");
        std::cout << path << std::endl;
        
        // Reads each filename from the training folder and appends them to the training.csv file
        while ((ep = readdir (dp))){
            if (ep->d_name[0] != '.') {
                puts(ep->d_name);
                myfile << ep->d_name << "\n";
            }
        }
        std::cout << "'training.csv' generated successfully" << std::endl;
        myfile.close();
        (void) closedir (dp);
    } else {
        perror ("Couldn't open the directory");
    }
}

void generateTestCsv (std::string path) {
    std::string npath(path);
    npath += "/test";
    std::cout << "\nGenerating 'test.csv' file ..." << std::endl;
    
    DIR *dp;
    struct dirent *ep;
    
    dp = opendir (npath.c_str());
    
    if (dp != NULL) {
        std::ofstream myfile;
        myfile.open(path + "/test.csv");
        std::cout << path << std::endl;
        
        // Reads each filename from the test folder and appends them to the test.csv file
        while ((ep = readdir (dp))){
            if (ep->d_name[0] != '.') {
                puts(ep->d_name);
                myfile << ep->d_name << "\n";
            }
        }
        std::cout << "'test.csv' generated successfully" << std::endl;
        myfile.close();
        (void) closedir (dp);
    } else {
        perror ("Couldn't open the directory");
    }
}
