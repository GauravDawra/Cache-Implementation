#include "cache.h"
#include "resources.h"
#include "associativeCache.h"

// template<type T>

int associativeCache::read(string address){
    string offset = "";
    string tag = "";
    int tagSize = WORD_SIZE - logBS;
    for(int i=0;i<tagSize;i++)
        tag += address[i];

    for(int i=tagSize;i<address.length();i++)
        offset += address[i];
    
    return read(tag, offset);
    
}

void associativeCache::write(string address, int data){
    string offset = "";
    string tag = "";
    int tagSize = WORD_SIZE - logBS;
    
    for(int i=0;i<tagSize;i++)
        tag += address[i];

    for(int i=tagSize;i<address.length();i++)
        offset += address[i];

    write(tag, offset, data);
    
    return;
}


int associativeCache::read(string tag, string offset){
    for(int i=0;i<noOfLines;i++){
        if(tagArray[i] == tag) return dataArray[i][binaryToDecimal(offset)];
    }
    std::cout << "READ MISS for address " << tag + offset << std::endl;
    return -1;
}

void associativeCache::write(string tag, string offset, int data){
    bool present = 0;
    int index=-1;
    for(int i=0;i<=noOfLines;i++) 
        if(tagArray[i] == tag) {
            present = 1; 
            index = i;
            break; 
        }

    if(present){
        dataArray[index][binaryToDecimal(offset)] = data;
    }

    else{
        std::cout << "WRITE MISS for address " << tag + offset << std::endl;
        vector<int> c(blockSize, 0);
        dataArray[associativePtr] = c;
        dataArray[associativePtr][binaryToDecimal(offset)] = data;
        tagArray[associativePtr] = tag;
        associativePtr = (associativePtr + 1) % noOfLines;
        return;
    }
}