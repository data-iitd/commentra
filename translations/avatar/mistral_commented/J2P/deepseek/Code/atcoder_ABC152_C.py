def solve():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    N = int(data[0])
    arr = list(map(int, data[1:N+1]))
    
    sum = 0
    q = []
    
    for i in range(N):
        arr[i] = int(arr[i])
        q.append(arr[i])
        q.sort()
        if arr[i] <= q[0]:
            sum += 1
    
    return sum

print(solve())
