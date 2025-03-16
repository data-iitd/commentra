
# Read the number of elements from user input
N = int(input())

# Read N elements into the list A
A = [int(input()) for _ in range(N)]

# Initialize m and M to the first element of the list A
m = A[0]
M = A[0]

# Iterate through the list to find the minimum and maximum values
for a in A:
    # Update m if the current element is less than the current minimum
    if a < m: m = a
    
    # Update M if the current element is greater than the current maximum
    if a > M: M = a

# Output the difference between the maximum and minimum values
print(M - m)

