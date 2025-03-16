# Define direction vectors for 4 possible movements (right, down, left, up)
dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]

# Define constants for maximum vertices and modulo value
MAX_V = 100001
MOD = 1000000007

# Define a type for a graph represented as an adjacency list
Graph = list[list[int]]

def main():
    # Read the number of vertices (or nodes)
    n = int(input())

    # Initialize a list to store the count of edges for each vertex
    ans = [0] * n

    # Read n-1 edges and count the occurrences for each vertex
    for i in range(n - 1):
        a = int(input())  # Read the vertex index
        a -= 1  # Convert to 0-based index
        ans[a] += 1  # Increment the count for the corresponding vertex

    # Output the count of edges for each vertex
    for i in range(n):
        print(ans[i])  # Print the count for vertex i

# Call the main function
main()
