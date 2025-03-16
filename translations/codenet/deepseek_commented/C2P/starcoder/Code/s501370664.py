#include <stdio.h>  # Include standard input/output library for printf and scanf
#include <stdlib.h> # Include standard library for memory allocation (calloc)

flag = None # Declare a global integer array to keep track of prime numbers

# Function to mark non-prime numbers up to a given number 'num'
def prime(num):
	i = 2
	while i*i <= num:
		if flag[i] == 0:
			j = 2
			while i*j <= num:
				flag[i*j] = 1
				j += 1
		i += 1

# Main function to read an integer, calculate pairs of primes summing to 'n', and print the result
def main():
	n = 0
	while n!= 0:
		scanf("%d",&n) # Read an integer 'n' from the user
		if n == 0:
			break
		flag = (int *)calloc(sizeof(int),n+1) # Allocate memory for the flag array
		prime(n) # Call the prime function to mark non-prime numbers up to 'n'
		i = 2
		cnt = 0
		while i*2 <= n:
			if not flag[i] and not flag[n-i]:
				cnt += 1
			i += 1
		printf("%d\n",cnt) # Print the count of pairs of primes summing to 'n'

main() # Execute the main function

