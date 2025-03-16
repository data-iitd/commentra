
from collections import deque

n, q = map(int, input().split())
Q = deque()
elaps = 0

for i in range(n):
    name, time = input().split()
    Q.append((name, int(time)))

while Q:
    name, time = Q.popleft()
    if time <= q:
        elaps += time
        print(name, elaps)
    else:
        time -= q
        elaps += q
        Q.append((name, time))
