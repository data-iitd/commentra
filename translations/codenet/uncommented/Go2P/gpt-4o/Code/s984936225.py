def main():
    import sys
    input = sys.stdin.read
    data = input().splitlines()
    
    N, M = map(int, data[0].split())
    Inf = 1 << 62
    
    a = [0] * M
    b = [0] * M
    c = [0] * M
    
    for i in range(M):
        a[i], b[i], c[i] = map(int, data[i + 1].split())
        c[i] = -c[i]
    
    dist = [Inf] * N
    dist[0] = 0
    
    for loop in range(N):
        for i in range(M):
            if dist[a[i] - 1] == Inf:
                continue
            if dist[b[i] - 1] > dist[a[i] - 1] + c[i]:
                dist[b[i] - 1] = dist[a[i] - 1] + c[i]
    
    ans = dist[N - 1]
    navigate = [False] * N
    
    for loop in range(N):
        for i in range(M):
            if dist[a[i] - 1] == Inf:
                continue
            if dist[b[i] - 1] > dist[a[i] - 1] + c[i]:
                dist[b[i] - 1] = dist[a[i] - 1] + c[i]
                navigate[b[i] - 1] = True
            if navigate[a[i] - 1]:
                navigate[b[i] - 1] = True
    
    if navigate[N - 1]:
        print("inf")
    else:
        print(-ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
