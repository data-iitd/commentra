
import sys

def maxLeft(n):
    # Return n - 2 if n is greater than 2, otherwise return 0
    return n - 2 if n > 2 else 0

def main():
    # Read the number of test cases from the first line of input
    t = int(input())
    
    # Loop through each test case
    for i in range(t):
        # Read the integer n for the current test case
        n = int(input())
        
        # Call the maxLeft function and print the result
        print(maxLeft(n))

if __name__ == "__main__":
    main()

