
import sys
from collections import deque

def max_matching(graph, start):
    visited = [False] * len(graph)
    stack = deque([start])
    matching = 0
    while stack:
        node = stack.pop()
        if not visited[node]:
            visited[node] = True
            for neighbor in graph[node]:
                if not visited[neighbor]:
                    stack.append(neighbor)
                    stack.append(node)
                    matching += 1
                    break
    return matching

def main():
    n = int(input())
    graph = [[] for _ in range(n)]
    for _ in range(n - 1):
        a, b = map(int, input().split())
        graph[a - 1].append(b - 1)
        graph[b - 1].append(a - 1)
    m = max_matching(graph, 0)
    print("Second" if m * 2 == n else "First")

if __name__ == "__main__":
    sys.exit(main())

END-OF-CODE