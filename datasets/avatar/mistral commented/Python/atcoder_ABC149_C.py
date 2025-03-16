# Initialize an array 'prime' of boolean values with all elements as True
# The array 'prime' will be used to store whether a number is prime or not
# The size of the array is 100010
X = int(input())
prime = [True] * (100010)

# Set the first two elements of the array as False, as 0 and 1 are not prime numbers
prime[0] = False
prime[1] = False

# Sieve of Eratosthenes algorithm to find prime numbers up to 100008
for i in range(4, 100010, 2):
    # If the number 'i' is prime
    if prime[i]:
        # Mark all multiples of 'i' as composite (non-prime)
        for j in range(i + i, 100008, i):
            prime[j] = False

# Find the prime number 'X' and print it
i = X
while i <= 100008:
    # If the number 'i' is prime
    if prime[i]:
        print(i)
        # Exit the loop as we have found the prime number 'X'
        break
