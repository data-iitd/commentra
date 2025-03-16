M = 100
whi = 0
gra = 1
bla = 2

n = 0
T = [[0] * M for _ in range(M)]
color = [0] * M
d = [0] * M
Q = []
head = 0
tail = 0

def enqueue(x):
    global tail
    Q.append(x)
    tail += 1

def dequeue():
    global head
    x = Q[head]
    head += 1
    return x

def bfs(s):
    global head, tail
    for i in range(n):
        color[i] = whi
        d[i] = 1000000

    color[s] = gra
    d[s] = 0
    enqueue(s)

    while head < tail:
        u = dequeue()
        for v in range(n):
            if T[u][v] == 1 and color[v] == whi:
                color[v] = gra
                d[v] = d[u] + 1
                enqueue(v)
        color[u] = bla

if __name__ == "__main__":
    n = int(input())

    for i in range(n):
        for j in range(n):
            T[i][j] = 0

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

# <END-OF-CODE>
