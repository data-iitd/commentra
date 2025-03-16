
import sys

def main():
    n = int(input())
    aa = [int(x) for x in input().split()]

    cumsum = [0] * (n + 1)
    for i in range(n):
        cumsum[i + 1] = cumsum[i] + aa[i]

    ans = 2020202020
    for i in range(1, n - 1):
        ans = min(ans, abs(cumsum[n] - 2 * cumsum[i]))

    print(ans)

if __name__ == "__main__":
    main()

