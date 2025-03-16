#include<stdio.h>
#define N 1000  # Define a constant N to represent the maximum size of the input array

def main():
    su = ['0'] * N  # Declare a character array to store the input, initialized with '0'
    susum = 0  # Initialize a variable to hold the sum of the digits
    j = 0  # Initialize a counter variable for the loop

    # Infinite loop to continuously read input until a specific condition is met
    while True:
        # Loop to read characters into the array until a newline is encountered or the limit is reached
        for j in range(N):
            su[j] = input()  # Read a character from standard input
            if su[j] == '\n': break  # Break the loop if a newline character is encountered
            susum = susum + (su[j] - '0')  # Convert the character to an integer and add it to the sum
        
        # Check if the first character is '0', which indicates the end of input
        if su[0] == '0': break  # Exit the loop if the first character is '0'
        
        print(susum)  # Print the sum of the digits read
        susum = 0  # Reset the sum for the next input

    return 0  # Return 0 to indicate successful completion of the program

