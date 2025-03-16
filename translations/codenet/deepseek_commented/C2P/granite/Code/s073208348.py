
import sys
input = sys.stdin.readline

# Define a function to read the graph
def readgraph():
    n = int(input())
    edges = []
    for _ in range(n):
        x, y, c = map(int, input().split())
        edges.append((x, y, c))
    return n, edges

# Define a function to find the diameter of the tree
def tyokkei(n, edges):
    edges.sort(key=lambda x: x[0])
    id = [0] * (n + 1)
    p = 0
    for i in range(n):
        while p < len(edges) and edges[p][0] < i:
            p += 1
        id[i] = p
    id[n] = len(edges)
    tyokkeitemp = [0] * (n + 10)
    tyokkeitemp[0] = 1
    def tyokkeidfs(s):
        for i in range(id[s], id[s + 1]):
            if tyokkeitemp[edges[i][1]] == 0:
                tyokkeitemp[edges[i][1]] = tyokkeitemp[s] + edges[i][2]
                tyokkeidfs(edges[i][1])
    tyokkeidfs(0)
    M = 0
    Mi = 0
    for i in range(n):
        if tyokkeitemp[i] > M:
            M = tyokkeitemp[i]
            Mi = i
    tyokkeitemp = [0] * (n + 10)
    tyokkeitemp[Mi] = 1
    tyokkeidfs(Mi)
    for i in range(n):
        M = max(M, tyokkeitemp[i])
    return M - 1

# Main function
if __name__ == "__main__":
    n, edges = readgraph()
    print(tyokkei(n, edges))

