#include <stdio.h>  # Include the standard input-output header

def main():
	n = int(raw_input())  # Read the number of elements
	x = [int(raw_input()) for i in range(n)]  # Read the elements of array x
	q = int(raw_input())  # Read the number of queries
	y = [int(raw_input()) for i in range(q)]  # Read the elements of array y
	sum = 0  # Initialize the sum
	for i in range(q):  # For each query
		for j in range(n):  # Check each element in array x
			if y[i] == x[j]:  # If the query matches an element in x
				sum = sum + 1  # Increment the sum
				break  # Break out of the inner loop
	print sum  # Print the sum of matches

if __name__ == "__main__":
	main()

