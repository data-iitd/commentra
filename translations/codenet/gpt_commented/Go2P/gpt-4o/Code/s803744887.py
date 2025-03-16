def main():
    # Define a constant for the maximum limit for the sieve
    MX = 10000
    
    # Create a list to hold the sieve values and a list to store the prime numbers
    sieve = [0] * MX
    primes = []
    
    # Implement the Sieve of Eratosthenes to find all prime numbers up to MX
    for i in range(2, MX):
        # If sieve[i] is not zero, it means i is not a prime number
        if sieve[i] != 0:
            continue
        # i is a prime number, add it to the primes list
        primes.append(i)
        # Mark all multiples of i as non-prime by setting their sieve value
        for j in range(i + i, MX, i):
            sieve[j] = i

    # Read the number of integers to process
    n = int(input())
    
    # Initialize a counter for the number of integers that are prime
    ans = 0
    
    # Process each integer input
    for _ in range(n):
        x = int(input())
        # Assume the number is prime initially
        ans += 1
        # Check if x is divisible by any of the found prime numbers
        for prime in primes:
            # If x is greater than the prime and divisible by it, it's not prime
            if x > prime and x % prime == 0:
                ans -= 1  # Decrease the count of prime numbers
                break  # No need to check further primes
    
    # Output the count of prime numbers found
    print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
