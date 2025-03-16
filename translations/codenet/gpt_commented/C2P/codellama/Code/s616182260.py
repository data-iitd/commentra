#include<stdio.h>

int main() {
    # Declare arrays to hold input values and intermediate calculations
    a = [0]
    b = []
    c = []
    i = 0
    j = 0

    # Read a 3x3 matrix from user input
    for i in range(3):
        c.append(list(map(int, input().split())))

    # Copy the first row of the matrix 'c' into array 'b'
    for i in range(3):
        b.append(c[0][i])

    # Calculate the remaining elements of array 'a' based on the first column of matrix 'c'
    for i in range(1, 3):
        a.append(c[i][0] - b[0])

    # Verify if the matrix 'c' can be represented as the sum of arrays 'a' and 'b'
    for i in range(3):
        for j in range(3):
            # Check if the current element of 'c' equals the sum of corresponding elements from 'a' and 'b'
            if c[i][j] != a[i] + b[j]:
                print("No") # Output "No" if the condition fails
                return 0   # Exit the program

    # If all checks pass, output "Yes"
    print("Yes")
    return 0 # Exit the program successfully
}

