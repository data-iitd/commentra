

#include <bits/stdc++.h> 
using namespace std ; 

void cout ( string str ) { 
    cout << str << endl ; 
} 

int main ( ) { 
    ios_base::sync_with_stdio ( false ) ; 
    cin.tie ( NULL ) ; 
    
    // Reading the integer input n
    int n ; 
    cin >> n ; 
    
    // Reading the string input str
    string a = "", b = "", str ; 
    getline ( cin, str ) ; 
    
    // Constructing the string a by taking the first n/2 characters of str
    for ( int i = 0 ; i < n / 2 ; i ++ ) { 
        a = a + str [ i ] ; 
    } 
    
    // Checking if str is equal to a + a and printing the result
    if ( str == a + a ) 
        cout ( "Yes" ) ; 
    else 
        cout ( "No" ) ; 
    
    return 0 ; 
} ;
