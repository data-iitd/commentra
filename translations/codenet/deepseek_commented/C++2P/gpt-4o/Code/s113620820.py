import sys

# Constants
MAX_N = 4000
LINF = 1 << 60

# Global variables
wis = [0] * MAX_N
wsums = [0] * (MAX_N + 1)
dp = [[LINF] * (MAX_N + 1) for _ in range(MAX_N)]
ks = [[-1] * (MAX_N + 1) for _ in range(MAX_N)]

# Main function
def main():
    n = int(sys.stdin.readline().strip())

    for i in range(n):
        wis[i] = int(sys.stdin.readline().strip())
        wsums[i + 1] = wsums[i] + wis[i]

    for i in range(n):
        dp[i][i + 1] = 0
        ks[i][i + 1] = i

    for l in range(2, n + 1):
        for i in range(n - l + 1):
            j = i + l
            mind = LINF
            wsum = wsums[j] - wsums[i]
            mink = -1
            for k in range(ks[i][j - 1], ks[i + 1][j] + 1):
                d = dp[i][k] + dp[k][j] + wsum
                if mind > d:
                    mind = d
                    mink = k
            dp[i][j] = mind
            ks[i][j] = mink

    print(dp[0][n])

if __name__ == "__main__":
    main()

# <END-OF-CODE>
