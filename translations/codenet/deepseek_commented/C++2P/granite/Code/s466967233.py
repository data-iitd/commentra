
import sys

def main():
    N, K = map(int, input().split())
    A = list(map(int, input().split()))
    B = [-1] * (N + 1)  # Array to track visited nodes
    now = 1  # Starting node
    cnt = 0  # Counter for cycle detection
    B[1] = 0  # Mark the starting node
    for i in range(1, K + 1):
        now = A[now - 1]  # Move to the next node
        if B[now] == -1:
            B[now] = i  # Mark the node as visited
        else:
            cnt = i  # Record the cycle start
            break  # Exit the loop as cycle is detected
    if i < K:
        tmp = (K - B[now]) % (cnt - B[now])  # Calculate remaining steps
        for j in range(tmp):
            now = A[now - 1]  # Move to the position after K steps
    print(now)  # Output the final position

if __name__ == "__main__":
    main()

