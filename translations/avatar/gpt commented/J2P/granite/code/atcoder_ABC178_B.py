
import sys

# Function to compute (x^y) % mod using modular exponentiation
def modPower(x, y, mod):
    res = 1
    x %= mod # Reduce x modulo mod
    if x == 0: return 0 # If x is 0, return 0
    
    # Loop until y becomes 0
    while y > 0: 
        # If y is odd, multiply x with result
        if y % 2 == 1: 
            res = (res * x) % mod 
        y = y >> 1 # Divide y by 2
        x = (x * x) % mod # Square x
    return res # Return the final result

# Main method to execute the program
def main():
    a = list(map(int, sys.stdin.readline().split())) # Read four integers from input
    print(max(a[0] * a[2], max(a[1] * a[3], max(a[0] * a[3], a[1] * a[2])))) # Calculate and print the maximum product of pairs from the array

if __name__ == "__main__":
    main() # Call the main method

