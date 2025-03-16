# Define long long type for convenience
import sys

# Define input() to get input from stdin
input = sys.stdin.readline

# Define is_prime() to check if a number is prime
def is_prime(x):
    # Check divisibility from 2 to the square root of x
    for i in range(2, int(x**0.5)+1):
        if x % i == 0: return False # If divisible, not prime
    return True # If no divisors found, it is prime

# Read the input value N
N = int(input())

# Initialize the answer variable to 1
ans = 1

# Loop through all numbers from 2 to N
for i in range(2, N+1):
    # Check if the current number i is prime
    if is_prime(i):
        # Store the original value of N for calculations
        NN = N
        # Initialize a counter for the prime factor's exponent
        cnt = 0

        # Count the number of times i is a factor in the numbers from 1 to N
        while NN:
            cnt += NN // i # Count multiples of i
            NN //= i # Reduce NN by dividing by i

        # Update the answer by multiplying with the count of factors + 1
        ans *= cnt + 1
        ans %= 1000000007 # Take modulo to prevent overflow

# Output the final result
print(ans)
# 