#include "associativeCache.h"
#include "cache.h"
#include "resources.h"

associativeCache::associativeCache(int CL, int B) : 
    size(CL * B), noOfLines(CL), blockSize(B) 
{
    logS = (int) log2(size);
    logNOL = (int) log2(noOfLines);
    logBS = (int) log2(blockSize);
    tagArray.assign(noOfLines, "");
    vector<int> c(blockSize, 0);
    dataArray.assign(noOfLines, c);
    associativePtr = 0;
}

int associativeCache::read(string address) {
    string offset = "";
    string tag = "";
    int tagSize = WORD_SIZE - logBS;
    for (int i = 0; i < tagSize; i++)
        tag += address[i];

    for (int i = tagSize; i < address.length(); i++)
        offset += address[i];

    return read(tag, offset);
}

void associativeCache::write(string address, int data) {
    string offset = "";
    string tag = "";
    int tagSize = WORD_SIZE - logBS;

    for (int i = 0; i < tagSize; i++)
        tag += address[i];

    for (int i = tagSize; i < address.length(); i++)
        offset += address[i];

    write(tag, offset, data);

    return;
}

int associativeCache::read(string tag, string offset) {
    for (int i = 0; i < noOfLines; i++)
        if (tagArray[i] == tag) 
            return dataArray[i][binaryToDecimal(offset)];
    
    std::cout << "READ MISS for address " << tag + offset << std::endl;
    return -1;
}

void associativeCache::write(string tag, string offset, int data) {
    bool present = 0;
    int index = -1;
    for (int i = 0; i <= noOfLines; i++)
        if (tagArray[i] == tag) {
            present = 1;
            index = i;
            break;
        }

    if (present) 
        dataArray[index][binaryToDecimal(offset)] = data;
    
    else {
        std::cout << "WRITE MISS for address " << tag + offset << std::endl;
        vector<int> c(blockSize, 0);
        dataArray[associativePtr] = c;
        dataArray[associativePtr][binaryToDecimal(offset)] = data;
        tagArray[associativePtr] = tag;
        associativePtr = (associativePtr + 1) % noOfLines;
        return;
    }
}