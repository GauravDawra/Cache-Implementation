#pragma once

#include "cache.h"
#include "resources.h"
// int x = 10;

class n_wayAssociativeCache{
private:
    int size, noOfLines, blockSize, n;
    int logS, logNOL, logBS;
    vector<string> tagArray;
    vector<vector<int> > dataArray;
    vector<int> n_wayAssociativePtr;
    int read(string index, string tag, string offset);
    void write(string index, string tag, string offset, int data);
    
public:
    n_wayAssociativeCache(int CL, int B, int N = 0) : size(CL * B), noOfLines(CL), 
        blockSize(B), n(N)
    {
        logS = (int) log2(size);
        logNOL = (int) log2(noOfLines);
        logBS = (int) log2(blockSize);
        tagArray.assign(noOfLines, "");
        vector<int> c(blockSize, 0);
        dataArray.assign(noOfLines, c);
        n_wayAssociativePtr.assign(noOfLines / n, 0);
    }
    int read(string address);
    void write(string address, int data);
};