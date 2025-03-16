def sieve_of_eratosthenes(mx):
    sieve = [0] * mx
    primes = []
    for i in range(2, mx):
        if sieve[i] != 0:
            continue  # Skip if i is not a prime
        primes.append(i)  # i is a prime, add it to the primes list
        for j in range(i + i, mx, i):
            sieve[j] = i  # Mark j as not prime
    return primes

def main():
    mx = 10000
    primes = sieve_of_eratosthenes(mx)

    # Read the number of integers to process
    n = int(input())
    ans = 0

    # Process each integer and update the answer
    for _ in range(n):
        x = int(input())
        ans += 1  # Assume the number is valid
        for prime in primes:
            if x > prime and x % prime == 0:
                ans -= 1  # The number is not valid
                break

    # Output the result
    print(ans)

main()
