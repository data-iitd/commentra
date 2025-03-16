import math
import sys

def main():
    n = int(sys.stdin.readline())
    A = list(map(int, sys.stdin.readline().split()))
    div = 1000000007
    ans = 0

    for i in range(60):
        count1 = 0
        for j in range(n):
            if A[j] >> i & 1 == 1:
                count1 += 1
        a = count1 * (n - count1)
        for j in range(i):
            a = (a << 1) % div
        ans += a
        ans %= div

    print(ans)

if __name__ == "__main__":
    main()

