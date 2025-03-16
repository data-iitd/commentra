
import queue

M = 100
whi = 0
gra = 1
bla = 2

n = int(input())
T = [[0 for _ in range(n)] for _ in range(n)]
color = [whi for _ in range(n)]
d = [1000000 for _ in range(n)]
Q = queue.Queue()

def enqueue(x):
    Q.put(x)

def dequeue():
    return Q.get()

def bfs(s):
    i, u, v = 0, 0, 0

    for i in range(n):
        color[i] = whi
        d[i] = 1000000

    color[s] = gra
    d[s] = 0
    enqueue(s)

    while not Q.empty():
        u = dequeue()
        for v in range(n):
            if T[u][v] == 1 and color[v] == whi:
                color[v] = gra
                d[v] = d[u] + 1
                enqueue(v)
        color[u] = bla

for i in range(n):
    u, k = map(int, input().split())
    u -= 1
    for j in range(k):
        v = int(input())
        v -= 1
        T[u][v] = 1

bfs(0)

for i in range(n):
    if d[i] == 1000000:
        d[i] = -1
    print(i + 1, d[i])

print("