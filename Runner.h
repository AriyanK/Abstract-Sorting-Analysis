#ifndef ABSTRACTSORTING_RUNNER_H
#define ABSTRACTSORTING_RUNNER_H
#include <iostream>
#include <chrono>
#include <fstream>
#include "DSVector.h"
using namespace std;

class Runner {
public:
    void run();
    void generateInt();
    void generateString();
    int sizes[6] = {1000, 10000, 100000, 150000, 200000, 250000};
    //int sizes[6] = {10, 20, 30, 40, 50, 60};

private:
    ofstream out;

    int* generateRandomI(int size);
    int* generateAscI(int size);
    int* generateDescI(int size);
    int* generateD20I(int size);
    int* generateD40I(int size);

    string* generateRandomS(int size);
    string* generateAscS(int size);
    string* generateDescS(int size);
    string* generateD20S(int size);
    string* generateD40S(int size);



};


#endif //ABSTRACTSORTING_RUNNER_H
