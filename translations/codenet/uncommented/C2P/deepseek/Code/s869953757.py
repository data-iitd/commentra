M = 100
whi = 0
gra = 1
bla = 2

n = int(input())
T = [[0] * M for _ in range(M)]
color = [whi] * M
d = [1000000] * M
Q = [0] * M
head = 0
tail = 0

def enqueue(x):
    global tail
    Q[tail] = x
    tail = (tail + 1) % M

def dequeue():
    global head
    x = Q[head]
    head = (head + 1) % M
    return x

def bfs(s):
    color[s] = gra
    d[s] = 0
    enqueue(s)

    while head != tail:
        u = dequeue()
        for v in range(n):
            if T[u][v] == 1 and color[v] == whi:
                color[v] = gra
                d[v] = d[u] + 1
                enqueue(v)
        color[u] = bla

bfs(0)

for i in range(n):
    if d[i] == 1000000:
        d[i] = -1
    print(f"{i+1} {d[i]}")

