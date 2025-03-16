# Import the sys module for user input
import sys

def main():
    # Read an integer input from the user
    n = int(sys.stdin.readline().strip())
    
    # Initialize a variable to hold the final result
    ans = 0
    
    # Loop through each integer from 1 to n (inclusive)
    for i in range(1, n + 1):
        # Calculate the contribution of the current integer i to the result
        # This involves multiplying i by the number of times i fits into n
        # and summing up the series of numbers from 1 to (n // i)
        ans += i * (n // i) * ((n // i) + 1) // 2
    
    # Output the final result
    print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
