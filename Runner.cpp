#include "Runner.h"
#include <iostream>
#include <chrono>
#include <algorithm>
#include <random>
#include "DSVector.h"
#include "Algorithms.h"
#include <fstream>
using namespace std;

void Runner::run() {
    out.open("intData.csv");
    out << "Algo, ";
    for(int x = 0; x < 6; x++){
        out << "Ascending(" + to_string(sizes[x]) + "), ";
        out << "Descending(" + to_string(sizes[x]) + "), ";
        out << "Random(" + to_string(sizes[x]) + "), ";
        out << "D20%(" + to_string(sizes[x]) + "), ";
        out << "D40%(" + to_string(sizes[x]) + "), ";
    }
    out << endl;
    generateInt();
    out.close();

    out.open("stringData.csv");
    out << "Algo, ";
    for(int x = 0; x < 6; x++){
        out << "Ascending(" + to_string(sizes[x]) + "), ";
        out << "Descending(" + to_string(sizes[x]) + "), ";
        out << "Random(" + to_string(sizes[x]) + "), ";
        out << "D20%(" + to_string(sizes[x]) + "), ";
        out << "D40%(" + to_string(sizes[x]) + "), ";
    }
    out << endl;
    generateString();
}

void Runner::generateInt() {
    chrono::time_point<chrono::high_resolution_clock> start, end;
    chrono::duration<double> time_in_seconds;

    //Data sizes : {100, 1000, 5000,

    /*for(int x = 0; x < 6; x++){
        generateRandom(sizes[x]);
    }*/
    vector<DSVector<int>> sets;
    for(int x = 0; x < 6; x++){
        for(int y = 0; y < 5; y++){
            if(y == 0)
                sets.push_back(DSVector<int>(generateAscI(sizes[x]), sizes[x]));
            if(y == 1)
                sets.push_back(DSVector<int>(generateDescI(sizes[x]), sizes[x]));
            if(y == 2)
                sets.push_back(DSVector<int>(generateRandomI(sizes[x]), sizes[x]));
            if(y == 3)
                sets.push_back(DSVector<int>(generateD20I(sizes[x]), sizes[x]));
            if(y == 4)
                sets.push_back(DSVector<int>(generateD40I(sizes[x]), sizes[x]));
        }
    }
    for(int y = 0; y < 3; y++) {
        if(y == 0)
            out << "Insertion sort, ";
        if(y == 1)
            out << "Quicksort, ";
        if(y == 2)
            out << "Heapsort, ";
        for (int x = 0; x < sets.size(); x++) {
            if(y == 0) {
                start = chrono::high_resolution_clock::now();
                Algorithms::myInsertionSort(sets[x].begin(), sets[x].end());
                end = chrono::high_resolution_clock::now();
                time_in_seconds = end - start;
                out << fixed << to_string(time_in_seconds.count()) + ", ";
            }
            if(y == 1){
                start = chrono::high_resolution_clock::now();
                Algorithms::myQuickSort(sets[x].begin(), sets[x].end());
                end = chrono::high_resolution_clock::now();
                time_in_seconds = end - start;
                out << fixed << to_string(time_in_seconds.count()) + ", ";
            }
            if(y == 2){
                start = chrono::high_resolution_clock::now();
                Algorithms::myHeapSort(sets[x].begin(), sets[x].end());
                end = chrono::high_resolution_clock::now();
                time_in_seconds = end - start;
                out << fixed << to_string(time_in_seconds.count()) + ", ";
            }
        }
        out << endl;
    }

}

