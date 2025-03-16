
# Python code to find the number of primes less than or equal to a given number

# Define a constant for the maximum value to check for primes
MAX_V = 999999

# Array to hold the prime status of numbers from 0 to MAX_V
prime = [1] * (MAX_V + 1)
prime[0] = 0
prime[1] = 0

# Implement the Sieve of Eratosthenes algorithm to find all primes up to MAX_V
for i in range(2, int(MAX_V**0.5) + 1):
    if prime[i]:
        for k in range(2 * i, MAX_V + 1, i):
            prime[k] = 0

# Read integers from standard input until EOF
count = 0
while True:
    try:
        n = int(input())
        count += 1
        cnt = 0

        # Count how many primes are less than or equal to n
        for i in range(n, 0, -1):
            if prime[i]:
                cnt += 1

        # Output the count of primes found
        print(cnt)

        # Stop processing after 30 numbers
        if count == 30:
            break
    except EOFError:
        break

