#include "cache.h"
#include "n_wayAssociativeCache.h"

n_wayAssociativeCache::n_wayAssociativeCache(int CL, int B, int N) : 
    size(CL * B), noOfLines(CL), blockSize(B), n(N)
    {
        logS = (int) log2(size);
        logNOL = (int) log2(noOfLines);
        logBS = (int) log2(blockSize);
        tagArray.assign(noOfLines, "");
        vector<int> c(blockSize, 0);
        dataArray.assign(noOfLines, c);
        n_wayAssociativePtr.assign(noOfLines / n, 0);
    }

void n_wayAssociativeCache::write(string address, int data){
    int indexSize = (int) log2(noOfLines / n);
    int tagSize = WORD_SIZE - indexSize - logBS;
    
    string tag = "";
    for(int i=0;i<tagSize;i++) 
        tag += address[i];
    
    string index = "";
    for(int i=tagSize;i<tagSize+indexSize;i++) 
        index+=address[i];
    
    string offset = "";
    for(int i=tagSize+indexSize;i<WORD_SIZE;i++) 
        offset +=address[i];

    write(index, tag, offset, data);
}

int n_wayAssociativeCache::read(string address){
    int indexSize = log2(noOfLines / n);
    int tagSize = WORD_SIZE - indexSize - logBS;
    
    string tag = "";
    for(int i=0;i<tagSize;i++) 
        tag += address[i];
    
    string index = "";
    for(int i=tagSize;i<tagSize+indexSize;i++) 
        index+=address[i];
    
    string offset = "";
    for(int i=tagSize+indexSize;i<WORD_SIZE;i++) 
        offset +=address[i];

    return read(index, tag, offset);
}

int n_wayAssociativeCache::read(string index, string tag, string offset){
    int start = binaryToDecimal(index) * n;
    for(int i=start;i<start+n;i++)
        if(tagArray[i] == tag) 
            return dataArray[i][binaryToDecimal(offset)];
    
    std::cout << "READ MISS at address " << tag + index + offset << std::endl;
    return -1;
}

void n_wayAssociativeCache::write(string index, string tag, string offset, int data){
    int Index = binaryToDecimal(index);
    int Offset = binaryToDecimal(offset);
    int start = Index * n;

    for(int i=start;i<start+n;i++){
        if(tagArray[i] == tag){
            dataArray[i][Offset] = data;
            return;
        }
    }
    std::cout << "WRITE MISS at address " << tag + index + offset << std::endl;
    tagArray[start + n_wayAssociativePtr[Index]] = tag;
    dataArray[start + n_wayAssociativePtr[Index]][Offset] = data;
    n_wayAssociativePtr[Index] = (n_wayAssociativePtr[Index] + 1) % n;
}