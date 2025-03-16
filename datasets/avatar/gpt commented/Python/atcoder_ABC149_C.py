# Read an integer input from the user
X = int(input())

# Initialize a list to track prime numbers up to 100010
# Start by assuming all numbers are prime (True)
prime = [True] * (100010)

# Set 0 and 1 as non-prime (False)
prime[0] = False
prime[1] = False

# Eliminate all even numbers greater than 2 from the list of primes
for i in range(4, 100010, 2):
    prime[i] = False

# Start checking for prime numbers from 3 onwards
i = 3
# Use the Sieve of Eratosthenes method to find all primes up to 100008
while (i * i <= 100008):
    # If 'i' is still marked as prime
    if prime[i]:
        # Mark all multiples of 'i' as non-prime
        for j in range(i + i, 100008, i):
            prime[j] = False
    # Move to the next odd number
    i += 2

# Find and print the first prime number greater than or equal to X
for i in range(X, 100008):
    if prime[i]:
        print(i)  # Print the prime number found
        break  # Exit the loop after finding the first prime
