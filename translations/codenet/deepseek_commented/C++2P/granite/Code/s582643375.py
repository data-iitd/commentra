
import sys
input = sys.stdin.readline

MOD = 10**9 + 7
MAX = 10**6 + 10

fac = [0] * MAX
finv = [0] * MAX
inv = [0] * MAX

# Initialize factorial, inverse factorial, and inverse arrays
def COMinit():
    fac[0] = fac[1] = 1
    finv[0] = finv[1] = 1
    inv[1] = 1
    for i in range(2, MAX):
        fac[i] = fac[i-1] * i % MOD
        inv[i] = MOD - inv[MOD%i] * (MOD//i) % MOD
        finv[i] = finv[i-1] * inv[i] % MOD

# Calculate the binomial coefficient C(n, k)
def COM(n, k):
    if n < k:
        return 0
    if n < 0 or k < 0:
        return 0
    return fac[n] * (finv[k] * finv[n-k] % MOD) % MOD

# Main function logic
if __name__ == "__main__":
    COMinit()
    X, Y = map(int, input().split())
    # Check if the sum of X and Y is divisible by 3
    if (X+Y) % 3!= 0:
        print(0)
        exit()
    # Calculate the number of steps needed to reach the target point
    n = (X+Y) // 3 + 1
    # Calculate the number of steps needed to reach the target point from the most upper point
    k = 2*(n-1) - Y + 1 # y = 2xより最も上にくる点からどれだけ離れているか。
    # Output the number of ways to reach the target point
    print(COM(n-1, k-1))

