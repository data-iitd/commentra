
#include <iostream> 
#include <string> 
#include <sstream> 
#include <map> 

using namespace std ; 

int main ( ) { 
    // Step 1: Read the input value `n` which represents the number of elements.
    int n ; 
    cin >> n ; 
    
    // Step 2: Read the values of `v` (values) and store them in a list `vList`.
    string vStr ; 
    cin >> vStr ; 
    map < int , int > vList ; 
    int key = 0 ; 
    stringstream vStream ( vStr ) ; 
    string vVal ; 
    while ( getline ( vStream , vVal , ' ' ) ) { 
        vList [ key ] = stoi ( vVal ) ; 
        key ++ ; 
    } 
    
    // Step 3: Read the values of `c` (costs) and store them in a list `cList`.
    string cStr ; 
    cin >> cStr ; 
    map < int , int > cList ; 
    key = 0 ; 
    stringstream cStream ( cStr ) ; 
    string cVal ; 
    while ( getline ( cStream , cVal , ' ' ) ) { 
        cList [ key ] = stoi ( cVal ) ; 
        key ++ ; 
    } 
    
    // Step 4: Initialize a variable `max` to keep track of the maximum profit.
    int max = 0 ; 
    
    // Step 5: Iterate through the elements, calculate the profit for each element, and update `max` if the profit is positive.
    for ( int i = 0 ; i < n ; i ++ ) { 
        int profit = vList [ i ] - cList [ i ] ; 
        if ( profit > 0 ) { 
            max += profit ; 
        } 
    } 
    
    // Step 6: Print the maximum profit.
    cout << max << endl ; 
    
    return 0 ; 
} 

