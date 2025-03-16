#include<stdio.h>  # Include the standard input/output library

# Define a function to compare two integers
def compare(a, b):
    return (b - a)  # Return the difference between the two integers

def main():  # Define the main function
    array = [0] * 10  # Declare an array of 10 integers
    for i in range(10):  # Read 10 integers from the input
        array[i] = int(input())
    array.sort(key=compare)  # Sort the array using the qsort function and the compare function
    for i in range(3):  # Print the first three elements of the sorted array
        print(array[i])

if __name__ == "__main__":  # Execute the main function
    main()

