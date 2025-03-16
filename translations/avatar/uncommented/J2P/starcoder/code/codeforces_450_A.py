
import sys
import queue

n, m = map(int, sys.stdin.readline().split())
q1 = queue.Queue()
q2 = queue.Queue()
for i in range(1, n+1):
    q1.put(int(sys.stdin.readline()))
    q2.put(i)
ans = 0
while not q1.empty():
    if q1.queue[0] <= m:
        q1.get()
        ans = q2.get()
    elif q1.queue[0] > m:
        x = q1.get()
        val = x - m
        q1.put(val)
        val2 = q2.get()
        q2.put(val2)
print(ans)

