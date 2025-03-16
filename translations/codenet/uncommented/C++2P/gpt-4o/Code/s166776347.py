# Import necessary libraries
import sys
from collections import defaultdict

# Define constants
mod = 10**9 + 7

def main():
    # Input
    N, K = map(int, input().split())
    A = list(map(int, input().split()))

    # Solution
    ans1 = 0
    for i in range(N):
        for j in range(N):
            if i >= j:
                continue
            if A[i] > A[j]:
                ans1 += 1
            ans1 %= mod

    count = [0] * 2005
    for i in range(N):
        count[A[i] - 1] += 1

    ans2 = 0
    remain = N
    for i in range(2005):
        remain -= count[i]
        ans2 += count[i] * remain

    ans = 0
    tmp = K * (K - 1) // 2
    tmp %= mod
    tmp *= ans2
    tmp %= mod
    ans += ans1 * K
    ans %= mod
    ans += tmp
    ans %= mod

    # Output
    print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
