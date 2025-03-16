#include<stdio.h>

def main():
    # Declare arrays to hold input values and intermediate calculations
    a = [0, 0, 0]
    b = [0, 0, 0]
    c = [[0, 0, 0], [0, 0, 0], [0, 0, 0]] # 2D array to store the input matrix
    i = 0
    j = 0

    # Read a 3x3 matrix from user input
    for i in range(3):
        c[i] = [int(x) for x in input().split()]

    # Initialize the first element of array 'a' to 0
    a[0] = 0

    # Copy the first row of the matrix 'c' into array 'b'
    for i in range(3):
        b[i] = c[0][i]

    # Calculate the remaining elements of array 'a' based on the first column of matrix 'c'
    for i in range(1, 3):
        a[i] = c[i][0] - b[0]

    # Verify if the matrix 'c' can be represented as the sum of arrays 'a' and 'b'
    for i in range(3):
        for j in range(3):
            # Check if the current element of 'c' equals the sum of corresponding elements from 'a' and 'b'
            if(c[i][j]!= a[i] + b[j]):
                print("No") # Output "No" if the condition fails
                return 0   # Exit the program
            else:
                print("Yes") # Output "Yes" if the condition passes
                return 0   # Exit the program

if __name__ == "__main__":
    main()

