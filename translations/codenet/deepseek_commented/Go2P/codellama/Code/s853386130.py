
import sys

def main():
    # Create a new reader to read from standard input
    r = sys.stdin

    # Read the number of cities, roads, and restaurants
    n, m, R = map(int, r.readline().split())

    # Read the indices of the restaurants and decrement by 1 for 0-based indexing
    rs = [int(x) - 1 for x in r.readline().split()]

    # Initialize the cost matrix with INF and set diagonal to 0
    costs = [[INF] * n for _ in range(n)]
    for i in range(n):
        costs[i][i] = 0

    # Read the road connections and their costs, updating the cost matrix
    for _ in range(m):
        a, b, c = map(int, r.readline().split())
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
    perms = permutations(rs)
    ans = INF
    for perm in perms:
        tmp = 0
        for j in range(1, len(perm)):
            from = perm[j - 1]
            to = perm[j]
            tmp += costs[from][to]
        ans = min(ans, tmp)
    print(ans)


def permutations(arr):
    res = []

    def helper(arr, n):
        if n == 1:
            res.append(arr[:])
        else:
            for i in range(n):
                helper(arr, n - 1)
                if n % 2 == 1:
                    tmp = arr[i]
                    arr[i] = arr[n - 1]
                    arr[n - 1] = tmp
                else:
                    tmp = arr[0]
                    arr[0] = arr[n - 1]
                    arr[n - 1] = tmp

    helper(arr, len(arr))
    return res


def min(a, b):
    if a < b:
        return a
    else:
        return b


if __name__ == "__main__":
    main()

