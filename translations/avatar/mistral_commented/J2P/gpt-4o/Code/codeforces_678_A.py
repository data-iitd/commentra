# Import the sys module for reading input
import sys

def main():
    # Read the first integer `n` from the standard input
    n = int(sys.stdin.readline().strip())
    # Read the second integer `k` from the standard input
    k = int(sys.stdin.readline().strip())
    
    n += 1  # Increment the value of `n` by 1
    z = 0   # Initialize an integer variable `z` to 0
    
    if n % k != 0:  # Check if the remainder of `n` divided by `k` is equal to 0
        z = k - n % k  # If the remainder is not equal to 0, calculate the difference between `k` and the remainder and assign it to `z`
    
    print(n + z)  # Print the value of `n` plus the value of `z`

if __name__ == "__main__":
    main()

# <END-OF-CODE>
