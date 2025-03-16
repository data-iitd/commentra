# Define a structure to store connection details
class Date:
    def __init__(self, go, back, cost):
        self.go = go
        self.back = back
        self.cost = cost

# Define the maximum number of nodes and the distance array
n = 100000
d = [INF] * n

# Declare the root function
def root(b):
    # Declare variables for iteration and input
    i, flag = 0, 1

    # Initialize all distances to INF except the root node (node 0)
    for i in range(n):
        d[i] = INF
    d[0] = 0

    # Use a while loop to update distances based on connections
    while flag!= 0:
        flag = 0
        for i in range(b):
            if a[i].cost + d[a[i].back] < d[a[i].go]:
                d[a[i].go] = a[i].cost + d[a[i].back]
                flag = 1

# Read the number of nodes
n = int(input())

# Read each node's connections and store them in the array 'a'
a = []
for i in range(n):
    u, k = map(int, input().split())
    for j in range(k):
        go, cost = map(int, input().split())
        a.append(Date(go, u, cost))

# Call the root function to initialize distances
root(len(a))

# Print the shortest distances from the root node to each node
for i in range(n):
    print(i, d[i])

# 