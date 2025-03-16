import sys

def main():
    input = sys.stdin.readline
    N, M = map(int, input().split())

    L = [0] * 100000
    for i in range(N):
        L[i] = int(input())

    L.sort()

    for _ in range(M):
        max_L = L[-1]
        if max_L == 0:
            break

        max_L //= 2
        idx = bisect.bisect_left(L, max_L)
        L.insert(idx, max_L)
        L.pop()

    ans = sum(L)

    print(ans)

if __name__ == "__main__":
    main()
