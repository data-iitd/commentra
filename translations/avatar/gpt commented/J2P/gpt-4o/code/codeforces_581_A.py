# Importing the sys module for user input
import sys

def main():
    # Reading two integers from user input
    a, b = map(int, sys.stdin.readline().split())
    
    # Initializing a counter to keep track of the number of pairs processed
    count = 0
    
    # Loop to process pairs of a and b while both are greater than zero
    while True:
        # Check if both a and b are positive
        if a > 0 and b > 0:
            # Increment the count of pairs
            count += 1
            # Decrement both a and b
            a -= 1
            b -= 1
        else:
            # Break the loop if either a or b is not positive
            break
    
    # Calculate the number of pairs that can be formed from the remaining a and b
    ans = a // 2 + b // 2
    
    # Output the count of pairs processed and the calculated answer
    print(count, ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
