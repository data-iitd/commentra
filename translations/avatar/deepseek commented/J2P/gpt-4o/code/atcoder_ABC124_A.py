# Import the necessary module for reading input
import sys

def main():
    # Read two integers from the input
    a, b = map(int, sys.stdin.readline().split())
    
    # Initialize sum to 0, this will store the sum of the two numbers
    sum = 0
    
    # Loop runs twice, each time adding the larger of the two numbers to sum
    # and decrementing that number by 1
    for _ in range(2):
        if a >= b:
            sum += a
            a -= 1
        else:
            sum += b
            b -= 1
    
    # Print the final sum to the console
    print(sum)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
