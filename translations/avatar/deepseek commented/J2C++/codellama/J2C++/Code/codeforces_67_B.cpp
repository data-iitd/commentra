#include <iostream> 
#include <cstdlib> 
#include <cstdio> 
#include <cmath> 
#include <cstring> 
#include <string> 
#include <vector> 
#include <map> 
#include <list> 
#include <queue> 
#include <stack> 
#include <bitset> 
#include <deque> 
#include <set> 
#include <sstream> 

using namespace std; 

int main ( ) { 
    int n , k ; 
    cin >> n >> k ; 
    int bb [ n ] ; 
    for ( int i = 0 ; i < n ; i ++ ) 
        cin >> bb [ i ] ; 

    // Initialize an array to store the result
    int aa [ n ] ; 
    int m = 0 ; 

    // Process the array bb in reverse order
    for ( int a = n - 1 ; a >= 0 ; a -- ) { 
        int j = 0 ; 
        while ( bb [ a ] > 0 ) { 
            if ( aa [ j ] >= a + k ) 
                bb [ a ] -- ; 
            j ++ ; 
        } 
        for ( int j_ = m ++ ; j_ > j ; j_ -- ) 
            aa [ j_ ] = aa [ j_ - 1 ] ; 
        aa [ j ] = a ; 
    } 

    // Print the contents of the array aa, incrementing each element by 1
    for ( int i = 0 ; i < n ; i ++ ) 
        cout << aa [ i ] + 1 << " " ; 
    cout << endl ; 
} 

