
#include <iostream>
#include <string>

using namespace std;

// This method generates a string of numbers from 1 to 1000
string generateString ( ) { 
    string s = "" ; 
    for ( int i = 1 ; i <= 1000 ; i ++ ) { 
        s += to_string ( i ) ; 
    } 
    return s ; 
} 

// The main method reads an integer n from the user, and prints the nth character of the generated string
int main ( ) { 
    int n ; 
    cin >> n ; 
    cout << generateString ( ) [ n - 1 ] << endl ; 
    return 0 ; 
} 

