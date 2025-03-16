#include<stdio.h>
#define N 1000000  # Maximum size for the array S
#define Q 50000    # Maximum size for the array T

n = int(input())  # Read the number of elements in the sorted array S
S = [int(input()) for i in range(n)]  # Read the elements into the sorted array S
q = int(input())  # Read the number of queries
T = [int(input()) for i in range(q)]  # Read the queries into the array T
c = 0  # Initialize the count of found elements

for i in range(q):  # Process each query to check if it exists in the sorted array S
  if T[i] in S:  # If the element is found, increment the count
    c += 1

print(c)  # Output the total count of found elements

