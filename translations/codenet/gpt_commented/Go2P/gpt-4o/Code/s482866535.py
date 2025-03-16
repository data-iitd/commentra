import sys

# get_next_string retrieves the next string from the input.
def get_next_string():
    return input().strip()

# get_next_int retrieves the next integer from the input.
def get_next_int():
    return int(get_next_string())

def main():
    # Determine the input source: standard input or a file specified as a command-line argument.
    if len(sys.argv) > 1:
        with open(sys.argv[1], 'r') as f:
            input_data = f.read().splitlines()
            input_iter = iter(input_data)
            n = int(next(input_iter))  # Read the number of elements.
    else:
        input_iter = iter(sys.stdin.read().splitlines())
        n = int(next(input_iter))  # Read the number of elements.

    mm = [0] * (n + 1)  # Create a list to hold the input values.
    dp = [[0] * (n + 1) for _ in range(n + 1)]  # Create a 2D list for dynamic programming.

    # Read the input values into the mm list.
    for i in range(n):
        mm[i] = get_next_int()  # Read the first value.
        mm[i + 1] = get_next_int()  # Read the second value.

    # Perform dynamic programming to calculate the minimum cost.
    for l in range(2, n + 1):  # l is the length of the subproblem.
        for i in range(1, n - l + 2):  # i is the starting index of the subproblem.
            j = i + l - 1  # j is the ending index of the subproblem.
            for k in range(i, j):  # k is the partition point.
                # Calculate the cost of multiplying the matrices.
                d = dp[i][k] + dp[k + 1][j] + mm[i - 1] * mm[k] * mm[j]
                # Update the dp table with the minimum cost found.
                if dp[i][j] == 0 or dp[i][j] > d:
                    dp[i][j] = d

    # Output the minimum cost of multiplying the entire sequence of matrices.
    print(dp[1][n])

if __name__ == "__main__":
    main()

# <END-OF-CODE>
