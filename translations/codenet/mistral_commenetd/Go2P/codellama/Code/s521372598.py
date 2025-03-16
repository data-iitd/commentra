
# Importing necessary packages
import sys

def solve():
    # Function to solve the problem
    n = int(sys.stdin.readline()) # Read the number of elements in the array
    as = list(map(int, sys.stdin.readline().split())) # Read the array elements

    # Initialize an array xs of size n
    xs = [0] * n
    # Iterate through the array as and assign the value xs[i]
    for i, a in enumerate(as):
        xs[i] = a - i + 1 # Assign the value xs[i] = a - i + 1

    # Sort the array xs in ascending order
    xs.sort()

    # Assign the middle element of the sorted array xs to variable b
    b = xs[n//2]
    # Initialize variable ans with 0
    ans = 0
    # Iterate through the array xs and calculate the absolute difference between each element and b
    for x in xs:
        ans += abs(x - b) # Calculate the absolute difference and add it to ans

    # Print the answer
    print(ans)

def abs(n):
    # Function to calculate the absolute difference of a number
    if n < 0:
        # If the number is negative, return the negative number with the minus sign removed
        return -n
    # If the number is non-negative, return the number itself
    return n

# Main function
if __name__ == "__main__":
    solve() # Call the solve function

