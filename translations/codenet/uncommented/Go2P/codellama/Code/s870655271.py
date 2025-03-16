
import math

def main():
    N, M = map(int, input().split())
    ans = 0
    if N == 1 and M == 1:
        ans += 1
    elif 1 < N and 1 < M:
        ans += (N - 2) * (M - 2)
    else:
        ans += (N * M) - 2

    print(ans)


if __name__ == "__main__":
    main()

