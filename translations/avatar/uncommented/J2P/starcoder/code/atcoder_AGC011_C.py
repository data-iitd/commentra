
class Main:
    def __init__(self):
        self.graph = []
        self.visited = []
        self.color = []
        self.one = 0
        self.bipartite = 0
        self.count = 0
        self.mujun = False

    def dfs(self, a, c):
        if self.visited[a]:
            if self.color[a] >= 0 and self.color[a]!= c:
                self.mujun = True
            return 0
        self.visited[a] = True
        self.color[a] = c
        total = 1
        for b in self.graph[a]:
            total += self.dfs(b, 1 - c)
        return total

    def run(self):
        scan = Scanner(System.in)
        n = scan.nextInt()
        m = scan.nextInt()
        self.graph = [[] for _ in range(n)]
        for i in range(m):
            u = scan.nextInt() - 1
            v = scan.nextInt() - 1
            self.graph[u].append(v)
            self.graph[v].append(u)
        self.visited = [False for _ in range(n)]
        self.color = [-1 for _ in range(n)]
        Arrays.fill(self.color, -1)
        self.one = 0
        self.bipartite = 0
        self.count = 0
        for i in range(n):
            if self.visited[i]:
                continue
            self.count += 1
            self.mujun = False
            kind = self.dfs(i, 0)
            if kind == 1:
                self.one += 1
            elif not self.mujun:
                self.bipartite += 1
        total = self.one * (2 * n - self.one)
        total += (self.count - self.one) * (self.count - self.one)
        total += self.bipartite * self.bipartite
        System.out.println(total)


# 