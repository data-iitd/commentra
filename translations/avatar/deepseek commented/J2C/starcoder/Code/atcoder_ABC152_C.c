
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <ctype.h>
#include <time.h>
#include <float.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <ctype.h>
#include <time.h>
#include <float.h>
#include <limits.h>

int solve ( ) { 
    // Create a Scanner object to read input from the standard input stream
    Scanner sc = new Scanner ( System.in ) ; 
        
    // Read the integer N from the input
    int N = sc.nextInt ( ) ; 
        
    // Initialize an array of size N to store the integers
    int [ ] arr = new int [ N ] ; 
        
    // Read N integers from the input and store them in the array
    for ( int i = 0 ; i < N ; i ++ ) { 
        arr [ i ] = sc.nextInt ( ) ; 
    } 
        
    // Initialize a sum variable to 0
    int sum = 0 ; 
        
    // Create a priority queue to store the integers in ascending order
    Queue < Integer > q = new PriorityQueue < > ( ) ; 
        
    // Iterate through the array and add each element to the priority queue
    for ( int i = 0 ; i < arr.length ; i ++ ) { 
        q.add ( arr [ i ] ) ; 
            
        // Check if the current element is less than or equal to the smallest element in the priority queue
        if ( arr [ i ] <= q.peek ( ) ) { 
            sum ++ ; 
        } 
    } 
        
    // Return the sum
    return sum ; 
} 

// 