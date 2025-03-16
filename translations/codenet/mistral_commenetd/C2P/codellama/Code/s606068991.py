
#include<stdio.h>

# Function to print the first n-1 elements of an array
def white(n,A):
	i = 0
	# Loop to print the first n-1 elements of the array
	while i < n-1:
		print(A[i],end=" ")
		i += 1
	# Print the last element of the array
	print(A[i])

# Function to implement insertion sort algorithm
def insertionsort(n,A):
	i = 0
	j = 0
	a = 0
	# Loop to sort the array using insertion sort algorithm
	while i < n:
		# Inner loop to find the position of the current element in sorted array
		while j < i:
			# Swap if current element is smaller than the previous one
			if A[i] < A[j]:
				# Swap the elements
				a = A[i]
				A[i] = A[j]
				A[j] = a
			j += 1
		# Call the white function to print the sorted array after each iteration
		white(n,A)
		i += 1

# Main function to take input and call the insertion sort function
def main():
	i = 0
	n = 0
	A = []
	# Take the size of the array as input
	n = int(input())
	# Take the elements of the array as input
	for i in range(n):
		A.append(int(input()))
	# Call the insertion sort function to sort the array
	insertionsort(n,A)

	# Return 0 to indicate successful execution of the program
	return 0

