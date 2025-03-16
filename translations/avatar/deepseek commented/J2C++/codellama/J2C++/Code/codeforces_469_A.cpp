
#include <iostream> 
#include <cstdlib> 

using namespace std ; 

int main ( ) { 
    int n, levels, sum, sum2, sum3, count, level2, level3 ; 
    int [ ] arr, arr2, arr3 ; 
    
    // Read the total number of levels
    cin >> n ; 
    
    // Read the number of levels the user has completed
    cin >> levels ; 
    
    // Initialize array to store completed levels
    arr = new int [ levels ] ; 
    
    // Read the levels completed by the user
    for ( int i = 0 ; i < levels ; i ++ ) { 
        cin >> arr [ i ] ; 
    } 
    
    // Read the number of levels the second user has completed
    cin >> level2 ; 
    
    // Calculate the total number of levels
    level3 = levels + level2 ; 
    
    // Initialize array to store all levels
    arr2 = new int [ level3 ] ; 
    
    // Copy levels from arr to arr2
    for ( int i = 0 ; i < levels ; i ++ ) { 
        arr2 [ i ] = arr [ i ] ; 
    } 
    
    // Read additional levels for arr2
    for ( int i = levels ; i < level3 ; i ++ ) { 
        cin >> arr2 [ i ] ; 
    } 
    
    // Generate a sequence of numbers from 1 to n
    arr3 = new int [ n ] ; 
    int j = 0 ; 
    for ( int i = 0 ; i < n ; i ++ ) { 
        arr3 [ i ] = ++ j ; 
    } 
    
    // Check if all numbers from 1 to n are present in arr2
    for ( int i = 0 ; i < n ; i ++ ) { 
        for ( int x = 0 ; x < level3 ; x ++ ) { 
            if ( arr3 [ i ] == arr2 [ x ] ) { 
                count ++ ; 
                break ; 
            } 
        } 
    } 
    
    // Print the result based on whether all levels were completed
    if ( count == n ) { 
        cout << "I become the guy." << endl ; 
    } else { 
        cout << "Oh, my keyboard!" << endl ; 
    } 
    
    return 0 ; 
}

