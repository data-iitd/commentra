MAX = 101
WHITE = 0
BLACK = 2
GRAY = 1

time = 0
n = 0
g = [[0] * MAX for _ in range(MAX)]
d = [0] * MAX
f = [0] * MAX
color = [WHITE] * MAX

def visit(u):
    global time
    color[u] = GRAY
    d[u] = time + 1
    time += 1

    for i in range(n):
        if g[u][i] == 0:
            continue
        if color[i] == WHITE:
            visit(i)

    color[u] = BLACK
    f[u] = time + 1
    time += 1

def dfs():
    global time
    time = 0

    for i in range(n):
        if color[i] == WHITE:
            visit(i)

    for i in range(n):
        print(f"{i + 1} {d[i]} {f[i]}")

if __name__ == "__main__":
    n = int(input())

    for i in range(n):
        x, y = map(int, input().split())
        for j in range(y):
            z = int(input())
            g[x - 1][z - 1] = 1

    dfs()
