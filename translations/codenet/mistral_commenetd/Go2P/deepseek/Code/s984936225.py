import sys

def main():
    # Read input values for N and M
    N, M = map(int, sys.stdin.readline().split())

    # Constants and initializations
    INF = 1 << 62
    # a, b, and c are lists of size M
    a = []
    b = []
    c = []

    # Read input values for a, b, and c
    for _ in range(M):
        ai, bi, ci = map(int, sys.stdin.readline().split())
        c.append(-ci)
        a.append(ai)
        b.append(bi)

    # Initialize the dist array with the maximum value
    dist = [INF] * N
    # Set the initial distance of the source node to 0
    dist[0] = 0

    # Dijkstra's algorithm loop
    for _ in range(N):
        for i in range(M):
            # Skip if the current node's distance is still the maximum value
            if dist[a[i]-1] == INF:
                continue
            # Update the distance if the new path is shorter
            if dist[b[i]-1] > dist[a[i]-1] + c[i]:
                dist[b[i]-1] = dist[a[i]-1] + c[i]

    # Calculate the answer
    ans = dist[-1]
    navigate = [False] * N

    # Dijkstra's algorithm loop (second pass)
    for _ in range(N):
        for i in range(M):
            # Skip if the current node's distance is still the maximum value
            if dist[a[i]-1] == INF:
                continue
            # Update the distance if the new path is shorter
            if dist[b[i]-1] > dist[a[i]-1] + c[i]:
                dist[b[i]-1] = dist[a[i]-1] + c[i]
                navigate[b[i]-1] = True
            # If the previous node is in the navigate list, set the current node's navigate list value to True
            if navigate[a[i]-1]:
                navigate[b[i]-1] = True

    # Print the result
    if navigate[-1]:
        print("inf")
    else:
        print(-ans)

# Call the main function
main()
