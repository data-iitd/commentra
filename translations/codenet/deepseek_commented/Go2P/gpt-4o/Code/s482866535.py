import sys

# Function to read the next integer from the input.
def get_next_int():
    return int(next(scanner))

# Main function to compute the minimum number of matrix multiplications.
if __name__ == "__main__":
    # Initialize scanner for standard input or a file.
    if len(sys.argv) > 1:
        fp = open(sys.argv[1], 'r')
    else:
        fp = sys.stdin

    scanner = iter(fp.read().split())

    # Read the number of matrices.
    n = get_next_int()

    # Initialize lists for matrix dimensions and dynamic programming.
    mm = [0] * (n + 1)
    dp = [[0] * (n + 1) for _ in range(n + 1)]

    # Read matrix dimensions into the mm list.
    for i in range(n):
        mm[i] = get_next_int()
        mm[i + 1] = get_next_int()

    # Use dynamic programming to compute the minimum number of multiplications.
    for l in range(2, n + 1):
        for i in range(1, n - l + 2):
            j = i + l - 1
            for k in range(i, j):
                d = dp[i][k] + dp[k + 1][j] + mm[i - 1] * mm[k] * mm[j]
                if dp[i][j] == 0 or dp[i][j] > d:
                    dp[i][j] = d

    # Print the result to the standard output.
    print(dp[1][n])

# <END-OF-CODE>
