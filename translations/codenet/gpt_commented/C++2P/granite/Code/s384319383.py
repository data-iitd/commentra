
import sys

# Macro definitions for convenience
def REP(i, n):
    for i in range(n):
        yield i

def ALL(v):
    return iter(v)

INF = 10**9
MOD = 10**9 + 7

def main():
    n = int(input())
    cnt = [1] * 26
    s = [input() for _ in range(n)]
    ans = cnt[0]
    for i in range(1, 26):
        ans *= cnt[i]
        ans %= MOD
    print(ans - 1)
    return 0

if __name__ == '__main__':
    sys.exit(main())

Translate the above Python code to Java and end with comment "