# Import the necessary module
import sys

def main():
    # Read an integer n from the user input
    n = int(input())
    
    # Print the value of n
    print(n)
    
    # Initialize a variable m with the value of n
    m = n
    
    # Enter a loop that runs from n-1 down to 1
    for i in range(n - 1, 0, -1):
        # Check if m is divisible by i
        if m % i == 0:
            # If m is divisible by i, print i and update m to i
            print(i)
            m = i

if __name__ == "__main__":
    main()

# <END-OF-CODE>
