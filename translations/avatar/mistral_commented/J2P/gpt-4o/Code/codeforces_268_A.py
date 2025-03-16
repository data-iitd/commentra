# Importing the necessary module for reading input
import sys

def main():
    n = int(sys.stdin.readline().strip())  # Reading the first line of the input containing the number of integers n

    result = 0  # Initializing the variable result to zero

    h = list(map(int, sys.stdin.readline().strip().split()))  # Reading the first array h
    g = list(map(int, sys.stdin.readline().strip().split()))  # Reading the second array g

    for i in range(n):  # Iterating through each index i from 0 to n-1 in the first for loop
        for j in range(n):  # Nested for loop iterating through each index j from 0 to n-1
            if h[i] == g[j]:  # Checking if the current element of array h is equal to the current element of array g
                result += 1  # Incrementing the result variable if the condition is true

    print(result)  # Printing the final result to the standard output stream

if __name__ == "__main__":
    main()

# <END-OF-CODE>
