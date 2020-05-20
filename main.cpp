#include "cache.h"
// #include "n_wayAssociativeCache.h"

using namespace std;
template<type T>
void run(cache<T>& c){
    string command = "";
    while(command!="exit"){
        cin>>command;
        if(command == "read"){
            string address;
            cin>>address;
            cout<<c.read(address)<<endl;
        }
        else if(command=="write"){

            string address;
            int data;
            cin>>address>>data;
            c.write(address, data);
        }
    }
}

int main(){
    // cache<n_wayAssociative> c(128, 64, 4);
    // c.write("11101110000010001011001000100001", 201);
    // c.write("11101110011010001011001000111101", 203);
    // // cout<<'h'<<endl;
    // c.write("11101110011010001011001000111001", 202);
    // c.write("11101110011010001011001000111111", 204);
    // cout<<c.read("11101110000010001011001000100001");
    // cout<<endl;
    // cout<<c.read("11101110011010001011001000111101");
    // cout<<c.read("11101110011010001011001000111001");
    // cout<<endl;
    
    cout << "Choose your option:\n";
    cout<<"1. Associtive" << endl
        <<"2. Directive" <<endl
        <<"3. n-way Associative"<<endl;
    int choice;
    cin>>choice;

    int n=2;
    if(choice == 3) {cout<<"Enter n: \n"; cin>>n;}
    int CL, B;
    cout<<"Enter no. of lines : "; cin>>CL;
    cout<<"Enter block size : "; cin>>B;
    // cache<directive> c(CL, B, n);
    
    if(choice == 1){cache<associative> c(CL,B,n); run(c);}// T = associative;
    else if(choice == 2) {cache<directive> c(CL,B,n); run(c);}
    else if(choice == 3) {cache<n_wayAssociative> c(CL,B,n); run(c);}
    
    return 0;
}