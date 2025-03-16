#include<stdio.h>

def sieve(n):
    prime = [True for i in range(n+1)]
    p = 2
    while (p * p <= n):
        if (prime[p] == True):
            for i in range(p * 2, n+1, p):
                prime[i] = False
        p += 1
    prime[0] = False
    prime[1] = False
    return prime

def countPrimes(n, prime):
    count = 0
    for i in range(n+1):
        if (prime[i] == True):
            count += 1
    return count

def main():
    # Define the maximum value for the sieve
    MAX_V = 999999
    # Array to store prime status of numbers from 0 to MAX_V
    prime = sieve(MAX_V)
    # Set 0 and 1 as non-prime
    prime[0] = False
    prime[1] = False
    # Counter for the number of inputs processed
    count = 0
    # Read integers from standard input until EOF
    while (True):
        n = int(input())
        if (n == -1):
            break
        count += 1
        # Count the number of primes less than or equal to n
        cnt = countPrimes(n, prime)
        # Print the count of primes for the current input
        print(cnt)
        # Break the loop after processing 30 inputs
        if (count == 30):
            break

if __name__ == "__main__":
    main()

