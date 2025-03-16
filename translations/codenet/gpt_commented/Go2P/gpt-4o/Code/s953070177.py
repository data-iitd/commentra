import sys

# Function to read the next integer from the input.
def get_next_int(scanner):
    return int(scanner.readline().strip())

# Function to calculate the absolute value of an integer.
def absint(a):
    return -a if a < 0 else a

def main():
    # Determine the input source: standard input or a file specified as a command-line argument.
    if len(sys.argv) > 1:
        with open(sys.argv[1], 'r') as fp:
            scanner = fp
    else:
        scanner = sys.stdin

    # Read the number of elements from the input.
    n = get_next_int(scanner)

    # Initialize a list to hold the elements and a variable to store the total sum of absolute differences.
    aa = [0] * (n + 2)
    sum_diff = 0

    # Read the elements into the list and calculate the total sum of absolute differences between consecutive elements.
    for i in range(n):
        aa[i + 1] = get_next_int(scanner)
        sum_diff += absint(aa[i + 1] - aa[i])

    # Include the difference between the last element and the element before it.
    sum_diff += absint(aa[n + 1] - aa[n])

    # Calculate and print the result for each element.
    results = []
    for i in range(1, n + 1):
        # Calculate the new sum of absolute differences if the i-th element is removed.
        ans = sum_diff - absint(aa[i + 1] - aa[i]) - absint(aa[i] - aa[i - 1]) + absint(aa[i + 1] - aa[i - 1])
        results.append(ans)  # Store the result for the current element.

    # Print all results.
    print('\n'.join(map(str, results)))

if __name__ == "__main__":
    main()

# <END-OF-CODE>
