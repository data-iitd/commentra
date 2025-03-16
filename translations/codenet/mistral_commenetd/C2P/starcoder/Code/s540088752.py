#include <stdio.h>

def main():
    # Declare and initialize variables
    N = 0
    A = []
    B = []
    i = 0
    ans = 0

    # Read the elements of array A from the standard input
    for i in range(N + 1):
        A.append(int(input()))

    # Read the elements of array B from the standard input
    for i in range(N):
        B.append(int(input()))

    # Nested for loop to compare each pair of elements from arrays A and B
    for i in range(N):
        #site i
        if A[i] >= B[i]:
            ans = ans + B[i] # Add the smaller element to the answer
            A[i] = A[i] - B[i] # Subtract the smaller element from the corresponding element in array A
            B[i] = 0 # Set the smaller element in array B to 0
        else:
            ans = ans + A[i] # Add the smaller element to the answer
            B[i] = B[i] - A[i] # Subtract the smaller element from the corresponding element in array B
            A[i] = 0 # Set the smaller element in array A to 0

        #site i + 1
        if A[i + 1] >= B[i]:
            ans = ans + B[i] # Add the smaller element to the answer
            A[i + 1] = A[i + 1] - B[i]; # Subtract the smaller element from the corresponding element in array A
            B[i] = 0 # Set the smaller element in array B to 0
        else:
            ans = ans + A[i + 1] # Add the smaller element to the answer
            B[i] = B[i] - A[i + 1] # Subtract the smaller element from the corresponding element in array B
            A[i + 1] = 0 # Set the smaller element in array A to 0

    # Print the final answer
    print(ans) # Print the value of the answer variable

    # Return 0 to indicate the successful execution of the program
    return 0 # Return 0 to the operating system

if __name__ == "__main__":
    main()

