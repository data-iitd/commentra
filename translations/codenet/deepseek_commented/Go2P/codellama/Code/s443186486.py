
import sys

def main():
    n = int(sys.stdin.readline())
    a = list(map(int, sys.stdin.readline().split()))
    s = [0] * (n + 1)
    for i in range(n):
        s[i + 1] = s[i] + a[i]
    s.sort()
    ans = 0
    count = 0
    for i in range(n):
        if s[i] == s[i + 1]:
            count += 1
        else:
            if count > 0:
                ans += combi(count + 1, 2)
                count = 0
    if count > 0:
        ans += combi(count + 1, 2)
    print(ans)

def combi(n, r):
    c = 1
    for i in range(1, r + 1):
        c = c * (n - i + 1) // i
    return c

if __name__ == "__main__":
    main()

