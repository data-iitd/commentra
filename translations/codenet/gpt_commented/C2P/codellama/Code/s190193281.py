#include<stdio.h>
#define N 1000000  # Maximum size for the array S
#define Q 50000    # Maximum size for the array T

n = 0  # Declare variables: n for the number of elements, S for the sorted array, T for the query array
S = []
T = []

# Function to perform binary search on the sorted array S
def binarySearch(key):
    left = 0
    right = n
    while left < right:
        mid = (left + right) // 2
        if S[mid] == key:
            return 1
        elif key < S[mid]:
            right = mid
        else:
            left = mid + 1
    return 0

# Read the number of elements in the sorted array S
n = int(input())

# Read the elements into the sorted array S
for i in range(n):
    S.append(int(input()))

# Read the number of queries
q = int(input())

# Process each query to check if it exists in the sorted array S
for i in range(q):
    T.append(int(input()))  # Read the query element into array T
    if binarySearch(T[i]) == 1:
        c += 1

# Output the total count of found elements
print(c)

