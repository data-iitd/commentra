#include<stdio.h>
#define N 1000  # Define a constant N with the value 1000

def main():
    su = [0] * N  # Declare a character array 'su' of size N
    susum = 0  # Initialize an integer variable 'susum' to zero
    j = 0  # Initialize an integer variable 'j' to zero

    while True:  # Start an infinite loop
        for j in range(N):  # Iterate through each index of the array 'su'
            su[j] = input()  # Read a character from the standard input and store it in the array 'su' at the current index
            if su[j] == '\n':  # If the character read is a newline character, break out of the loop
                break
            susum = susum + (ord(su[j]) - ord('0'))  # Add the ASCII value of the character (after subtracting '0') to the variable 'susum'
        if su[0] == '0':  # If the first character of the array 'su' is '0', break out of the loop
            break
        print(susum)  # Print the sum of the digits read from the standard input
        susum = 0  # Reset the variable 'susum' to zero for the next iteration

    return 0  # Indicate successful termination of the program

