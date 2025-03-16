class Edge:  # Class to represent an edge
    def __init__(self, id, to):  # Constructor to initialize the edge with its id and the vertex it connects to
        self.id = id
        self.to = to

def dfs(to, color, parents):  # Function to perform Depth First Search
    global k
    k = 1  # Initializing the color to 1
    for e in g[to]:  # Looping through each edge adjacent to the current vertex
        if e.to == parents:
            continue  # Skipping the edge if it is already colored with the current color
        if k == color:
            k += 1  # Incrementing the color if the current vertex is already colored with the same color
        ans[e.id] = k  # Storing the answer in the array
        dfs(e.to, k, to)  # Recursively calling the DFS function for the adjacent vertex
        k += 1  # Incrementing the color for the next vertex

n = int(input())  # Reading the number of vertices from the input
g = [[] for _ in range(n)]  # Creating an empty list to store the graph
for i in range(n - 1):  # Looping through each edge to add it to the graph
    a, b = map(int, input().split())  # Reading the vertices of the edge
    a -= 1  # Adjusting for 0-based index
    b -= 1  # Adjusting for 0-based index
    g[a].append(Edge(i, b))  # Adding the edge from vertex 'a' to 'b'
    g[b].append(Edge(i, a))  # Adding the edge from vertex 'b' to 'a'

ans = [0] * (n - 1)  # Creating an array of size 'n-1' to store the answer
k = -1  # Initialize k for the DFS
dfs(0, -1, -1)  # Calling the DFS function to find the answer

max_ans = max(ans)  # Finding the maximum answer
print(max_ans)  # Printing the maximum answer
for c in ans:  # Printing all the answers
    print(c)

# <END-OF-CODE>
