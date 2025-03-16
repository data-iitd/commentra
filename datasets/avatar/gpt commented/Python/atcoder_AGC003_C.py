# Read an integer N from user input
N = int(input())

# Create a list A where each element is calculated as (input value * N + index)
# This combines user input with the index to create a unique value for each position
A = [int(input()) * N + i for i in range(N)]

# Sort the list A in ascending order
A.sort()

# Initialize a counter to keep track of mismatches
cnt = 0

# Iterate through each element in the sorted list A
for i in range(N):
    # Calculate the value of d as the remainder of A[i] divided by N, then take that remainder modulo 2
    d = (A[i] % N) % 2
    
    # Check if the parity of d does not match the parity of the current index i
    if d % 2 != i % 2:
        # If they don't match, increment the counter
        cnt += 1

# Print half of the count of mismatches, as each mismatch can be paired
print(cnt // 2)
