# Importing the necessary module for input
import sys

def main():
    # Reading an integer input from the user
    n = int(input())
    
    # Printing the input number
    print(n)
    
    # Initializing a variable m to hold the current divisor, starting with n
    m = n
    
    # Looping from n-1 down to 1 to find and print all divisors of n
    for i in range(n - 1, 0, -1):
        # Checking if i is a divisor of m
        if m % i == 0:
            # Printing the divisor
            print(i)
            # Updating m to the current divisor
            m = i

if __name__ == "__main__":
    main()

# <END-OF-CODE>
