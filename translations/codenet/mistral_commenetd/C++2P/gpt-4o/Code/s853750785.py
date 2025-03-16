import sys
from collections import defaultdict
from math import gcd

# Constants
MOD = 10**9 + 7

def myPow(x, n, m):
    if n == 0:
        return 1
    if n % 2 == 0:
        return myPow(x * x % m, n // 2, m)
    else:
        return x * myPow(x, n - 1, m) % m

def main():
    input = sys.stdin.read
    data = input().split()
    
    N = int(data[0])  # Number of nodes
    M = int(data[1])  # Number of edges
    H = list(map(int, data[2:N+2]))  # Heights of the nodes
    
    G = defaultdict(list)  # Adjacency list to represent the graph
    
    index = N + 2
    for _ in range(M):  # Read edges
        u = int(data[index]) - 1  # Convert to 0-indexing
        v = int(data[index + 1]) - 1  # Convert to 0-indexing
        G[u].append(v)  # Add an edge from node u to node v
        G[v].append(u)  # Add a reciprocal edge from node v to node u
        index += 2
    
    ans = 0  # Initialize answer variable
    for u in range(N):  # Iterate through each node
        flag = True  # Assume that the node has a higher height than its neighbors
        for v in G[u]:
            if H[u] <= H[v]:  # If not, update the flag
                flag = False
                break
        if flag:
            ans += 1  # If the node has a higher height than its neighbors, increment the answer
    
    print(ans)  # Print the answer

if __name__ == "__main__":
    main()

# <END-OF-CODE>
