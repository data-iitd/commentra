import sys

# Define the matrix and DP arrays
mat = [[0] * 3000 for _ in range(3000)]
dp = [[[0] * 4 for _ in range(3000)] for _ in range(3000)]
dpl = [0] * 3000

def main():
    rr, cc, k = map(int, sys.stdin.readline().split())

    # Read each non-zero element's row, column, and value, and store in the matrix
    for _ in range(k):
        r, c, v = map(int, sys.stdin.readline().split())
        mat[r - 1][c - 1] = v

    # Initialize the DP table for the starting cell
    dp[0][0][1] = mat[0][0]

    # Fill the DP table
    for y in range(rr):
        for x in range(cc):
            for c in range(4):
                v = mat[y][x]
                if c == 0 or v == 0:
                    q = dpl[x] if x == 0 else max(dpl[x], dp[y][x - 1][c])
                else:
                    q = (dpl[x] + v) if x == 0 else max(dpl[x] + v, max(dp[y][x - 1][c], dp[y][x - 1][c - 1] + v))
                dp[y][x][c] = q

        # Update the maximum values for each column after processing the current row
        for x in range(cc):
            dpl[x] = max(dp[y][x][0], dp[y][x][1], dp[y][x][2], dp[y][x][3])

    # Output the maximum value in the last column of the last row
    print(dpl[cc - 1])

if __name__ == "__main__":
    main()

# <END-OF-CODE>
