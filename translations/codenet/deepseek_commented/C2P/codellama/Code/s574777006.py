#include <stdio.h>  # Include the standard input-output header

int main():
	
	int n, i, j, q, x[10000], y[500], sum = 0  # Declare variables
	
	scanf("%d", &n)  # Read the number of elements
	
	for i in range(n):
		scanf("%d", &x[i])  # Read the elements of array x
	
	scanf("%d", &q)  # Read the number of queries
	
	for i in range(q):
		scanf("%d", &y[i])  # Read the elements of array y
	
	for i in range(q):  # For each query
		for j in range(n):  # Check each element in array x
			if y[i] == x[j]:  # If the query matches an element in x
				sum = sum + 1  # Increment the sum
				break  # Break out of the inner loop
	
	printf("%d\n", sum)  # Print the sum of matches
	
	return 0  # Return 0 to indicate successful execution

