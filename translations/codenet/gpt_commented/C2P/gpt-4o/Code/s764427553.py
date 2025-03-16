# Define a constant for the maximum value to check for primes
MAX_V = 999999

# Array to hold the prime status of numbers from 0 to MAX_V
prime = [1] * (MAX_V + 1)  # 1 indicates that the number is prime

# Implement the Sieve of Eratosthenes algorithm to find all primes up to MAX_V
for i in range(2, int(MAX_V**0.5) + 1):
    if prime[i]:  # If i is still marked as prime
        # Mark all multiples of i as non-prime
        for k in range(2 * i, MAX_V + 1, i):
            prime[k] = 0  # 0 indicates that the number is not prime

# Explicitly mark 0 and 1 as non-prime
prime[0] = 0
prime[1] = 0

# Variable to count the number of inputs processed
count = 0

# Read integers from standard input until EOF
try:
    while True:
        n = int(input())  # Read an integer from standard input
        count += 1  # Increment the count of numbers processed
        cnt = 0  # Counter for the number of primes less than or equal to n

        # Count how many primes are less than or equal to n
        for i in range(n, 0, -1):
            if prime[i] == 1:  # Check if the number is prime
                cnt += 1  # Increment the prime count

        # Output the count of primes found
        print(cnt)

        # Stop processing after 30 numbers
        if count == 30:
            break
except EOFError:
    pass  # End of input

# Indicate successful completion of the program
# <END-OF-CODE>
