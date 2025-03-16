# Read an integer N from the standard input
N = int(input())

# Read N integers from the standard input and store them in a list A
A = list(map(int, input().split()))

# Initialize the variable m to the first element of the list A
m = A[0]

# Initialize the variable M to the first element of the list A
M = A[0]

# Iterate through the list A to find the minimum and maximum values
for a in A:
    if a < m:
        m = a
    if a > M:
        M = a

# Print the difference between the maximum and minimum values in the list A
print(M - m)

# End-of-code comment
