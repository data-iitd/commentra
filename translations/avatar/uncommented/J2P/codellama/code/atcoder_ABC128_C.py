import sys

def main():
    sc = sys.stdin
    N, M = map(int, sc.readline().split())
    a = [0] * N
    for i in range(M):
        k = int(sc.readline())
        for j in range(k):
            s = int(sc.readline())
            s -= 1
            a[s] |= (1 << i)
    p = 0
    for i in range(M):
        x = int(sc.readline())
        p |= (x << i)
    ans = 0
    for s in range(1 << N):
        t = 0
        for i in range(N):
            if (s >> i) & 1:
                t ^= a[i]
        if p == t:
            ans += 1
    print(ans)


if __name__ == "__main__":
    main()


