def main():
    N, K = map(int, input().split())
    A = [0] * (N + 1)  # Create an array of size N+1
    B = [-1] * (N + 1)  # Array to track visited nodes
    now = 1  # Starting node
    cnt = 0  # Counter for cycle detection

    for i in range(1, N + 1):
        A[i] = int(input())  # Read the sequence of nodes

    # Detect cycle and find the position after K steps
    B[1] = 0  # Mark the starting node
    j = 1
    while j <= K:
        now = A[now]  # Move to the next node
        if B[now] == -1:
            B[now] = j  # Mark the node as visited
        else:
            cnt = j  # Record the cycle start
            break  # Exit the loop as cycle is detected
        j += 1

    if j < K:
        tmp = (K - B[now]) % (cnt - B[now])  # Calculate remaining steps
        for _ in range(tmp):
            now = A[now]  # Move to the position after K steps

    print(now)  # Output the final position

if __name__ == "__main__":
    main()

# <END-OF-CODE>
