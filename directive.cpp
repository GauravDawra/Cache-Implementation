#include "cache.h"
#include "directiveCache.h"

directiveCache::directiveCache(int CL, int B) : size(CL * B), noOfLines (CL), blockSize(B)
{
    logS = (int) log2(size);
    logNOL = (int) log2(noOfLines);
    logBS = (int) log2(blockSize);
    tagArray.assign(noOfLines, "#");
    vector<int> c(blockSize, 0);
    dataArray.assign(noOfLines, c);
}

int directiveCache::read(string address){
    int tagSize = WORD_SIZE - logNOL - logBS;
    
    string tag = "";
    for(int i=0;i<tagSize;i++) tag += address[i];
    
    string index = "";
    for(int i=tagSize;i<tagSize+logNOL;i++) index+=address[i];
    
    string offset = "";
    for(int i=tagSize+logNOL;i<WORD_SIZE;i++) offset +=address[i];
    
    return read(index, tag, offset);
}

void directiveCache::write(string address, int data){
    int tagSize = WORD_SIZE - logNOL - logBS;
    
    string tag = "";
    for(int i=0;i<tagSize;i++) tag += address[i];
    
    string index = "";
    for(int i=tagSize;i<tagSize+logNOL;i++) index+=address[i];
    
    string offset = "";
    for(int i=tagSize+logNOL;i<WORD_SIZE;i++) offset +=address[i];

    write(index, tag, offset, data);
    
}

int directiveCache::read(string index, string tag, string offset){
    int Index = binaryToDecimal(index);
    int Offset = binaryToDecimal(offset);

    if(tagArray[Index] == "#" ||
        tagArray[Index] != tag){
        std::cout << "READ MISS at address " << tag + index + offset << std::endl;
        return -1;
    }

    return dataArray[Index][Offset];
}

void directiveCache::write(string index, string tag, string offset, int data){
    int Index = binaryToDecimal(index);
    int Offset = binaryToDecimal(offset);
    
    if(tagArray[Index] == "#" || 
        tagArray[Index] != tag)
            std::cout << "WRITE MISS at address " << tag + index + offset << std::endl;
            // return;
    

    tagArray[Index] = tag;
    dataArray[Index][Offset] = data;
}
