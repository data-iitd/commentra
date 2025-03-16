import sys
import math

def f(N):
    a = [0] * 20  # List to store digits of N
    d = 0  # Digit counter
    while N > 0:
        a[d] = N % 10  # Store the last digit of N
        N //= 10  # Remove the last digit from N
        d += 1  # Increment the digit counter
    
    m = float('inf')  # Initialize the minimum fraction to infinity
    res = N  # Initialize the result to 0
    for i in range(d + 1):
        bunsi = 0  # Numerator
        bunbo = 9 * i  # Denominator
        for j in range(d - 1, -1, -1):
            bunsi *= 10
            if j < i:
                bunsi += 9  # Add 9 to the current digit if necessary
            else:
                bunsi += a[j]  # Add the actual digit
            
            if j >= i:
                bunbo += a[j]  # Add the actual digit to the denominator if necessary
        
        frac = bunsi / bunbo  # Calculate the fraction
        if frac < m:
            m = frac  # Update the minimum fraction
            res = bunsi  # Update the result
    
    return res  # Return the result

def main():
    K = int(input().strip())  # Read the number of iterations
    N = f(1)  # Initialize N with the result of f(1)
    for i in range(K):
        print(N)  # Output the current N
        N = f(N + 1)  # Update N to the result of f(N+1)

# Call the main function
main()
