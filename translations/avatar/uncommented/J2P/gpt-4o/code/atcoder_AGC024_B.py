def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    N = int(data[0])
    P = [int(data[i]) - 1 for i in range(1, N + 1)]
    
    map = {}
    for i in range(N):
        map[P[i]] = i
    
    nglist = []
    for i in range(N - 1):
        if map[i] > map[i + 1]:
            nglist.append(i)
    
    if not nglist:
        print(0)
        return
    
    ans = min(N - nglist[0] - 1, nglist[-1] + 1)
    for i in range(len(nglist) - 1):
        ans = min(nglist[i] + 1 + N - nglist[i + 1] - 1, ans)
    
    print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
