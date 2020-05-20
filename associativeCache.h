#pragma once
#include <iostream>
#include <vector>
#include <math.h>
#include "resources.h"

using namespace std;

class associativeCache{
private:
    int size, noOfLines, blockSize;
    int logS, logNOL, logBS;
    vector<string> tagArray;
    vector<vector<int> > dataArray;
    int read(string tag, string offset);
    void write(string tag, string offset, int data);
    int associativePtr;

public:
    associativeCache() : size(0), noOfLines(0), blockSize(0) { }
    associativeCache(int CL, int B) : size(CL * B), noOfLines(CL), blockSize(B)
    {
        logS = (int) log2(size);
        logNOL = (int) log2(noOfLines);
        logBS = (int) log2(blockSize);
        tagArray.assign(noOfLines, "");
        vector<int> c(blockSize, 0);
        dataArray.assign(noOfLines, c);
        associativePtr = 0;
    }

    int read(string address);
    void write(string address, int data);

    void print(){ // for debugging
        cout << WORD_SIZE;
    }
};