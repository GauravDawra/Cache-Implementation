#include <iostream>
#include "cache.h"
#include "type.h"
// #include "resources.h"
using namespace std;
// int WORD_SIZE = 32;
//  extern int wordSize;
int main(){
    cache c(1,(1<<13),128,64);
    c.print();
    cout<<c.read("0000000000000000000000000000");
    
    return 0;
}