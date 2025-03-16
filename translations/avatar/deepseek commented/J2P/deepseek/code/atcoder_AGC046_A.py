import sys
import io
import os
import math
import sys
import threading

input = sys.stdin.readline

def main():
    # Read an integer input
    x = int(input())
    # Initialize a counter to keep track of the number of iterations
    count = 0
    # Store the initial value of x in a temporary variable
    tmp = x
    
    # Initialize x to 0 to start the loop
    x = 0
    
    # Loop until x becomes 360
    while x != 360:
        # Increment x by tmp
        x += tmp
        # If x exceeds 360, adjust it by subtracting 360
        if x > 360:
            x -= 360
        # Increment the counter
        count += 1
    
    # Print the final count
    print(count)

if __name__ == "__main__":
    main()
