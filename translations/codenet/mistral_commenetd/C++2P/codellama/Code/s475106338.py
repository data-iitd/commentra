#include <iostream> // Include the iostream library for input/output operations
using namespace std; // Use the standard namespace for easier access to iostream functions

int main(void){ // The main function is the entry point of the program
    int i, t, n; // Declare three integer variables: i for the loop counter, t for the user input, and n for the number of items

    # This is a comment
    for i in range(4): # The for loop runs 4 times, each time reading user input and processing it accordingly
        t, n = map(int, input().split()) # Read two integers from the user: t and n

        # Check the value of t and process the input accordingly
        if t == 1:
            print(6000*n) # If t is 1, print the result of multiplying n by 6000 and ending the line
        elif t == 2:
            print(4000*n) # If t is 2, print the result of multiplying n by 4000 and ending the line
        elif t == 3:
            print(3000*n) # If t is 3, print the result of multiplying n by 3000 and ending the line
        elif t == 4:
            print(2000*n) # If t is 4, print the result of multiplying n by 2000 and ending the line

# 