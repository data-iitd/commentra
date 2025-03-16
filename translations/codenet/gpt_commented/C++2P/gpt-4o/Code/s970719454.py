# Import necessary libraries
import sys

# Arrays to store the presence of numbers and dynamic programming results
here = [0] * 100001
dp1 = [0] * 100001
dp2 = [0] * 100001

def main():
    while True:
        # Read the values of n and m
        n, m = map(int, sys.stdin.readline().split())
        # Break the loop if n is 0 (termination condition)
        if n == 0:
            break
        
        # Initialize arrays to zero for the current test case
        for i in range(100001):
            here[i] = dp1[i] = dp2[i] = 0
        
        # Flag to check if a zero was encountered in the input
        dpflg = False
        
        # Read m numbers and mark their presence
        for _ in range(m):
            a = int(sys.stdin.readline().strip())
            # If a zero is encountered, set the flag
            if a == 0:
                dpflg = True
            # Mark the presence of number a
            here[a] = 1
        
        # Variables to track the maximum lengths of sequences
        maxi1 = 0
        maxi2 = 0
        
        # Calculate the longest sequence of present numbers without a zero
        for i in range(1, n + 1):
            if here[i] == 1:
                dp1[i] = dp1[i - 1] + 1  # Increment if present
            maxi1 = max(dp1[i], maxi1)  # Update maximum length
        
        # Calculate the longest sequence of present numbers considering the presence of a zero
        for i in range(1, n + 1):
            if here[i] == 1:
                dp2[i] = dp2[i - 1] + 1  # Increment if present
            else:
                dp2[i] = dp1[i - 1] + 1  # Reset if zero is encountered
            maxi2 = max(dp2[i], maxi2)  # Update maximum length
        
        # Output the result based on whether a zero was encountered
        if not dpflg:
            print(maxi1)  # Print the maximum length without zero
        else:
            print(maxi2)  # Print the maximum length considering zero

if __name__ == "__main__":
    main()

# <END-OF-CODE>
