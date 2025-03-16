# Importing necessary modules
import sys

def main():
    # Read a line of input and split it into a list of integers
    ns = list(map(int, sys.stdin.readline().strip().split()))
    
    # Sort the list in ascending order
    ns.sort()
    
    # Check if the sorted list contains the numbers 1, 4, 7, and 9 in that order
    if ns == [1, 4, 7, 9]:
        print("YES")  # Print "YES" if the condition is true
    else:
        print("NO")   # Print "NO" if the condition is false

if __name__ == "__main__":
    main()

# <END-OF-CODE>
