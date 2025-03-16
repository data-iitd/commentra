import sys

def main():
    n = int(sys.stdin.readline())
    m = int(sys.stdin.readline())
    h = [int(sys.stdin.readline()) for i in range(n)]
    good = [True for i in range(n)]
    for i in range(m):
        ai, bi = [int(x) - 1 for x in sys.stdin.readline().split()]
        if h[ai] > h[bi]:
            good[bi] = False
        elif h[ai] < h[bi]:
            good[ai] = False
        else:
            good[ai] = False
            good[bi] = False
    ans = 0
    for i in range(n):
        if good[i]:
            ans += 1
    print(ans)

if __name__ == "__main__":
    main()

