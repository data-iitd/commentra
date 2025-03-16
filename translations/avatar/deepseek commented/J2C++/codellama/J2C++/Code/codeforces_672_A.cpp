
#include <iostream> 
#include <string> 

using namespace std ; 

// This function generates a string of numbers from 1 to 1000
string generateString ( ) { 
    string str = "" ; 
    for ( int i = 1 ; i <= 1000 ; i ++ ) { 
        str += to_string ( i ) ; 
    } 
    return str ; 
} 

// The main function reads an integer n from the user, and prints the nth character of the generated string
int main ( ) { 
    int n ; 
    cin >> n ; 
    cout << generateString ( ) [ n - 1 ] << endl ; 
    return 0 ; 
} 

