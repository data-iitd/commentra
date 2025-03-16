
import sys

def main():
    n, m = map(int, input().split())
    h = list(map(int, input().split()))
    good = [True] * n
    for _ in range(m):
        a, b = map(int, input().split())
        a -= 1
        b -= 1
        if h[a] > h[b]:
            good[b] = False
        elif h[a] < h[b]:
            good[a] = False
        else:
            good[a] = False
            good[b] = False
    ans = sum(good)
    print(ans)

if __name__ == "__main__":
    main()

