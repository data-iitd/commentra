

# Python program to find the number of vertices connected to each vertex in a graph

# Read the number of vertices from the input
n = int(input())

# Initialize an answer list of size n
ans = [0]*n

# Read the edges and increment the count of each vertex in the answer list
for i in range(n-1):
    a = int(input())-1 # Decrement the vertex index as it is 0-indexed
    ans[a] += 1 # Increment the count of the vertex

# Print the answer list
for i in range(n):
    print(ans[i])

