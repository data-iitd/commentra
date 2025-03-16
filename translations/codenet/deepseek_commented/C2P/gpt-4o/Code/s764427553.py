# Define the maximum value for the sieve
MAX_V = 999999
# List to store prime status of numbers from 0 to MAX_V
prime = [1] * (MAX_V + 1)

# Sieve of Eratosthenes to find prime numbers
for i in range(2, int(MAX_V**0.5) + 1):
    if prime[i]:
        # If i is a prime, mark its multiples as non-prime
        for k in range(2 * i, MAX_V + 1, i):
            prime[k] = 0

# Set 0 and 1 as non-prime
prime[0] = 0
prime[1] = 0

# Counter for the number of inputs processed
count = 0

# Read integers from standard input until EOF
try:
    while True:
        n = int(input())
        count += 1
        cnt = 0
        # Count the number of primes less than or equal to n
        for i in range(n, 0, -1):
            if prime[i] == 1:
                cnt += 1
        # Print the count of primes for the current input
        print(cnt)
        # Break the loop after processing 30 inputs
        if count == 30:
            break
except EOFError:
    pass

# <END-OF-CODE>
