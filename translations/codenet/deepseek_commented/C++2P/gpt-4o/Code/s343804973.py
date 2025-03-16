def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    n = int(data[0])
    m = int(data[1])
    mod = int(data[2])
    
    C = [[0] * 310 for _ in range(310)]  # Binomial coefficient table
    pre = [[0] * 310 for _ in range(310)]  # Prefix sums
    f = [[0] * 310 for _ in range(310)]  # Dynamic programming table

    C[0][0] = 1  # Initialize the binomial coefficient table
    # Compute binomial coefficients
    for i in range(1, n + 1):
        C[i][0] = C[i][i] = 1
        for j in range(1, i):
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod

    # Initialize the dynamic programming table
    for i in range(m + 1):
        f[1][i] = 1
        pre[1][i] = m - i + 1

    # Compute the dynamic programming table
    for i in range(2, n + 2):
        for j in range(m + 1):
            for k in range(1, i):
                f[i][j] = (f[i][j] + f[i - k][j] * pre[k][j + 1] % mod * C[i - 2][k - 1]) % mod
        for j in range(m, -1, -1):
            pre[i][j] = (pre[i][j + 1] + f[i][j]) % mod

    # Output the result
    print(f[n + 1][0])  # Print the value of f[n+1][0]

if __name__ == "__main__":
    main()
# <END-OF-CODE>
