#include<iostream>  # Include the iostream library for input and output operations
#include<stdio.h>   # Include the standard I/O library for printf and scanf functions
#include<algorithm> # Include the algorithm library for sorting the array
using namespace std; # Use the standard namespace for easier access to functions and variables

def main(): # The main function is the entry point of the program
    s = [0] * 11 # Declare an integer array 's' of size 11
    i = 0 # Declare an integer variable 'i' for loop counter

    # Read 10 integers from the user and store them in the array 's'
    for i in range(10):
        s[i] = int(input()) # Read an integer from the standard input and store it in the array 's' at the current index

    # Sort the array 's' in ascending order using the sort function from the algorithm library
    s.sort()

    # Print the 4th, 5th and 6th smallest elements from the sorted array 's'
    for i in range(9, 6, -1): # Initialize the loop counter 'i' to 9 (index of the 5th smallest element) and decrement it until it becomes greater than the index of the 6th smallest element
        print(s[i]) # Print the current element of the array 's' to the standard output

    return 0 # Indicate that the program has executed successfully and terminate

