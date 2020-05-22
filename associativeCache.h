#pragma once
#include <math.h>

#include <iostream>
#include <vector>

#include "resources.h"

using namespace std;

class associativeCache {
private:
    int size, noOfLines, blockSize;
    int logS, logNOL, logBS;
    vector<string> tagArray;
    vector<vector<int> > dataArray;
    int read(string tag, string offset);
    void write(string tag, string offset, int data);
    int associativePtr;

public:
    associativeCache() : size(0), noOfLines(0), blockSize(0) {}
    associativeCache(int CL, int B);

    int read(string address);
    void write(string address, int data);
};