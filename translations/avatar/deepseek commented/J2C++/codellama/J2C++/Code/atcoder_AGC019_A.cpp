
#include <iostream>
#include <cmath>

using namespace std ; 

int main ( ) { 
    long Q , H , S , D , N ; 
    
    // Reading input values
    cin >> Q >> H >> S >> D >> N ; 
    
    // Calculating the minimum price for one unit
    long onePrice = min ( min ( Q * 4 , H * 2 ) , S ) ; 
    
    // Conditional logic to determine the total cost
    if ( ( double ) onePrice <= ( double ) D / 2 ) { 
        cout << N * onePrice << endl ; 
    } else { 
        cout << ( N / 2 ) * D + ( N % 2 ) * onePrice << endl ; 
    } 
    
    return 0 ; 
}

