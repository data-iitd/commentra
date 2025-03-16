import sys

def main():
    input = sys.stdin.readline
    N, M = map(int, input().split())
    Inf = 1 << 62
    a = []
    b = []
    c = []
    for _ in range(M):
        ai, bi, ci = map(int, input().split())
        c.append(-ci)
        a.append(ai - 1)
        b.append(bi - 1)
    
    dist = [Inf] * N
    dist[0] = 0
    
    for loop in range(N):
        for i in range(M):
            if dist[a[i]] == Inf:
                continue
            if dist[b[i]] > dist[a[i]] + c[i]:
                dist[b[i]] = dist[a[i]] + c[i]
    
    ans = dist[N - 1]
    navigate = [False] * N
    
    for loop in range(N):
        for i in range(M):
            if dist[a[i]] == Inf:
                continue
            if dist[b[i]] > dist[a[i]] + c[i]:
                dist[b[i]] = dist[a[i]] + c[i]
                navigate[b[i]] = True
            if navigate[a[i]]:
                navigate[b[i]] = True
    
    if navigate[N - 1]:
        print("inf")
    else:
        print(-ans)

if __name__ == "__main__":
    main()
