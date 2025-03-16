
# define MAX 101
# define WHITE 0
# define BLACK 2
# define GRAY 1
time = 0
n = 0
g = [[0 for i in range(MAX)] for j in range(MAX)]
d = [0 for i in range(MAX)]
f = [0 for i in range(MAX)]
color = [WHITE for i in range(MAX)]

def visit(u):
    global time
    global n
    global g
    global d
    global f
    global color
    color[u] = GRAY
    d[u] = time
    time += 1
    for i in range(n):
        if g[u][i] == 0:
            continue
        if color[i] == WHITE:
            visit(i)
    color[u] = BLACK
    f[u] = time
    time += 1

def dfs():
    global time
    global n
    global g
    global d
    global f
    global color
    time = 0
    for i in range(n):
        if color[i] == WHITE:
            visit(i)
    for i in range(n):
        print(i+1, d[i], f[i])

def main():
    global time
    global n
    global g
    global d
    global f
    global color
    time = 0
    n = 0
    g = [[0 for i in range(MAX)] for j in range(MAX)]
    d = [0 for i in range(MAX)]
    f = [0 for i in range(MAX)]
    color = [WHITE for i in range(MAX)]
    x = 0
    y = 0
    z = 0
    i = 0
    j = 0
    while True:
        x = int(input())
        if x == 0:
            break
        n = x
        for i in range(n):
            x, y = map(int, input().split())
            for j in range(y):
                z = int(input())
                g[x-1][z-1] = 1
        dfs()

main()
print("