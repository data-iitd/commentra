
import heapq

n, m = map(int, input().split())
a = list(map(int, input().split()))
heapq.heapify(a)
for _ in range(m):
    x = heapq.heappop(a)
    heapq.heappush(a, x // 2)
print(sum(a))

