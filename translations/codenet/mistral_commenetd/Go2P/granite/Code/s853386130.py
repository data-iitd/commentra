
# Importing necessary packages
import sys
from itertools import permutations

# Global variables initialization
mod = 1000000007
INF = 1000000007

def main():
    # Reading input from standard input
    r = sys.stdin.readlines()
    # Variables initialization
    n, m, R = map(int, r[0].split())
    rs = list(map(lambda x: int(x)-1, r[1].split()))
    costs = [[INF for _ in range(n)] for _ in range(n)]
    for i in range(n):
        costs[i][i] = 0
    for i in range(2, len(r)):
        a, b, c = map(int, r[i].split())
        a -= 1
        b -= 1
        costs[a][b] = c
        costs[b][a] = c
    for k in range(n):
        for i in range(n):
            for j in range(n):
                costs[i][j] = min(costs[i][j], costs[i][k]+costs[k][j])
    perms = permutations(rs)
    ans = INF
    for perm in perms:
        tmp = 0
        for j in range(1, len(perm)):
            from_ = perm[j-1]
            to = perm[j]
            tmp += costs[from_][to]
        ans = min(ans, tmp)
    print(ans)

if __name__ == "__main__":
    main()

