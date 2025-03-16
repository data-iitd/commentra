MAX_V = 999999

# Initialize the prime array; assume all numbers are prime initially
prime = [True] * (MAX_V + 1)

# Implement the Sieve of Eratosthenes algorithm to find all primes up to MAX_V
for i in range(2, int(MAX_V**0.5) + 1):
    if prime[i]:  # If i is still marked as prime
        # Mark all multiples of i as non-prime
        for k in range(2 * i, MAX_V + 1, i):
            prime[k] = False  # False indicates that the number is not prime

# Explicitly mark 0 and 1 as non-prime
prime[0] = False
prime[1] = False

# Variable to count the number of inputs processed
count = 0

# Read integers from standard input until EOF
while True:
    try:
        n = int(input())
        count += 1  # Increment the count of numbers processed
        cnt = 0  # Counter for the number of primes less than or equal to n

        # Count how many primes are less than or equal to n
        for i in range(n, 0, -1):
            if prime[i]:  # Check if the number is prime
                cnt += 1  # Increment the prime count

        # Output the count of primes found
        print(cnt)

        # Stop processing after 30 numbers
        if count == 30:
            break
    except EOFError:
        break
