# Importing necessary packages
import sys
import itertools

# Global variables initialization
mod = 1000000007
INF = 1000000007

# Reading input from standard input
input_lines = sys.stdin.readlines()
n, m, R = map(int, input_lines[0].split())
rs = list(map(int, input_lines[1].split()))
rs = [x - 1 for x in rs]  # Decreasing starting point index for matrix indexing

# Initializing costs matrix with infinite values
costs = [[INF] * n for _ in range(n)]
for i in range(n):
    costs[i][i] = 0  # Initializing costs[i][i] with zero value

# Reading roads and filling costs matrix with their costs
road_data = input_lines[2:]
for line in road_data:
    a, b, c = map(int, line.split())
    a -= 1  # Decreasing starting point index for matrix indexing
    b -= 1  # Decreasing ending point index for matrix indexing
    costs[a][b] = c  # Filling costs[a][b] with cost c
    costs[b][a] = c  # Filling costs[b][a] with cost c

# Applying Warshall-Floyd algorithm to find shortest paths between all pairs of cities
for k in range(n):
    for i in range(n):
        for j in range(n):
            costs[i][j] = min(costs[i][j], costs[i][k] + costs[k][j])  # Updating costs[i][j] with minimum of current value and costs[i][k] + costs[k][j]

# Calculating minimum cost of visiting all cities in a single tour
perms = list(itertools.permutations(rs))  # Generating all permutations of starting points
ans = INF  # Initializing answer with infinite value
for perm in perms:  # Iterating through all permutations
    tmp = 0  # Initializing temporary variable tmp with zero value
    for j in range(1, len(perm)):  # Iterating through all pairs of consecutive starting points
        from_ = perm[j - 1]  # Getting previous starting point
        to_ = perm[j]  # Getting current starting point
        tmp += costs[from_][to_]  # Adding cost of road from from to to tmp
    ans = min(ans, tmp)  # Updating answer with minimum of current answer and tmp

# Printing answer
print(ans)
