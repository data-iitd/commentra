import sys

# Define the maximum number of nodes and the distance array
N = 100000
INF = 1000000

# Define a class to store connection details
class Date:
    def __init__(self, go, back, cost):
        self.go = go
        self.back = back
        self.cost = cost

# Read the number of nodes
n = int(input().strip())

# Initialize the distance array and the list of connections
d = [INF] * N
a = []

# Read each node's connections and store them in the list 'a'
for _ in range(n):
    u, k = map(int, input().strip().split())
    for _ in range(k):
        go, cost = map(int, input().strip().split())
        a.append(Date(go, u, cost))

# Initialize distances and update them based on connections
d[0] = 0
flag = 1
while flag != 0:
    flag = 0
    for connection in a:
        if d[connection.back] + connection.cost < d[connection.go]:
            d[connection.go] = d[connection.back] + connection.cost
            flag = 1

# Print the shortest distances from the root node to each node
for i in range(n):
    print(f"{i} {d[i]}")

