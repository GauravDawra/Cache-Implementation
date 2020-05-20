#pragma once

#include "associativeCache.h"
#include "directiveCache.h"
#include "n_wayAssociativeCache.h"

#include <iostream>
#include <string>
#include <math.h>
#include <vector>

#include "resources.h"
#include "type.h"

using namespace std;

template<type T>
class cache : public associativeCache, public directiveCache, public n_wayAssociativeCache
{
private:
    int size, noOfLines, blockSize;
public:
    // cache() : size(0), noOfLines(0), blockSize(0) { }
    cache(int CL = 0, int B = 0, int n = 2) :  associativeCache(CL, B), 
        directiveCache(CL, B), n_wayAssociativeCache(CL, B, n)
    {
        size = CL * B; 
        noOfLines = CL;
        blockSize = B;
    }
    
    int read(string address){
        // cout
        switch(T){
            case associative:
                return associativeCache::read(address);
                break;
            case directive:
                return directiveCache::read(address);
                break;
            case n_wayAssociative:
                return n_wayAssociativeCache::read(address);
                break;
        }
    }
    void write(string address, int data){
        switch(T){
            case associative:
                associativeCache::write(address, data);
                break;
            case directive:
                directiveCache::write(address, data);
                break;
            case n_wayAssociative:
                n_wayAssociativeCache::write(address, data);
                break;
        }
    }

};