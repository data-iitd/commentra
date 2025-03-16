import sys

N = 100000
INF = 1000000

# Define a class to store connection details
class Date:
    def __init__(self, go, back, cost):
        self.go = go
        self.back = back
        self.cost = cost

# Define the maximum number of nodes and the distance array
n = 0
d = [INF] * N
a = []

def root(b):
    global d
    flag = True

    # Initialize all distances to INF except the root node (node 0)
    d[0] = 0

    # Use a while loop to update distances based on connections
    while flag:
        flag = False
        for i in range(b):
            if a[i].cost + d[a[i].back] < d[a[i].go]:
                d[a[i].go] = a[i].cost + d[a[i].back]
                flag = True

if __name__ == "__main__":
    # Read the number of nodes
    n = int(sys.stdin.readline().strip())

    # Read each node's connections and store them in the list 'a'
    for i in range(n):
        u, k = map(int, sys.stdin.readline().strip().split())
        for j in range(k):
            go, cost = map(int, sys.stdin.readline().strip().split())
            a.append(Date(go, u, cost))

    # Call the root function to initialize distances
    root(len(a))

    # Print the shortest distances from the root node to each node
    for i in range(n):
        print(i, d[i])

# <END-OF-CODE>
