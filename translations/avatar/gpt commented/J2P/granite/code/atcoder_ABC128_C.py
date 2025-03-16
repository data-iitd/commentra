
import sys

def main():
    # Read input from the console
    N, M = map(int, input().split())
    a = [0] * N
    for _ in range(M):
        k, *s = map(int, input().split())
        for si in s:
            a[si - 1] |= 1 << _
    p = 0
    for i in range(M):
        x = int(input())
        p |= x << i
    ans = 0
    for s in range(1 << N):
        t = 0
        for i in range(N):
            if (s >> i) & 1:
                t ^= a[i]
        if p == t:
            ans += 1
    print(ans)

if __name__ == "__main__":
    main()

