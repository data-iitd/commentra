import sys

def main():
    N, M = map(int, input().split())
    a = []
    b = []
    c = []
    for i in range(M):
        a_, b_, c_ = map(int, input().split())
        a.append(a_)
        b.append(b_)
        c.append(c_)

    INF = 1 << 62
    dist = [INF] * N
    dist[0] = 0
    for loop in range(N):
        for i in range(M):
            if dist[a[i] - 1] == INF:
                continue
            if dist[b[i] - 1] > dist[a[i] - 1] + c[i]:
                dist[b[i] - 1] = dist[a[i] - 1] + c[i]

    ans = dist[N - 1]
    navigate = [False] * N
    for loop in range(N):
        for i in range(M):
            if dist[a[i] - 1] == INF:
                continue
            if dist[b[i] - 1] > dist[a[i] - 1] + c[i]:
                dist[b[i] - 1] = dist[a[i] - 1] + c[i]
                navigate[b[i] - 1] = True
            if navigate[a[i] - 1] == True:
                navigate[b[i] - 1] = True

    if navigate[N - 1]:
        print("inf")
    else:
        print(-ans)

if __name__ == "__main__":
    main()

