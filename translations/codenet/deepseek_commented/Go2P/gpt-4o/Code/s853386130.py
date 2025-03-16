import sys
from itertools import permutations

# Constants for the modulo operation and infinity value
mod = 1000000007
INF = 1000000007

def main():
    # Read the number of cities, roads, and restaurants
    n = int(sys.stdin.readline().strip())
    m = int(sys.stdin.readline().strip())
    R = int(sys.stdin.readline().strip())

    # Read the indices of the restaurants and decrement by 1 for 0-based indexing
    rs = list(map(int, sys.stdin.readline().strip().split()))
    rs = [r - 1 for r in rs]

    # Initialize the cost matrix with INF and set diagonal to 0
    costs = [[INF] * n for _ in range(n)]
    for i in range(n):
        costs[i][i] = 0

    # Read the road connections and their costs, updating the cost matrix
    for _ in range(m):
        a, b, c = map(int, sys.stdin.readline().strip().split())
        a -= 1
        b -= 1
        costs[a][b] = c
        costs[b][a] = c

    # Use the Floyd-Warshall algorithm to compute the shortest paths between all pairs of cities
    for k in range(n):
        for i in range(n):
            for j in range(n):
                costs[i][j] = min(costs[i][j], costs[i][k] + costs[k][j])

    # Generate all permutations of the restaurant indices and find the minimum cost tour
    ans = INF
    for perm in permutations(rs):
        tmp = 0
        for j in range(1, len(perm)):
            from_city = perm[j - 1]
            to_city = perm[j]
            tmp += costs[from_city][to_city]
        ans = min(ans, tmp)

    print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
