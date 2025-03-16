#include<cstdio>
#define int long long  # Step 1: Define a type for long long integers

n, m, mod, C = [0] * 310, [0] * 310, [0] * 310, [0] * 310
# Step 2: Declare variables for input values, binomial coefficients, and dynamic programming table

using namespace std;  # Step 3: Specify the namespace

signed main() {  # Step 4: Define the main function with return type signed
    scanf("%lld%lld%lld", &n, &m, &mod);  # Step 5: Read input values

    C[0][0] = 1  # Initialize the binomial coefficient table
    # Step 6: Compute binomial coefficients using nested loops
    for i in range(1, n + 1):
        C[i][0] = C[i][i] = 1
        for j in range(1, i):
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod

    # Step 7: Initialize the dynamic programming table
    for i in range(0, m + 1):
        f[1][i] = 1
        pre[1][i] = m - i + 1

    # Step 8: Compute the dynamic programming table
    for i in range(2, n + 2):
        for j in range(0, m + 1):
            for k in range(1, i):
                (f[i][j] += f[i - k][j] * pre[k][j + 1] % mod * C[i - 2][k - 1]) %= mod
        for j in range(m, -1, -1):
            pre[i][j] = (pre[i][j + 1] + f[i][j]) % mod

    # Step 9: Output the result
    printf("%lld\n", f[n + 1][0])  # Print the value of f[n+1][0]
}

