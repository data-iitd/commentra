
N = int(input())  # Read an integer value from the standard input and store it in N
A = [int(input()) for _ in range(N)]  # Read N integers from the standard input and store them in the list A

m = A[0]  # Initialize the variable m to the first element of the list A
M = A[0]  # Initialize the variable M to the first element of the list A
for i in range(N):  # Start a loop that iterates through the list A
    if A[i] < m:  # If the current element is less than m, update m to the current element
        m = A[i]
    if A[i] > M:  # If the current element is greater than M, update M to the current element
        M = A[i]

print(M - m)  # Print the difference between the maximum and minimum values in the list A
