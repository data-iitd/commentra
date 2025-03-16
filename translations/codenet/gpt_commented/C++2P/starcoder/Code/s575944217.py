
# Define long long type for convenience
from sys import stdin, stdout

# Define constants for maximum vertices and modulo value
MAX_V = 100001
MOD = 1000000007

# Define a type for a graph represented as an adjacency list
Graph = list[list[int]]

# Read the number of vertices (or nodes)
n = int(stdin.readline())

# Initialize a vector to store the count of edges for each vertex
ans = [0] * n

# Read n-1 edges and count the occurrences for each vertex
for i in range(n - 1):
    a = int(stdin.readline())
    a -= 1
    ans[a] += 1

# Output the count of edges for each vertex
for i in range(n):
    stdout.write(str(ans[i]) + '\n')

# 