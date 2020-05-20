#include "cache.h"
#include <string>

// using namespace std;

const int WORD_SIZE = 32;

int binaryToDecimal(string s){
    int sum=0;
    int n = s.length();
    for(int i=n-1;i>=0;i--) 
        sum+=((s[i]-'0') * (1 << (n-1-i)));
    return sum;
}

// std::string string(int x){
//     std::string ans = "";
//     while(x){
//         ans += (x%10) + '0';
//         x/=10;
//     }
//     return ans;
// }