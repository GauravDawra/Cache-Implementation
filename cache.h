#pragma once
#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include "resources.h"
using namespace std;

// extern const int WORD_SIZE;
// extern int binaryToDecimal(string s);

// enum type{
//     directive = 0,
//     associative
// };

// // template<type Type>
// // class cache{
// // private:
// //     int size, noOfLines, blockSize;
// //     int logS, logNOL, logBS;
// //     int Type;
// //     vector<string> tagArray;
// //     vector<vector<int> > dataArray;
// // public:
// //     cache() : size(0), noOfLines(0), blockSize(0) {}
// //     int associativePtr;
// //     cache(int T, int S, int CL, int B) : size(S), noOfLines(CL), blockSize(B)
// //     { 
// //         Type = T;
// //         logS = (int) log2(size);
// //         logNOL = (int) log2(noOfLines);
// //         logBS = (int) log2(blockSize);
// //         tagArray.assign(noOfLines,"");
// //         vector<int> c(blockSize, 0);
// //         dataArray.assign(noOfLines, c);
// //         associativePtr = 0;
// //     }

// //     // int nextPtr = 0;
// //     int associativeRead(string tag, string offset);
// //     void associativeWrite(string tag, string offset, int data);

// //     int read(string address){
// //         string offset = "";
// //         string tag = "";
// //         int tagSize = WORD_SIZE - logBS;
// //         for(int i=0;i<tagSize;i++)
// //             tag += address[i];

// //         for(int i=tagSize;i<address.length();i++)
// //             offset += address[i];

// //         switch(Type){
// //             case 1: // associative case
// //                 return associativeRead(tag, offset);
// //                 break;
// //         }
// //         return -1;
// //     }

// //     void write(string address, int data){
// //         string offset = "";
// //         string tag = "";
// //         int tagSize = WORD_SIZE - logBS;
        
// //         for(int i=0;i<tagSize;i++)
// //             tag += address[i];

// //         for(int i=tagSize;i<address.length();i++)
// //             offset += address[i];

// //         switch(Type){
// //             case 1: //associative case
// //                 associativeWrite(tag, offset, data);
// //                 return;
// //         }
// //         return;
// //     }

// //     void print(){
// //         cout << WORD_SIZE;
// //         // std::cout<<wordSize;
// //     }
// // };