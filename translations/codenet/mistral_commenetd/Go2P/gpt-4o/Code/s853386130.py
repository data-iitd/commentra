# Importing necessary packages
import sys
from itertools import permutations

# Global variables initialization
mod = 1000000007
INF = 1000000007

def main():
    # Reading input from standard input
    input = sys.stdin.read
    data = input().split()
    
    # Variables initialization
    index = 0
    n = int(data[index])  # Reading number of cities n
    index += 1
    m = int(data[index])  # Reading number of roads m
    index += 1
    R = int(data[index])  # Reading number of starting points R
    index += 1

    # Initializing rs list with starting points
    rs = []
    for i in range(R):
        rs.append(int(data[index]) - 1)  # Reading starting point i and decreasing index for matrix indexing
        index += 1

    # Initializing costs matrix with infinite values
    costs = [[INF] * n for _ in range(n)]
    for i in range(n):
        costs[i][i] = 0  # Initializing costs[i][i] with zero value

    # Reading roads and filling costs matrix with their costs
    for i in range(m):
        a = int(data[index]) - 1  # Reading road starting point a
        index += 1
        b = int(data[index]) - 1  # Reading road ending point b
        index += 1
        c = int(data[index])  # Reading road cost c
        index += 1
        costs[a][b] = c  # Filling costs[a][b] with cost c
        costs[b][a] = c  # Filling costs[b][a] with cost c

    # Applying Warshall-Floyd algorithm to find shortest paths between all pairs of cities
    for k in range(n):
        for i in range(n):
            for j in range(n):
                costs[i][j] = min(costs[i][j], costs[i][k] + costs[k][j])  # Updating costs[i][j]

    # Calculating minimum cost of visiting all cities in a single tour
    ans = INF  # Initializing answer with infinite value
    for perm in permutations(rs):  # Generating all permutations of starting points
        tmp = 0  # Initializing temporary variable tmp with zero value
        for j in range(1, len(perm)):  # Iterating through all pairs of consecutive starting points
            from_city = perm[j - 1]  # Getting previous starting point
            to_city = perm[j]  # Getting current starting point
            tmp += costs[from_city][to_city]  # Adding cost of road from from_city to to_city
        ans = min(ans, tmp)  # Updating answer with minimum of current answer and tmp

    print(ans)  # Printing answer

if __name__ == "__main__":
    main()

# <END-OF-CODE>
