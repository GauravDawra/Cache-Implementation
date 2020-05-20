#include "cache.h"
#include "n_wayAssociativeCache.h"

void n_wayAssociativeCache::write(string address, int data){
    int indexSize = log2(noOfLines / n);
    int tagSize = WORD_SIZE - indexSize - logBS;
    
    string tag = "";
    for(int i=0;i<tagSize;i++) tag += address[i];
    
    string index = "";
    for(int i=tagSize;i<tagSize+indexSize;i++) index+=address[i];
    
    string offset = "";
    for(int i=tagSize+indexSize;i<WORD_SIZE;i++) offset +=address[i];

    write(index, tag, offset, data);
}

int n_wayAssociativeCache::read(string address){
    int indexSize = log2(noOfLines / n);
    int tagSize = WORD_SIZE - indexSize - logBS;
    
    string tag = "";
    for(int i=0;i<tagSize;i++) tag += address[i];
    
    string index = "";
    for(int i=tagSize;i<tagSize+indexSize;i++) index+=address[i];
    
    string offset = "";
    for(int i=tagSize+indexSize;i<WORD_SIZE;i++) offset +=address[i];

    return read(index, tag, offset);
}

int n_wayAssociativeCache::read(string index, string tag, string offset){
    int start = binaryToDecimal(index) * n;
    for(int i=start;i<start+n;i++)
        if(tagArray[i] == tag) return dataArray[i][binaryToDecimal(offset)];
    
    std::cout << "READ MISS at address " << tag + index + offset << std::endl;
    return -1;
}

void n_wayAssociativeCache::write(string index, string tag, string offset, int data){
    int start = binaryToDecimal(index) * n;
    
    for(int i=start;i<start+n;i++){
        if(tagArray[i] == tag){
            dataArray[i][(binaryToDecimal(offset))] = data;
            cout<<'z'<<tag+index+offset<<endl;
            return;
        }
    }
    std::cout << "WRITE MISS at address " << tag + index + offset << std::endl;
    tagArray[start + n_wayAssociativePtr[start]] = tag;
    dataArray[start + n_wayAssociativePtr[start]][binaryToDecimal(offset)] = data;
    n_wayAssociativePtr[start] = (n_wayAssociativePtr[start] + 1) % n;
}