import sys

def main():
    input = sys.stdin.readline
    N, L = map(int, input().split())
    S = [input().strip() for _ in range(N)]
    S.sort()
    print(''.join(S))

if __name__ == "__main__":
    main()
