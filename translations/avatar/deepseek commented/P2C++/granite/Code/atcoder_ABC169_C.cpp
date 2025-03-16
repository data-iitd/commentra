

#include <bits/stdc++.h>

using namespace std;

int main ( ) {
    ios_base::sync_with_stdio ( false );
    cin.tie ( NULL );
    
    // Debugging function to print debug information if _DEBUG is defined
    #ifdef _DEBUG
    auto __debug__ = [] ( auto... x ) { cerr << "\033[33;1m" << __func__ << " : " << x << "\033[0m\n" ; } ;
    #else
    auto __debug__ = [] ( auto... x ) {  } ;
    #endif
    
    // Function to read input from stdin without trailing whitespace
    auto input = [] ( ) { string _input ; getline ( cin, _input ) ; return _input ; } ;
    
    // Helper function to read a list of integers
    auto LMIIS = [] ( ) { vector < int > _v ; cin >> _v ; return _v ; } ;
    
    // Helper function to read a single integer
    auto II = [] ( ) { int _i ; cin >> _i ; return _i ; } ;
    
    // Constant for modulo operation
    const int P = 100000007 ;
    
    // Constant for infinity
    const int INF = 100000000 ;
    
    // Read two inputs, convert one to integer and the other to scaled integer
    auto sa = input ( ) ;
    auto sb = input ( ) ;
    auto a = stoi ( sa ) ;
    auto b = stoi ( sb ) * 100 + 0.1 ;
    
    // Perform the calculation and print the result
    cout << a * b / 100 << endl ;
    
    return 0 ;
}

