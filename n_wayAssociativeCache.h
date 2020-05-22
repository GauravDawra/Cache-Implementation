#pragma once

#include "cache.h"
#include "resources.h"

class n_wayAssociativeCache {
private:
    int size, noOfLines, blockSize, n;
    int logS, logNOL, logBS;
    vector<string> tagArray;
    vector<vector<int> > dataArray;
    vector<int> n_wayAssociativePtr;
    int read(string index, string tag, string offset);
    void write(string index, string tag, string offset, int data);

public:
    n_wayAssociativeCache(int CL, int B, int N = 2);
    int read(string address);
    void write(string address, int data);
};