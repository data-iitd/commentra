import sys

def chmax(a, b):
    if a < b:
        a = b
        return True
    return False

def chmin(a, b):
    if b < a:
        a = b
        return True
    return False

def main():
    input = sys.stdin.readline
    N, L = map(int, input().split())
    S = [input().strip() for _ in range(N)]
    S.sort()
    print(''.join(S))

if __name__ == "__main__":
    main()
