
# Package main is the entry point of the program
import sys

def get_scanner(fp):
    # Function to initialize a new scanner for reading input
    scanner = fp.split()
    return scanner

def get_next_string(scanner):
    # Function to read the next word as a string
    return scanner.pop(0)

def get_next_int(scanner):
    # Function to read the next integer from the input
    return int(get_next_string(scanner))

def get_next_int64(scanner):
    # Function to read the next integer64 from the input
    return int(get_next_string(scanner))

def get_next_uint64(scanner):
    # Function to read the next uint64 from the input
    return int(get_next_string(scanner))

def get_next_float64(scanner):
    # Function to read the next float64 from the input
    return float(get_next_string(scanner))

# Main function to solve the problem
def main():
    # Initializing standard input and output file pointers
    fp = sys.stdin
    wfp = sys.stdout

    # If input file and output file are provided as command line arguments
    if len(sys.argv) > 1:
        # Open the input file
        fp = open(sys.argv[1], 'r')

        # If output file is provided, create it
        if len(sys.argv) > 2:
            wfp = open(sys.argv[2], 'w')

    # Initialize a new scanner for reading input
    scanner = get_scanner(fp)
    writer = wfp

    # Read the number of elements in the array
    n = get_next_int(scanner)

    # Initialize a slice of length n to store the elements
    ll = [0] * n

    # Read the elements of the array
    for i in range(n):
        ll[i] = get_next_int(scanner)

    # Sort the slice in ascending order
    ll.sort()

    # Initialize the answer variable to 0
    ans = 0

    # Iterate through all possible pairs of elements
    for i in range(n-2):
        # Iterate through all possible right pointers
        for j in range(i+1, n-1):
            # Initialize the left and right pointers for binary search
            l = j + 1
            r = n

            # Binary search to find the index of the element greater than the sum of the current pair
            while l < r:
                m = (l + r) // 2
                if ll[m] < ll[i] + ll[j]:
                    l = m + 1
                    continue
                r = m

            # Update the answer variable
            ans += l - (j + 1)

    # Write the answer to the output file
    writer.write(str(ans) + '\n')

    # Flush the writer buffer
    writer.flush()

# 