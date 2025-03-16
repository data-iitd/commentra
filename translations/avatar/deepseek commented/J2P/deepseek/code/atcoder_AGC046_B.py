MOD = 998244353
dp = [[0] * 3001 for _ in range(3001)]

def solve(sc, pw):
    # Read the input values for A, B, C, and D
    A = int(sc.readline())
    B = int(sc.readline())
    C = int(sc.readline())
    D = int(sc.readline())

    # Initialize the dp array for the starting point (A, B)
    dp[A][B] = 1

    # Iterate over the range from A to C and from B to D
    for c in range(A, C + 1):
        for d in range(B, D + 1):
            # Skip the starting point (A, B)
            if c == A and d == B:
                continue

            # Calculate the answer based on previous states
            ans = 0
            if c > A:
                part = dp[c - 1][d]
                ans = (part * d) % MOD
            if d > B:
                part = dp[c][d - 1]
                ans = (ans + (part * c) % MOD) % MOD
            if c > A and d > B:
                ans = (ans - (dp[c - 1][d - 1] * (c - 1) * (d - 1) % MOD) + MOD) % MOD

            # Store the result in dp array
            dp[c][d] = ans

    # Output the result for the final state (C, D)
    pw.write(str(dp[C][D]) + '\n')

# Main method to set up input/output and call the solve method
def main():
    import sys
    sc = sys.stdin
    pw = sys.stdout
    solve(sc, pw)
    pw.flush()
    pw.close()
    sc.close()

main()
