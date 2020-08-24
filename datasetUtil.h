#pragma once

#include <string>
#include <dirent.h>

int promptSampleCount();
std::string promptSamplesPath();
void move(int randNum[], int perc, std::string path);
void randGenerator(int rNum[], int samples, int perc);
void generateTestCsv (std::string path);
void generateTrainingCsv (std::string path);
