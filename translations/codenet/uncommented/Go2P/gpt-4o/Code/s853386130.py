import sys
from itertools import permutations

mod = 1000000007
INF = 1000000007

def main():
    input = sys.stdin.read
    data = input().split()
    
    idx = 0
    n = int(data[idx]); idx += 1
    m = int(data[idx]); idx += 1
    R = int(data[idx]); idx += 1

    rs = [int(data[idx + i]) - 1 for i in range(R)]
    idx += R

    costs = [[INF] * n for _ in range(n)]
    for i in range(n):
        costs[i][i] = 0

    for _ in range(m):
        a = int(data[idx]) - 1; idx += 1
        b = int(data[idx]) - 1; idx += 1
        c = int(data[idx]); idx += 1
        costs[a][b] = c
        costs[b][a] = c

    # Floyd-Warshall algorithm to calculate shortest paths
    for k in range(n):
        for i in range(n):
            for j in range(n):
                costs[i][j] = min(costs[i][j], costs[i][k] + costs[k][j])

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
