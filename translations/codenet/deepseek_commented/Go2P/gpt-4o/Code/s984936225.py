import sys

def main():
    N, M = map(int, sys.stdin.readline().split())  # Read the number of vertices (N) and the number of edges (M)

    Inf = 1 << 62  # Set Inf to 2^62, representing a large number
    a = [0] * M
    b = [0] * M
    c = [0] * M
    for i in range(M):
        a[i], b[i], c[i] = map(int, sys.stdin.readline().split())  # Read the start vertex, end vertex, and cost of each edge
        c[i] = -c[i]  # Negate the cost for the Bellman-Ford algorithm

    dist = [Inf] * N  # Initialize the dist array to store the minimum cost to reach each vertex
    dist[0] = 0  # The starting vertex has a cost of 0

    # Bellman-Ford Algorithm
    for loop in range(N):
        for i in range(M):
            if dist[a[i] - 1] == Inf:
                continue  # Skip if the start vertex is at infinite distance
            if dist[b[i] - 1] > dist[a[i] - 1] + c[i]:
                # Update the distance if a shorter path is found
                dist[b[i] - 1] = dist[a[i] - 1] + c[i]

    ans = dist[N - 1]  # The minimum cost to reach the last vertex
    navigate = [False] * N

    # Negative Cycle Detection
    for loop in range(N):
        for i in range(M):
            if dist[a[i] - 1] == Inf:
                continue  # Skip if the start vertex is at infinite distance
            if dist[b[i] - 1] > dist[a[i] - 1] + c[i]:
                dist[b[i] - 1] = dist[a[i] - 1] + c[i]
                navigate[b[i] - 1] = True  # Mark the end vertex as part of a negative cycle
            if navigate[a[i] - 1]:
                navigate[b[i] - 1] = True  # Propagate the negative cycle

    if navigate[N - 1]:
        print("inf")  # Print "inf" if a negative cycle is detected
    else:
        print(-ans)  # Print the negative of the minimum cost to reach the last vertex

if __name__ == "__main__":
    main()

# <END-OF-CODE>
