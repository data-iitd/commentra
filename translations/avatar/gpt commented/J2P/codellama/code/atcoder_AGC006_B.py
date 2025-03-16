import math
import os
import random
import re
import sys

# Complete the print function below.
def print(x, n):
    # Calculating the maximum value based on n
    max = n * 2 - 1
    
    # Checking if x is equal to 1 or max, if so, print "No" and exit the function
    if x == 1 or x == max:
        print("No")
        return
    
    # If x is valid, print "Yes"
    print("Yes")
    
    # Prepare the line separator for formatting output
    sep = os.linesep
    
    # Generate a sequence of numbers based on the input x and n
    ans = "".join(str((i % max + 1)) + sep for i in range(x + n - 1, x + n + max - 1))
    
    # Print the generated sequence
    print(ans)


if __name__ == '__main__':
    # Reading two integers from user input: n and x
    n, x = map(int, input().split())
    
    # Calling the print method with the inputs x and n
    print(x, n)


