#include "cache.h"
// #include "type.h"

int binaryToDecimal(string s){
    int sum=0;
    for(int i=s.length()-1;i>=0;i--) {sum+=((s[i]-'0')*(1<<i));}
    return sum;
}

// template<type T>
int cache::associativeRead(string tag, string offset){
    // cout<<"working";
    // bool hit=false;
    for(int i=0;i<noOfLines;i++){
        if(tagArray[i] == tag) return dataArray[i][binaryToDecimal(offset)];
    }
    return -1;
}