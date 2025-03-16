# Importing necessary packages
import sys

# Function to read next integer from the standard input
def next_int():
    return int(sys.stdin.readline().strip())

# Function to reverse the subarray of array 'a' from index 'b' to 'e' (both inclusive)
def reva(b):
    # Reverse the subarray using slicing
    b.reverse()

# Main function
def main():
    # Read the number of elements in the array 'a'
    n = next_int()
    # Allocate memory for the array 'a' of size 'n'
    a = list(map(int, sys.stdin.readline().strip().split()))

    # Read the number of queries 'q'
    q = next_int()

    # Process each query by reversing the subarray of 'a'
    for _ in range(q):
        # Read the starting and ending indices of the subarray to be reversed
        b, e = map(int, sys.stdin.readline().strip().split())
        # Reverse the subarray 'a[b:e+1]'
        reva(a[b:e+1])

    # Write the reversed array 'a' to the standard output
    print(" ".join(map(str, a)))

# Entry point of the program
if __name__ == "__main__":
    main()

# <END-OF-CODE>
