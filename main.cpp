#include "cache.h"

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
        else if(command == "write"){
            string address;
            int data;
            cin>>address>>data;
            c.write(address, data);
        }
    }
}

int main(){
    cout << "Choose your option:\n";
    cout << "1. Associtive" << endl
         << "2. Directive" <<endl
         << "3. n-way Associative"<<endl;
    int choice;
    cin>>choice;

    int n=2;
    if(choice == 3) {cout<<"Enter n: \n"; cin>>n;}
    int CL, B;
    cout<<"Enter no. of lines : "; cin>>CL;
    cout<<"Enter block size : "; cin>>B;
    
    if(choice == 1){cache<associative> c(CL,B,n); run(c);}// T = associative;
    else if(choice == 2) {cache<directive> c(CL,B,n); run(c);}
    else if(choice == 3) {cache<n_wayAssociative> c(CL,B,n); run(c);}
    
    return 0;
}