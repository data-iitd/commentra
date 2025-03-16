# Import the sys module for input operations
import sys

# Read an integer value from the standard input
N = int(sys.stdin.readline().strip())  # Read the first line and convert it to an integer
A = list(map(int, sys.stdin.readline().strip().split()))  # Read the next line, split it into integers, and store in list A

m = A[0]  # Initialize the variable m to the first element of the list A
M = A[0]  # Initialize the variable M to the first element of the list A

for i in range(N):  # Start a loop that iterates through the list A
    if A[i] < m:
        m = A[i]  # If the current element is less than m, update m to the current element
    if A[i] > M:
        M = A[i]  # If the current element is greater than M, update M to the current element

print(M - m)  # Print the difference between the maximum and minimum values in the list A

# <END-OF-CODE>
