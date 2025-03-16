
import sys

# Define the maximum number of nodes and the distance array
n = 100000
d = [1000000] * n

# Read the number of nodes and connections
n = int(input())
a = []
for i in range(n):
    u, k = map(int, input().split())
    for j in range(k):
        go, cost = map(int, input().split())
        a.append((u, go, cost))

# Function to initialize distances and update them based on connections
def root(b):
    flag = True
    while flag:
        flag = False
        for i in range(b):
            if d[a[i][0]] + a[i][2] < d[a[i][1]]:
                d[a[i][1]] = d[a[i][0]] + a[i][2]
                flag = True

# Call the root function to initialize distances
root(len(a))

# Print the shortest distances from the root node to each node
for i in range(n):
    print(i, d[i])

