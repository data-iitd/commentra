#include<stdio.h>

# Function to compare two integers for sorting
def compare(a, b):
    # Return the difference between b and a for descending order
    return (b - a)

# Main function
def main():
    # Declare an array of integers and a variable for iteration
    array = [0] * 10
    i = 0

    # Read 10 integers from standard input into the array
    for i in range(10):
        array[i] = int(input())

    # Sort the array in descending order using qsort and the compare function
    array.sort(reverse=True)

    # Print the first 3 elements of the sorted array
    for i in range(3):
        print(array[i])

# Return 0 to indicate successful completion of the program
if __name__ == "__main__":
    main()

