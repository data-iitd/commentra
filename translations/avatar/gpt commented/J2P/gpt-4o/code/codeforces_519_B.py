# Import necessary modules
import sys

def main():
    # Read the number of elements to be processed
    n = int(input())
    
    # Initialize variables to hold the sums of three different sets of integers
    a = 0
    b = 0
    c = 0
    
    # Read n integers and calculate their sum (a)
    for _ in range(n):
        a += int(input())
    
    # Read n-1 integers and calculate their sum (b)
    for _ in range(n - 1):
        b += int(input())
    
    # Read n-2 integers and calculate their sum (c)
    for _ in range(n - 2):
        c += int(input())
    
    # Calculate the difference between the sums: x = sum of first set - sum of second set
    x = a - b
    
    # Calculate the difference between the sums: y = sum of second set - sum of third set
    y = b - c
    
    # Print the results of the differences
    print(x)
    print(y)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
