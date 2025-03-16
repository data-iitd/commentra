# Define long long type for large integers
from typing import List

# Constants for infinity and modulo operations
inf = 0x3f3f3f3f
mod = (10**9 + 7) if 1 else 998244353

def main():
    # Optimize input/output operations
    import sys
    input = sys.stdin.readline
    
    # Declare variables for input and processing
    z = input().strip()
    
    # Get the size of the input string
    a = len(z)
    
    # Check for consecutive identical characters in the string
    for i in range(a - 1):
        # If two consecutive characters are the same, print "Bad" and exit
        if z[i] == z[i + 1]:
            print("Bad")
            return
    
    # If no consecutive identical characters were found, print "Good"
    print("Good")

# Call the main function
if __name__ == "__main__":
    main()
