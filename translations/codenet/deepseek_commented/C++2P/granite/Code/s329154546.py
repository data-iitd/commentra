
import sys

def main():
    N, L = map(int, input().split())
    S = [input() for _ in range(N)]
    S.sort()
    print("\n".join(S))

if __name__ == "__main__":
    main()

