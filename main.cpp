// #include <iostream>
#include "cache.h"
#include "associativeCache.h"
#include "directiveCache.h"
#include "type.h"
using namespace std;

int main(){
    /* associative testing here */
    // associativeCache c(128, 64);
    // c.write("00000000000000000000000000000000", 101);
    // c.write("00101110000010001011000000100001", 102);
    // cout << c.read("00000000000000000000000000000000") << endl;
    // cout << c.read("00101110000010001011000000100001") << endl;
    // c.write("00101110000010001011000000100001", 103);
    // cout << c.read("00101110000010001011000000100001");

    /* directive testing here */
    // directiveCache c(128, 64);
    // cout<<c.read("11101110000010001011001000100001");
    // c.write("00101110000010001011000000100001", 121);
    // c.write("11101110000010001011001000100001", 123);
    // cout<<c.read("00101110000010001011000000100001");
    // cout<<c.read("11101110000010001011001000100001");

    // cout<<'h';
    cache<associative> c(128, 64);
    cout<<c.read("11101110000010001011001000100001");
    c.write("11101110000010001011001000100001", 201);
    cout<<c.read("11101110000010001011001000100001");

    // c.f("11101110000010001011001000100001");

    return 0;
}