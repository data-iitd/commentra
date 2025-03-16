
# Importing necessary packages
import sys

# Function to read next integer from the standard input
def nextInt():
    return int(input())

# Function to reverse the subarray of array 'a' from index 'b' to 'e' (both inclusive)
def reva(b):
    # Reverse the subarray using a simple method of swapping elements
    for i in range(len(b)//2):
        b[i], b[len(b)-1-i] = b[len(b)-1-i], b[i]

# Main function
def main():
    # Read the number of elements in the array 'a'
    n = nextInt()
    # Allocate memory for the array 'a' of size 'n'
    a = [0] * n

    # Read 'n' integers from the standard input and store them in the array 'a'
    for i in range(n):
        a[i] = nextInt()

    # Read the number of queries 'q'
    q = nextInt()

    # Process each query by reversing the subarray of 'a'
    for i in range(q):
        # Read the starting and ending indices of the subarray to be reversed
        b = nextInt()
        e = nextInt()

        # Reverse the subarray 'a[b:e]'
        reva(a[b:e])

    # Write the reversed array 'a' to the standard output
    for i in range(n):
        # Write each element of the array 'a' to the standard output with a space in between (except for the first element)
        if i > 0:
            sys.stdout.write(" ")
        sys.stdout.write(str(a[i]))

    # End of the code

# Call the main function to execute the code
main()

