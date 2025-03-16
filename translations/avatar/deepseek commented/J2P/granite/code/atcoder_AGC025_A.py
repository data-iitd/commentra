

import sys

def sum(a):
    ans = 0
    while a >= 10:
        ans += a % 10
        a //= 10
    ans += a
    return ans

def main():
    N = int(input())
    n = N // 2 if N % 2 == 0 else (N + 1) // 2
    ans = sum(1) + sum(N - 1)
    for A in range(1, n + 1):
        if sum(A) + sum(N - A) < ans:
            ans = sum(A) + sum(N - A)
    print(ans)

if __name__ == "__main__":
    main()

