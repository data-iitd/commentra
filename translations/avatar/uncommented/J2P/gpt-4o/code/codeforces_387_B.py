def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    n = int(data[0])
    m = int(data[1])
    
    req = []
    pre = []
    
    for i in range(n):
        req.append(int(data[2 + i]))
    
    for i in range(m):
        pre.append(int(data[2 + n + i]))
    
    i = n - 1
    j = m - 1
    ans = 0
    
    while i >= 0 and j >= 0:
        if req[i] > pre[j]:
            ans += 1
        else:
            j -= 1
        i -= 1
    
    print(ans + i + 1)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
