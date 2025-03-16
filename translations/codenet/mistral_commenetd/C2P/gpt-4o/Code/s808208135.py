import sys

N = 100000
INF = 1000000

class Date:
    def __init__(self, go, back, cost):
        self.go = go
        self.back = back
        self.cost = cost

n = 0
d = [INF] * N
a = []  # List to store the adjacency list and cost for each edge

def root(b):  # Function to perform Dijkstra's algorithm
    global d
    flag = True  # Algorithm termination flag

    for i in range(n):  # Initialize the shortest distance array with infinite values
        d[i] = INF

    d[0] = 0  # Set the shortest distance to the source vertex to 0

    while flag:  # While there are still vertices with updated shortest distances
        flag = False  # Assume no vertices have updated shortest distances

        for i in range(b):  # Iterate through all the edges
            if a[i].cost + d[a[i].back] < d[a[i].go]:  # If the cost of the edge plus the shortest distance to the previous vertex is less than the current shortest distance
                d[a[i].go] = a[i].cost + d[a[i].back]  # Update the shortest distance to the current vertex
                flag = True  # Set the flag to indicate that there are still vertices with updated shortest distances

if __name__ == "__main__":
    n = int(sys.stdin.readline().strip())  # Read the number of vertices

    for i in range(n):  # Iterate through each vertex
        u, k = map(int, sys.stdin.readline().strip().split())  # Read the number of edges and their destinations

        for j in range(k):  # Iterate through each edge
            go, cost = map(int, sys.stdin.readline().strip().split())  # Read the destination vertex and the cost
            a.append(Date(go, u, cost))  # Set the back pointer to the current vertex and append to the list

    root(len(a))  # Call the Dijkstra's algorithm function

    for i in range(n):  # Print the shortest distance from the source to each vertex
        print(i, d[i])

# <END-OF-CODE>
