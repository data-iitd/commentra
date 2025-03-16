import sys

# Define a long long type for convenience
ll = int

# Function to update a variable to the maximum of itself and another value
def chmax(a, b):
    if a < b:
        return b
    return a

# Function to update a variable to the minimum of itself and another value
def chmin(a, b):
    if a > b:
        return b
    return a

# Define a constant for infinity
INF = 10**18 + 1

# Function to find the smallest integer n >= N such that n/S(n) is minimized
def f(N):
    # Array to store the digits of N
    a = []
    
    # Extract digits of N and store them in the array
    while N > 0:
        a.append(N % 10)  # Get the last digit
        N //= 10  # Remove the last digit

    d = len(a)  # Digit counter
    a.reverse()  # Reverse to have the digits in the correct order
    m = 1e18  # Initialize minimum fraction to a large value
    res = N  # Result variable to store the best candidate

    # Iterate through possible positions to replace digits with 9s
    for i in range(d + 1):
        bunsi = 0  # Numerator
        bunbo = 9 * i  # Denominator starts with 9 times the number of replaced digits

        # Construct the numerator and denominator based on the current digit manipulation
        for j in range(d):
            bunsi *= 10  # Shift left for the next digit
            if j < i:
                bunsi += 9  # Replace with 9 if below the current index
            else:
                bunsi += a[j]  # Keep the original digit
            
            if j >= i:
                bunbo += a[j]  # Add to denominator if the digit is not replaced

        # Calculate the fraction n/S(n)
        frac = bunsi / bunbo

        # Update the result if a new minimum fraction is found
        if frac < m:
            m = frac  # Update minimum fraction
            res = bunsi  # Update result with the new candidate

    return res  # Return the best candidate found

def main():
    K = int(input())  # Read the number of outputs
    N = f(1)  # Initialize N by finding the first candidate starting from 1

    # Generate K outputs
    for _ in range(K):
        print(N)  # Output the current candidate
        N = f(N + 1)  # Find the next candidate starting from N + 1

if __name__ == "__main__":
    main()

# <END-OF-CODE>
