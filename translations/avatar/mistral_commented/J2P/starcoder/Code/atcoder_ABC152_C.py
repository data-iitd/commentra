import heapq

def solve():
    N = int(input())
    arr = [int(x) for x in input().split()]
    sum = 0
    q = []
    for i in range(N):
        heapq.heappush(q, arr[i])
        if arr[i] <= q[0]:
            sum += 1
    return sum

print(solve())