void Runner::generateString(){
    chrono::time_point<chrono::high_resolution_clock> start, end;
    chrono::duration<double> time_in_seconds;

    //Data sizes : {100, 1000, 5000,

    /*for(int x = 0; x < 6; x++){
        generateRandom(sizes[x]);
    }*/
    vector<DSVector<string>> sets;
    for(int x = 0; x < 6; x++){
        for(int y = 0; y < 5; y++){
            if(y == 0)
                sets.push_back(DSVector<string>(generateAscS(sizes[x]), sizes[x]));
            if(y == 1)
                sets.push_back(DSVector<string>(generateDescS(sizes[x]), sizes[x]));
            if(y == 2)
                sets.push_back(DSVector<string>(generateRandomS(sizes[x]), sizes[x]));
            if(y == 3)
                sets.push_back(DSVector<string>(generateD20S(sizes[x]), sizes[x]));
            if(y == 4)
                sets.push_back(DSVector<string>(generateD40S(sizes[x]), sizes[x]));
        }
    }
    for(int y = 0; y < 3; y++) {
        if(y == 0)
            out << "Insertion sort, ";
        if(y == 1)
            out << "Quicksort, ";
        if(y == 2)
            out << "Heapsort, ";
        for(int x = 0; x < sets.size(); x++) {
            if(y == 0) {
                start = chrono::high_resolution_clock::now();
                Algorithms::myInsertionSort(sets[x].begin(), sets[x].end());
                end = chrono::high_resolution_clock::now();
                time_in_seconds = end - start;
                out << fixed << to_string(time_in_seconds.count()) + ", ";
            }
            if(y == 1){
                start = chrono::high_resolution_clock::now();
                Algorithms::myQuickSort(sets[x].begin(), sets[x].end());
                end = chrono::high_resolution_clock::now();
                time_in_seconds = end - start;
                out << fixed << to_string(time_in_seconds.count()) + ", ";
            }
            if(y == 2){
                start = chrono::high_resolution_clock::now();
                Algorithms::myHeapSort(sets[x].begin(), sets[x].end());
                end = chrono::high_resolution_clock::now();
                time_in_seconds = end - start;
                out << fixed << to_string(time_in_seconds.count()) + ", ";
            }
        }
        out << endl;
    }
}

int* Runner::generateRandomI(int size) {
    int* randomSet = generateAscI(size);
    shuffle(randomSet, randomSet + size, std::mt19937(std::random_device()()));
    return randomSet;
}

int* Runner::generateAscI(int size) {
    int* ascSet = new int[size];
    for(int x = 0; x < size; x++){
        ascSet[x] = x;
    }
    return ascSet;
}

int* Runner::generateDescI(int size) {
    int* descSet = new int[size];
    for(int x = 0; x < size; x++){
        descSet[x] = (size - x) - 1;
    }
    return descSet;
}

int* Runner::generateD20I(int size) {
    int* D20Set = new int[size];
    for(int x = 0; x < size; x++){
        if(x < (size*0.2)){
            D20Set[x] = 0;
        }
        else
            D20Set[x] = x;
    }
    shuffle(D20Set, D20Set + size, std::mt19937(std::random_device()()));
    return D20Set;
}

int* Runner::generateD40I(int size) {
    int* D40Set = new int[size];
    for(int x = 0; x < size; x++){
        if(x < (size*0.4)){
            D40Set[x] = 0;
        }
        else
            D40Set[x] = x;
    }
    shuffle(D40Set, D40Set + size, std::mt19937(std::random_device()()));
    return D40Set;
}


string* Runner::generateRandomS(int size) {
    std::random_device device;
    std::mt19937 generator(device());
    std::uniform_int_distribution<int> distribution(1000000000,2147483647);

    auto* strings = new string[size];

    for(int x = 0; x < size; x++){
        strings[x] = std::to_string(distribution(generator));
    }
    return strings;
}

string* Runner::generateAscS(int size) {
    auto* strings = new string[size];
    int i = 1000000000;
    for(int x = 0; x < size; x++){
        strings[x] = to_string(i++);
    }
    return strings;
}

string* Runner::generateDescS(int size) {
    auto* strings = new string[size];
    int i = 2147483647;
    for(int x = 0; x < size; x++){
        strings[x] = to_string(i--);
    }
    return strings;
}

string* Runner::generateD20S(int size) {
    std::random_device device;
    std::mt19937 generator(device());
    std::uniform_int_distribution<int> distribution(1000000000,2147483647);

    auto* D20Set = new string[size];
    for(int x = 0; x < size; x++){
        if(x < (size*0.2)){
            D20Set[x] = "0000000000";
        }
        else
            D20Set[x] = to_string(distribution(generator));
    }
    shuffle(D20Set, D20Set + size, std::mt19937(std::random_device()()));
    return D20Set;
}

string* Runner::generateD40S(int size) {
    std::random_device device;
    std::mt19937 generator(device());
    std::uniform_int_distribution<int> distribution(1000000000,2147483647);

    auto* D40Set = new string[size];
    for(int x = 0; x < size; x++){
        if(x < (size*0.4)){
            D40Set[x] = "0000000000";
        }
        else
            D40Set[x] = to_string(distribution(generator));
    }
    shuffle(D40Set, D40Set + size, std::mt19937(std::random_device()()));
    return D40Set;
}















