import sys

# absint returns the absolute value of an integer.
def absint(a):
    return -a if a < 0 else a

# main is the entry point of the program.
def main():
    # Check if a file name is provided as an argument.
    if len(sys.argv) > 1:
        with open(sys.argv[1], 'r') as f:
            data = f.read().split()
    else:
        data = sys.stdin.read().split()

    # Read the number of elements.
    n = int(data[0])

    # Initialize a list to store the elements and a sum variable.
    aa = [0] * (n + 2)
    sum_diff = 0

    # Read the elements into the list and calculate the sum of absolute differences.
    for i in range(n):
        aa[i + 1] = int(data[i + 1])
        sum_diff += absint(aa[i + 1] - aa[i])

    sum_diff += absint(aa[n + 1] - aa[n])

    # Calculate and print the differences for each element.
    results = []
    for i in range(1, n + 1):
        ans = sum_diff - absint(aa[i + 1] - aa[i]) - absint(aa[i] - aa[i - 1]) + absint(aa[i + 1] - aa[i - 1])
        results.append(ans)

    # Print all results.
    print('\n'.join(map(str, results)))

if __name__ == "__main__":
    main()

# <END-OF-CODE>
