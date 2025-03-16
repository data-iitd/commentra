#include<iostream>
using namespace std;

int main(){
    int a, b;
    
    cin >> a;
    
    print(a/(60*60),":",a%(60*60)/60,":",a%(60*60)%60)
    
    return 0;
}

