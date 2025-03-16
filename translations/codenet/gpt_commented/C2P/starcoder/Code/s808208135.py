# Define a constant for the maximum number of nodes
N = 100000
# Define a constant for representing infinity
INF = 1000000

# Structure to represent a directed edge with a cost
class Date:
    def __init__(self, go, back, cost):
        self.go = go
        self.back = back
        self.cost = cost

# Function to compute shortest paths using the Bellman-Ford algorithm
def root(b):
    # Initialize distances to all nodes as infinity
    d = [INF] * N
    d[0] = 0
    # Repeat the process until no changes occur
    while True:
        flag = 0  # Reset flag for this iteration
        # Relax all edges
        for i in range(b):
            # Check if the current edge can provide a shorter path
            if a[i].cost + d[a[i].back] < d[a[i].go]:
                d[a[i].go] = a[i].cost + d[a[i].back]  # Update the shortest distance
                flag = 1  # Set flag to indicate a change occurred
        if flag == 0:
            break

# Read the number of nodes
n = int(input())
# Read edges for each node
for i in range(n):
    u, k = map(int, input().split())  # Read the current node and number of edges
    for j in range(k):
        a[j] = Date(int(input()), u, int(input()))  # Read destination and cost

# Call the root function to compute shortest paths
root(k)

# Print the shortest distances from the source node to each node
for i in range(n):
    print(i, d[i])  # Output the node index and its distance

