#include <stdio.h>
#include <stdlib.h>

# Global pointer to hold the sieve flags for prime numbers
flag = [0] * 50001

# Function to generate prime numbers up to a given number using the Sieve of Eratosthenes
def prime(num):
    i, j = 2, 2

    # Implementing the Sieve of Eratosthenes
    while i * i <= num:
        # If the number is still marked as prime
        if flag[i] == 0:
            # Mark all multiples of i as non-prime
            for j in range(2, num // i + 1):
                flag[i * j] = 1 # Marking the multiple as non-prime
        i += 1

# Main function to execute the program
def main():
    n, i, cnt = 0, 2, 0

    # Generate prime numbers up to 50000
    prime(50000)

    # Infinite loop to continuously accept user input
    while True:
        # Read an integer from the user
        n = int(input())
        # Exit the loop if the input is 0
        if n == 0:
            break
        
        i = 2 # Start checking from the smallest prime number
        cnt = 0 # Initialize count of valid pairs

        # Check pairs of primes that sum up to n
        while i * 2 <= n:
            # If both i and n-i are prime
            if flag[i] == 0 and flag[n - i] == 0:
                cnt += 1 # Increment the count of valid pairs
            i += 1 # Move to the next number
        
        # Output the count of prime pairs that sum up to n
        print(cnt)

# Call the main function
main()

