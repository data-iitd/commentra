import sys

# Reading the number of elements N from user input
N = int(input())

# Initializing an array A of size N to store the input integers
A = []

# Loop to read N integers from user input and store them in array A
for i in range(N):
    A.append(int(input()))

# Initializing a counter to keep track of the number of segments
count = 0

# Loop through the array to identify segments of increasing or decreasing values
for i in range(N):
    # If we are at the last element, increment the count
    if i == N - 1:
        count += 1
    # If the current element is equal to the next element, do nothing
    elif A[i] == A[i + 1]:
        # No action needed, just continue
    # If the current element is less than the next element, find the end of the increasing segment
    elif A[i] < A[i + 1]:
        while A[i] <= A[i + 1]:
            i += 1 # Move to the next element
            # Break if we reach the end of the array
            if i == N - 1: break
        # Increment the count for the found segment
        count += 1
    # If the current element is greater than the next element, find the end of the decreasing segment
    else:
        while A[i] >= A[i + 1]:
            i += 1 # Move to the next element
            # Break if we reach the end of the array
            if i == N - 1: break
        # Increment the count for the found segment
        count += 1

# Output the total number of segments found
print(count)

# 