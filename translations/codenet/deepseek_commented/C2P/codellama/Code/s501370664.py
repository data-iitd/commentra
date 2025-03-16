#include <stdio.h>  # Include standard input/output library for printf and scanf
#include <stdlib.h> # Include standard library for memory allocation (calloc)

flag = []        # Declare a global integer array to keep track of prime numbers

# Function to mark non-prime numbers up to a given number 'num'
def prime(num):
	i,j = 2,2  # Declare loop variables

	flag = [0] * (num+1) # Allocate memory for the flag array

	while i*i <= num: # Iterate to mark non-prime numbers
		if flag[i] == 0: # If 'i' is a prime number
			for j in range(2,num+1): # Mark multiples of 'i' as non-prime
				flag[i*j] = 1
		i += 1

# Main function to read an integer, calculate pairs of primes summing to 'n', and print the result
def main():
	n,i,cnt = 0,2,0 # Declare variables to store input, loop index, and count of pairs

	prime(50000) # Call the prime function to mark non-prime numbers up to 50000

	while 1: # Infinite loop to read input until 'n' is zero
		n = int(input()) # Read an integer 'n' from the user
		if n == 0:
			break # Exit the loop if 'n' is zero
		i = 2 # Initialize the starting prime number
		cnt = 0 # Initialize the count of pairs
		while i*2 <= n: # Loop to find pairs of primes summing to 'n'
			if flag[i] == 0 and flag[n-i] == 0: # Check if both 'i' and 'n-i' are prime
				cnt += 1 # Increment the count if a valid pair is found
			i += 1
		print(cnt) # Print the count of pairs of primes summing to 'n'

if __name__ == "__main__":
	main()

