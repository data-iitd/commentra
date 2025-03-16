
#include<stdio.h> // This line is an include guard for standard C libraries
#include<stdlib.h> // Standard library for dynamic memory allocation and other functions
#include<string.h> // String manipulation library

/*
#include<gmp.h> // This line is an include guard for GNU Multiple Precision Arithmetic Library
#include<gmpxx.h> // GNU Multiple Precision Arithmetic Library for C++
*/
// Uncomment this block if you want to use GNU Multiple Precision Arithmetic Library for large numbers

// Define the maximum length of a string
#define MAX_LENGTH 1000

// Define the maximum number of strings
#define MAX_N 100000

// Define the maximum length of a string
#define MAX_LENGTH 1000

// Define the maximum number of strings
#define MAX_N 100000

int main(){

    // Declare and initialize an array 'v' of strings with a maximum length of MAX_LENGTH and a maximum number of strings of MAX_N
    char v[MAX_N][MAX_LENGTH];

    // Read the number of strings 'N' and their lengths 'L' from the standard input
    int N,L;
    scanf("%d %d",&N,&L);

    // Iterate through the strings and read each string into the array 'v'
    for(int i=0;i<N;i++){
        // Read a string's' from the standard input and store it in the array 'v'
        scanf("%s",v[i]);
    }

    // Sort the strings in the array 'v' in ascending order using the 'qsort' function
    qsort(v,N,sizeof(v[0]),strcmp);

    // Iterate through the sorted strings in the array 'v' and print each string to the standard output
    for(int i=0;i<N;i++){
        // Print the current string from the array 'v' to the standard output
        printf("%s",v[i]);
    }

    // Print a newline character at the end of the output
    printf("\n");

    // Return 0 to indicate successful execution
    return 0;
}

