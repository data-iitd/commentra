# Include necessary libraries
import sys

# Declare global variables
N, S = 0, 0

def main():  # Start the main function
    for line in sys.stdin:  # Read input from standard input
        N = int(line.strip())  # Read the number of elements (N)
        if N <= 0:
            break  # Exit if N is not positive
        
        M = -1  # Initialize maximum
        m = 1001  # Initialize minimum
        addup = 0  # Initialize sum
        
        for _ in range(N):  # Loop through each element
            S = int(sys.stdin.readline().strip())  # Read the element
            addup += S  # Update sum
            if S > M:
                M = S  # Update maximum
            if S < m:
                m = S  # Update minimum
        
        # Calculate the average of the remaining numbers
        print((addup - M - m) // (N - 2))  # Use integer division

if __name__ == "__main__":
    main()  # Call the main function

# <END-OF-CODE>
