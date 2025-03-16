

import sys
from typing import List

def max_matching(graph: List[List[int]], visited: List[bool], v: int) -> int:
    """
    Function to find the maximum number of edges that can be matched in a bipartite graph
    """
    a = 0  # Number of edges matched from the neighboring vertices of 'v'
    o = 0  # Number of vertices that have odd degree (unmatched vertices) in the neighboring vertices of 'v'

    for w in graph[v]:
        if not visited[w]:
            visited[w] = True
            r = max_matching(graph, visited, w)
            a += r // 2
            o += r % 2

    return 2 * a + min(1, o)

def main():
    """
    Main function to read input and print the result
    """
    # Reading the number of vertices in the graph
    n = int(input())

    # Initializing the graph as a list of lists
    graph = [[] for _ in range(n)]

    # Reading the edges and adding them to the graph
    for _ in range(n - 1):
        a, b = map(int, input().split())
        graph[a - 1].append(b - 1)
        graph[b - 1].append(a - 1)

    # Creating a visited array to keep track of visited vertices
    visited = [False] * n

    # Finding the maximum number of edges that can be matched in the graph
    max_matching = max_matching(graph, visited, 0) // 2

    # Printing the result based on whether all vertices have even degree or not
    print("Second" if 2 * max_matching == n else "First")

if __name__ == "__main__":
    main()

