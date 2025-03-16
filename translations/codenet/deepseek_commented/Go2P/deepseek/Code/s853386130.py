mod = 1000000007
INF = 1000000007

def main():
    # Read the number of cities, roads, and restaurants
    n, m, R = map(int, input().split())

    # Read the indices of the restaurants and decrement by 1 for 0-based indexing
    rs = list(map(lambda x: int(x) - 1, input().split()))

    # Initialize the cost matrix with INF and set diagonal to 0
    costs = [[INF] * n for _ in range(n)]
    for i in range(n):
        costs[i][i] = 0

    # Read the road connections and their costs, updating the cost matrix
    for _ in range(m):
        a, b, c = map(int, input().split())
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
    from itertools import permutations

    perms = permutations(rs)
    ans = INF
    for perm in perms:
        tmp = 0
        for j in range(1, len(perm)):
            from_ = perm[j-1]
            to_ = perm[j]
            tmp += costs[from_][to_]
        ans = min(ans, tmp)
    print(ans)

