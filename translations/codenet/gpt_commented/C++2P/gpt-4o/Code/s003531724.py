import sys
from collections import defaultdict

# Constants
N = int(1e5 + 10)

# Structure to represent an edge in the graph
class Edge:
    def __init__(self, to, pre, c):
        self.to = to  # 'to' is the destination
        self.pre = pre  # 'pre' is the previous edge
        self.c = c  # 'c' is the color

# Global variables
n, m = map(int, sys.stdin.readline().split())  # Number of vertices and edges
u = [0] * N  # Array to store the head of each vertex's adjacency list
e = []  # List to store edges
l = 0  # Edge counter
vis = [False] * N  # vis[i] indicates if vertex i has been visited
ok = True  # Indicates if the graph is valid
cnt = [0, 0, 0]  # Count of vertices in each of the three color classes
d = [0] * N  # Array to store the color of each vertex
T = 0  # Total number of vertices in the current connected component

# Function to insert an edge into the graph
def ins(a, b, c):
    global l
    e.append(Edge(b, u[a], c))  # Create a new edge
    u[a] = l  # Update the head of the adjacency list for vertex 'a'
    l += 1

# Depth-first search function to traverse the graph
def dfs(x, l):
    global ok, T
    vis[x] = True  # Mark the current vertex as visited
    cnt[l] += 1  # Increment the count for the current color class
    d[x] = l  # Assign the color to the current vertex

    # Iterate through all edges of the current vertex
    i = u[x]
    while i:
        v = e[i].to
        ec = e[i].c
        T += 1  # Increment the total count of vertices in the component
        if not vis[v]:  # If the adjacent vertex has not been visited
            dfs(v, (l + ec) % 3)  # Recursively visit it with the new color
        elif (l + ec) % 3 != d[v]:  # If the adjacent vertex is visited but has a different color
            ok = False  # Mark the component as invalid
        i = e[i].pre

# Main function
def main():
    global ok, T
    # Read edges and construct the graph
    for _ in range(m):
        a, b = map(int, sys.stdin.readline().split())  # Read each edge
        ins(a, b, 1)  # Insert edge from a to b with color 1
        ins(b, a, 2)  # Insert edge from b to a with color 2

    ans = 0  # Variable to store the final answer

    # Iterate through all vertices
    for i in range(1, n + 1):
        if not vis[i]:  # If the vertex has not been visited
            T = 0  # Reset the total count for the new component
            cnt = [0, 0, 0]  # Reset color counts
            ok = True  # Assume the component is valid
            dfs(i, 0)  # Start DFS from the current vertex with color 0
            
            # Calculate the size of the current component
            s = cnt[0] + cnt[1] + cnt[2]
            
            # If the component is invalid, add the square of its size to the answer
            if not ok:
                ans += s * s
            else:
                # If all three color classes are present, calculate combinations
                if cnt[0] and cnt[1] and cnt[2]:
                    ans += cnt[0] * cnt[1] + cnt[1] * cnt[2] + cnt[2] * cnt[0]
                else:
                    ans += T // 2  # If not all color classes are present, add half of the total vertices

    # Output the final answer
    print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
