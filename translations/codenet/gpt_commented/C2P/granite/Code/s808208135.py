
import sys

N = 100000  # Define a constant for the maximum number of nodes
INF = 1000000  # Define a constant for representing infinity

# Structure to represent a directed edge with a cost
class Date:
    def __init__(self, go, back, cost):
        self.go = go  # Destination node
        self.back = back  # Source node
        self.cost = cost  # Cost of the edge

n = int(input())  # Read the number of nodes
a = []  # List to store edges
for i in range(n):
    u, k = map(int, input().split())  # Read the current node and number of edges
    for j in range(k):
        back, go, cost = map(int, input().split())  # Read destination, source, and cost
        a.append(Date(go, back, cost))  # Append the edge to the list

def root(b):
    d = [INF] * n  # Initialize distances to all nodes as infinity
    d[0] = 0  # Set the distance to the source node (node 0) as 0
    flag = True  # Flag to indicate changes
    while flag:
        flag = False  # Reset flag for this iteration
        # Relax all edges
        for i in range(b):
            # Check if the current edge can provide a shorter path
            if a[i].cost + d[a[i].back] < d[a[i].go]:
                d[a[i].go] = a[i].cost + d[a[i].back]  # Update the shortest distance
                flag = True  # Set flag to indicate a change occurred
    return d

d = root(len(a))  # Compute shortest paths

# Print the shortest distances from the source node to each node
for i in range(n):
    print(f"{i} {d[i]}")  # Output the node index and its distance

