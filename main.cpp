// #include <iostream>
#include "cache.h"
#include "associativeCache.h"
using namespace std;

int main(){
    associativeCache c((1<<13), 128, 64);
    c.write("00000000000000000000000000000000", 101);
    c.write("00101110000010001011000000100001", 102);
    cout << c.read("00000000000000000000000000000000");
    cout << c.read("00101110000010001011000000100001");

    return 0;
}