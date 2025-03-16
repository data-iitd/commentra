#include <stdio.h>

# Function to search for a key in the array A of size n
def search(A, n, key):
    i = 0 # Initialize index to 0
    A[n] = key # Sentinel value: place the key at the end of the array
    # Loop until the key is found in the array
    while A[i]!= key: i += 1 # Increment index until the key is found
    # Return true if the key was found before the sentinel, false otherwise
    return i!= n

n = int(input())
A = [int(x) for x in input().split()]
q = int(input())
sum = 0
for i in range(q):
    key = int(input())
    if search(A, n, key): sum += 1
print(sum)

