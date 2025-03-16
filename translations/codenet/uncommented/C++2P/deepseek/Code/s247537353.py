import sys
input = sys.stdin.readline

def chmin(a, b):
    if a > b:
        a = b
        return True
    return False

def chmax(a, b):
    if a < b:
        a = b
        return True
    return False

INF = (1 << 30) - 1
INFLL = (1LL << 61) - 1
MOD = 1000000007

def main():
    A, B, C, K = map(int, input().split())
    if A + B >= K:
        print(min(A, K))
    else:
        print(A - (K - (A + B)))

if __name__ == "__main__":
    main()
