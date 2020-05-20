// #include <iostream>
#include "cache.h"
#include "n_wayAssociativeCache.h"
// #include "directiveCache.h"
// #include "type.h"
using namespace std;

int main(){
    cache<n_wayAssociative> c(128, 64, 4);
    c.write("11101110000010001011001000100001", 201);
    c.write("11101110011010001011001000111101", 203);
    // cout<<'h'<<endl;
    c.write("11101110011010001011001000111001", 202);
    c.write("11101110011010001011001000111111", 204);
    cout<<c.read("11101110000010001011001000100001");
    cout<<endl;
    cout<<c.read("11101110011010001011001000111101");
    cout<<c.read("11101110011010001011001000111001");
    cout<<endl;
    // cout<<"1. "
    

    return 0;
}