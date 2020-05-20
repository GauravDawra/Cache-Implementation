#pragma once

#include "cache.h"
#include "resources.h"

class directiveCache{
private:
    int size, noOfLines, blockSize;
    int logS, logNOL, logBS;
    vector<string> tagArray;
    vector<vector<int> > dataArray;
    int read(string index, string tag, string offset);
    void write(string index, string tag, string offset, int data);
public:
    directiveCache() : size(0), noOfLines(0), blockSize(0) { }
    directiveCache(int CL, int B) : size(CL * B), noOfLines (CL), blockSize(B)
    {
        logS = (int) log2(size);
        logNOL = (int) log2(noOfLines);
        logBS = (int) log2(blockSize);
        tagArray.assign(noOfLines, "#");
        vector<int> c(blockSize, 0);
        dataArray.assign(noOfLines, c);
    }

    int read(string address);
    void write(string address, int data);
};