#include<stdio.h>  # Include the standard input/output library

# Define a function to compare two integers
def compare(a, b):
    return (b - a)  # Return the difference between the two integers

def main(void):  # Define the main function
    array = [0] * 10  # Declare an array of 10 integers and a loop variable
    for i in range(10):  # Read 10 integers from the input
        array[i] = int(input())
    array.sort(compare)  # Sort the array using the sort function and the compare function
    for i in range(3):  # Print the first three elements of the sorted array
        print(array[i])
    return 0  # Return 0 to indicate successful execution

