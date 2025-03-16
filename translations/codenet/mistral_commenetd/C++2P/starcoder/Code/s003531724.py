# Define a structure to represent an edge in the graph
class edge:
    def __init__(self, to, pre, c):
        self.to = to
        self.pre = pre
        self.c = c

# Define some variables and arrays for storing information about the graph
n, m = map(int, input().split())
e = [edge(0, 0, 0) for i in range(n << 1)]
u = [0 for i in range(n + 1)]
l = 0
vis = [False for i in range(n + 1)]
cnt = [0 for i in range(3)]
d = [0 for i in range(n + 1)]
T = 0

# Define a function to perform a depth-first search of the graph
def dfs(x, l):
    vis[x] = True
    cnt[l] += 1
    d[x] = l
    for i in range(u[x]):
        T += 1
        if not vis[e[i].to]: dfs(e[i].to, (l + e[i].c) % 3)
        else:
            if ((l + e[i].c) % 3!= d[e[i].to]):
                ok = False
    return

# Define the main function to read the input and compute the answer
def main():
    ans = 0
    for i in range(1, n + 1):
        if not vis[i]:
            T = 0
            for j in range(3):
                cnt[j] = 0
            ok = True
            dfs(i, 0)
            s = cnt[0] + cnt[1] + cnt[2]
            if not ok:
                ans += s * s
            else:
                if cnt[0] and cnt[1] and cnt[2]:
                    ans += cnt[0] * cnt[1] + cnt[1] * cnt[2] + cnt[2] * cnt[0]
                else:
                    ans += T / 2
    print(ans)

# Call the main function
main()

# 