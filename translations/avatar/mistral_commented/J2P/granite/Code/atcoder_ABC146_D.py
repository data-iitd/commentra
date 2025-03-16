

import sys
sys.setrecursionlimit(10**6) # Setting the recursion limit to avoid stack overflow

n = int(input()) # Reading the number of vertices from the input
g = [[] for _ in range(n)] # Creating an empty list to store the graph
for _ in range(n - 1): # Looping through each edge to add it to the graph
 a, b = map(int, input().split()) # Reading the first and second vertices of the edge
 g[a - 1].append((b - 1, _)) # Adding the edge from vertex 'a' to 'b'
 g[b - 1].append((a - 1, _)) # Adding the edge from vertex 'b' to 'a'

ans = [0] * (n - 1) # Creating an array of size 'n-1' to store the answer
def dfs(to, color, parents): # Function to perform Depth First Search
 k = 1 # Initializing the color to 1
 for e in g[to]: # Looping through each edge adjacent to the current vertex
 if e[0] == parents: continue # Skipping the edge if it is already colored with the current color
 if k == color: k += 1 # Incrementing the color if the current vertex is already colored with the same color
 ans[e[1]] = k # Storing the answer in the array
 dfs(e[0], k, to) # Recursively calling the DFS function for the adjacent vertex
 k += 1 # Incrementing the color for the next vertex

dfs(0, -1, -1) # Calling the DFS function to find the answer

print(max(ans)) # Printing the maximum answer
for c in ans: # Printing all the answers
 print(c)

