# Import the sys module for reading input
import sys

def main():
    # Read the number of test cases
    t = int(sys.stdin.readline().strip())
    
    # Loop through each test case
    for _ in range(t):
        # Read the integer n for the current test case
        n = int(sys.stdin.readline().strip())
        
        # Call the max_left function and print the result
        print(max_left(n))

# Function to calculate the maximum value based on the input n
def max_left(n):
    # Return n - 2 if n is greater than 2, otherwise return 0
    return n - 2 if n > 2 else 0

if __name__ == "__main__":
    main()

# <END-OF-CODE>
