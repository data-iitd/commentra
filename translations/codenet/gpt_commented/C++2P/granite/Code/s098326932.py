
import sys

# Define a long long type for convenience
def read_ll():
    return int(input())

def write_ll(x):
    print(x)

# Function to update a variable to the maximum of itself and another value
def chmax(a, b):
    if a < b:
        a = b
        return 1
    return 0

# Function to update a variable to the minimum of itself and another value
def chmin(a, b):
    if a > b:
        a = b
        return 1
    return 0

# Define a constant for infinity
INF = 1e18 + 1

# Function to find the smallest integer n >= N such that n/S(n) is minimized
def f(N):
    # Array to store the digits of N
    a = [0] * 20
    d = 0 # Digit counter

    # Extract digits of N and store them in the array
    while N > 0:
        a[d] = N % 10 # Get the last digit
        N //= 10 # Remove the last digit
        d += 1 # Increment digit counter

    m = 1e18 # Initialize minimum fraction to a large value
    res = N # Result variable to store the best candidate

    # Iterate through possible positions to replace digits with 9s
    for i in range(d + 1):
        bunsi = 0 # Numerator
        bunbo = 9 * i # Denominator starts with 9 times the number of replaced digits

        # Construct the numerator and denominator based on the current digit manipulation
        for j in range(d - 1, -1, -1):
            bunsi *= 10 # Shift left for the next digit
            if j < i: 
                bunsi += 9 # Replace with 9 if below the current index
            else: 
                bunsi += a[j] # Keep the original digit
            
            if j >= i: 
                bunbo += a[j] # Add to denominator if the digit is not replaced

        # Calculate the fraction n/S(n)
        frac = bunsi / bunbo

        # Update the result if a new minimum fraction is found
        if frac < m:
            m = frac # Update minimum fraction
            res = bunsi # Update result with the new candidate

    return res # Return the best candidate found

# Main function
def main():
    K = read_ll() # Number of outputs to generate
    N = f(1) # Initialize N by finding the first candidate starting from 1

    # Generate K outputs
    for i in range(K):
        write_ll(N) # Output the current candidate
        N = f(N + 1) # Find the next candidate starting from N + 1

if __name__ == '__main__':
    main()

