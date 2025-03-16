# Read the number of elements from user input
N = int(input())

# Read N elements into the list A
A = list(map(int, input().split()))

# Initialize m and M to the first element of the list A
m = A[0]
M = A[0]

# Iterate through the list to find the minimum and maximum values
for i in range(N):
    # Update m if the current element is less than the current minimum
    if A[i] < m:
        m = A[i]
    
    # Update M if the current element is greater than the current maximum
    if A[i] > M:
        M = A[i]

# Output the difference between the maximum and minimum values
print(M - m)

# <END-OF-CODE>
