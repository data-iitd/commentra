
# Input the number of vertices
n = int(input())

# Initialize an answer vector of size n
ans = [0]*n

# Read the edges and increment the count of each vertex in the answer vector
for i in range(n-1):
    a = int(input())
    a -= 1 # Decrement the vertex index as it is 0-indexed
    ans[a] += 1 # Increment the count of the vertex

# Print the answer vector
for i in range(n):
    print(ans[i])

