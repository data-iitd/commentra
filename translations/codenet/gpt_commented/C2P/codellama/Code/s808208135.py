#include <stdio.h>
#include <stdlib.h>

#define N 100000  # Define a constant for the maximum number of nodes
#define INF 1000000  # Define a constant for representing infinity

# Structure to represent a directed edge with a cost
class Date:
    def __init__(self, go, back, cost):
        self.go = go
        self.back = back
        self.cost = cost

n, d = [0] * N, [0] * N  # n: number of nodes, d: array to store the shortest distances
a = [0] * 500000  # Array to store edges

def root(b):  # Function prototype for the root function
    i, flag = 0, 1  # Loop variable and flag to indicate changes

    # Initialize distances to all nodes as infinity
    for i in range(n):
        d[i] = INF
    d[0] = 0  # Set the distance to the source node (node 0) as 0

    # Repeat the process until no changes occur
    while flag != 0:
        flag = 0  # Reset flag for this iteration
        # Relax all edges
        for i in range(b):
            # Check if the current edge can provide a shorter path
            if a[i].cost + d[a[i].back] < d[a[i].go]:
                d[a[i].go] = a[i].cost + d[a[i].back]  # Update the shortest distance
                flag = 1  # Set flag to indicate a change occurred


def main():
    i, j, k, u, count = 0, 0, 0, 0, 0  # Loop variables and counter for edges
    scanf("%d", &n)  # Read the number of nodes

    # Read edges for each node
    for i in range(n):
        scanf("%d%d", &u, &k)  # Read the current node and number of edges
        for j in range(k):
            a[count].back = u  # Set the source node for the edge
            scanf("%d%d", &a[count].go, &a[count].cost)  # Read destination and cost
            count += 1  # Increment the edge counter

    # Call the root function to compute shortest paths
    root(count)

    # Print the shortest distances from the source node to each node
    for i in range(n):
        printf("%d %d\n", i, d[i])  # Output the node index and its distance

    return 0  # Exit the program


if __name__ == "__main__":
    main()

