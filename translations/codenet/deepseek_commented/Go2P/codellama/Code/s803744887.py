
# Initialize constants and slices
MX = 10000
sieve = [0] * MX
primes = []

# Use the Sieve of Eratosthenes to find all primes up to MX
for i in range(2, MX):
    if sieve[i] != 0:
        continue # Skip if i is not a prime
    primes.append(i) # i is a prime, add it to the primes list
    for j in range(i + i, MX, i):
        sieve[j] = i # Mark j as not prime

# Read the number of integers to process
n = int(input())
ans = 0

# Process each integer and update the answer
for i in range(n):
    x = int(input())
    ans += 1 # Assume the number is valid
    for j in range(len(primes)):
        if x > primes[j] and x % primes[j] == 0:
            ans -= 1 # The number is not valid
            break

# Output the result
print(ans)

