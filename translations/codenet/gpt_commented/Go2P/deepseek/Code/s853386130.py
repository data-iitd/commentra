mod = 1000000007
INF = 1000000007

def main():
    # Initialize a buffered reader to read input
    import sys
    input = sys.stdin.readline
    
    # Read the number of nodes (n), edges (m), and the number of required nodes (R)
    n, m, R = map(int, input().split())
    
    # Read the required nodes and adjust for 0-based indexing
    rs = list(map(lambda x: int(x) - 1, input().split()))
    
    # Initialize the cost matrix with INF values
    costs = [[INF] * n for _ in range(n)]
    for i in range(n):
        costs[i][i] = 0  # The cost to reach itself is 0
    
    # Read the edges and their costs
    for _ in range(m):
        a, b, c = map(int, input().split())
        a -= 1
        b -= 1
        costs[a][b] = c  # Set cost for edge a to b
        costs[b][a] = c  # Set cost for edge b to a (undirected graph)
    
    # Calculate the shortest paths using the Floyd-Warshall algorithm
    for k in range(n):
        for i in range(n):
            for j in range(n):
                costs[i][j] = min(costs[i][j], costs[i][k] + costs[k][j])
    
    # Generate all permutations of the required nodes
    from itertools import permutations
    
    perms = permutations(rs)
    ans = INF
    
    # Evaluate each permutation to find the minimum cost path
    for perm in perms:
        tmp = 0
        for j in range(1, len(perm)):
            from_node = perm[j-1]
            to_node = perm[j]
            tmp += costs[from_node][to_node]  # Accumulate the cost of the current permutation
        ans = min(ans, tmp)  # Update the answer with the minimum cost found
    
    # Output the minimum cost
    print(ans)

# Call the main function
if __name__ == "__main__":
    main()
