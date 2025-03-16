
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

int main ( ) { 
    // Create a Scanner object to read input from the standard input stream
    Scanner sc = new Scanner ( System.in ) ; 

    // Read the number of switches (N) and the number of lights (M)
    int N = sc.nextInt ( ) ; 
    int M = sc.nextInt ( ) ; 

    // Initialize an ArrayList of integers with N elements, all set to 0
    ArrayList < Integer > a = new ArrayList < > ( ) ; 
    for ( int i = 0 ; i < N ; i ++ ) { 
        a.add ( 0 ) ; 
    } 

    // Read M groups of integers, where each group represents a switch and its corresponding states
    for ( int i = 0 ; i < M ; i ++ ) { 
        int k = sc.nextInt ( ) ; 
        for ( int j = 0 ; j < k ; j ++ ) { 
            int s = sc.nextInt ( ) ; 
            s -- ; 
            a.set ( s , a.get ( s ) | ( 1 << i ) ) ; 
        } 
    } 

    // Read the final state of each light
    int p = 0 ; 
    for ( int i = 0 ; i < M ; i ++ ) { 
        int x = sc.nextInt ( ) ; 
        p |= ( x << i ) ; 
    } 

    // Calculate the number of possible configurations of switch states that match the final state of the lights
    int ans = 0 ; 
    for ( int s = 0 ; s < ( 1 << N ) ; s ++ ) { 
        int t = 0 ; 
        for ( int i = 0 ; i < N ; i ++ ) { 
            if ( ( ( s >> i ) & 1 ) == 1 ) { 
                t ^= a.get ( i ) ; 
            } 
        } 
        if ( p == t ) { 
            ans ++ ; 
        } 
    } 

    // Print the result
    printf ( "%d\n" , ans ) ; 

    // Close the Scanner object
    sc.close ( ) ; 

    return 0 ; 
} 

