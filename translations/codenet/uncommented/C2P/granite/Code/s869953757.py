
import sys

M = 100
whi = 0
gra = 1
bla = 2

n = int(input())
T = [[0 for _ in range(n)] for _ in range(n)]
color = [whi for _ in range(n)]
d = [1000000 for _ in range(n)]
Q = [0 for _ in range(M)]
head = 0
tail = 0

def enqueue(x):
    global Q, head, tail
    Q[tail] = x
    tail = (tail+1)%M

def dequeue():
    global Q, head, tail
    x = Q[head]
    head = (head+1)%M
    return x

def bfs(s):
    global n, T, color, d, head, tail
    for i in range(n):
        color[i] = whi
        d[i] = 1000000
    color[s] = gra
    d[s] = 0
    enqueue(s)
    while head!= tail:
        u = dequeue()
        for v in range(n):
            if T[u][v] == 1 and color[v] == whi:
                color[v] = gra
                d[v] = d[u]+1
                enqueue(v)
    for i in range(n):
        if d[i] == 1000000:
            d[i] = -1
        print(f"{i+1} {d[i]}")

for i in range(n):
    u, k = map(int, input().split())
    u -= 1
    for j in range(k):
        v = int(input())
        v -= 1
        T[u][v] = 1

bfs(0)

print("