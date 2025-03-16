
import sys
import math

def main():
    # Initialize a buffered reader to read input
    r = sys.stdin

    # Read the number of nodes (n), edges (m), and the number of required nodes (R)
    n, m, R = map(int, r.readline().split())

    # Read the required nodes and adjust for 0-based indexing
    rs = [int(r.readline()) - 1 for i in range(R)]

    # Initialize the cost matrix with INF values
    costs = [[INF for j in range(n)] for i in range(n)]
    for i in range(n):
        costs[i][i] = 0 # The cost to reach itself is 0

    # Read the edges and their costs
    for i in range(m):
        a, b, c = map(int, r.readline().split())
        a -= 1
        b -= 1
        costs[a][b] = c # Set cost for edge a to b
        costs[b][a] = c # Set cost for edge b to a (undirected graph)

    # Calculate the shortest paths using the Floyd-Warshall algorithm
    for k in range(n):
        for i in range(n):
            for j in range(n):
                costs[i][j] = min(costs[i][j], costs[i][k] + costs[k][j])

    # Generate all permutations of the required nodes
    perms = permutations(rs)
    ans = INF

    # Evaluate each permutation to find the minimum cost path
    for perm in perms:
        tmp = 0
        for j in range(1, len(perm)):
            from = perm[j-1]
            to = perm[j]
            tmp += costs[from][to] # Accumulate the cost of the current permutation
        ans = min(ans, tmp) # Update the answer with the minimum cost found

    # Output the minimum cost
    print(ans)

def min(a, b):
    if a < b:
        return a
    return b

def permutations(arr):
    res = []

    # Recursive helper function to generate permutations
    def helper(arr, n):
        if n == 1:
            tmp = arr[:]
            res.append(tmp)
        else:
            for i in range(n):
                helper(arr, n-1)
                # Swap elements based on the parity of n
                if n % 2 == 1:
                    tmp = arr[i]
                    arr[i] = arr[n-1]
                    arr[n-1] = tmp
                else:
                    tmp = arr[0]
                    arr[0] = arr[n-1]
                    arr[n-1] = tmp

    helper(arr, len(arr))
    return res

if __name__ == "__main__":
    main()

