
#include <bits/stdc++.h>
using namespace std;

int solve ( ) { 
    // Create a Scanner object to read input from the standard input stream
    Scanner sc ; 
    sc.open ( "input.txt" ) ; 
    
    // Read the integer N from the input
    int N = sc.nextInt ( ) ; 
    
    // Initialize an array of size N to store the integers
    int arr [ N ] ; 
    
    // Read N integers from the input and store them in the array
    for ( int i = 0 ; i < N ; i ++ ) { 
        arr [ i ] = sc.nextInt ( ) ; 
    } 
    
    // Initialize a sum variable to 0
    int sum = 0 ; 
    
    // Create a priority queue to store the integers in ascending order
    priority_queue < int > q ; 
    
    // Iterate through the array and add each element to the priority queue
    for ( int i = 0 ; i < arr.length ; i ++ ) { 
        q.push ( arr [ i ] ) ; 
        
        // Check if the current element is less than or equal to the smallest element in the priority queue
        if ( arr [ i ] <= q.top ( ) ) { 
            sum ++ ; 
        } 
    } 
    
    // Return the sum
    return sum ; 
}

