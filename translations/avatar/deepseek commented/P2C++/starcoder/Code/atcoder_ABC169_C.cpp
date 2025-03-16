
#include <bits/stdc++.h>

using namespace std;

int main ( ) {
    ios_base :: sync_with_stdio ( false );
    cin.tie ( 0 );
    cout.tie ( 0 );
    
    // Read two inputs, convert one to integer and the other to scaled integer
    string sa, sb;
    cin >> sa >> sb;
    int a = stoi ( sa );
    int b = stoi ( sb ) * 100 + 0.1;
    
    // Perform the calculation and print the result
    cout << a * b / 100 << "\n";
    
    return 0;
}

