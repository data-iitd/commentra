import sys
from itertools import permutations

mod = 1000000007
INF = 1000000007

def main():
    # Read the number of nodes (n), edges (m), and the number of required nodes (R)
    n = int(sys.stdin.readline().strip())
    m = int(sys.stdin.readline().strip())
    R = int(sys.stdin.readline().strip())

    # Read the required nodes and adjust for 0-based indexing
    rs = list(map(int, sys.stdin.readline().strip().split()))
    rs = [r - 1 for r in rs]

    # Initialize the cost matrix with INF values
    costs = [[INF] * n for _ in range(n)]
    for i in range(n):
        costs[i][i] = 0  # The cost to reach itself is 0

    # Read the edges and their costs
    for _ in range(m):
        a, b, c = map(int, sys.stdin.readline().strip().split())
        a -= 1
        b -= 1
        costs[a][b] = c  # Set cost for edge a to b
        costs[b][a] = c  # Set cost for edge b to a (undirected graph)

    # Calculate the shortest paths using the Floyd-Warshall algorithm
    for k in range(n):
        for i in range(n):
            for j in range(n):
                costs[i][j] = min(costs[i][j], costs[i][k] + costs[k][j])

    # Evaluate each permutation to find the minimum cost path
    ans = INF
    for perm in permutations(rs):
        tmp = 0
        for j in range(1, len(perm)):
            from_node = perm[j - 1]
            to_node = perm[j]
            tmp += costs[from_node][to_node]  # Accumulate the cost of the current permutation
        ans = min(ans, tmp)  # Update the answer with the minimum cost found

    # Output the minimum cost
    print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
