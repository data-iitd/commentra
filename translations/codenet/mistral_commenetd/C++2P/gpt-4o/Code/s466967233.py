def main():
    # Initialize variables
    N, K = map(int, input().split())
    A = [0] * (N + 1)
    B = [-1] * (200100)
    now = 1
    cnt = 0

    # Read array A
    for i in range(1, N + 1):
        A[i] = int(input())

    # B[1] is always 0
    B[1] = 0

    # Simulation of the algorithm
    for j in range(1, K + 1):
        # Move to the next node
        now = A[now]

        # If the node has not been reached yet, update B[now]
        if B[now] == -1:
            B[now] = j
        else:
            # If the node has already been reached, calculate the answer
            cnt = j
            break

    # If the simulation has not reached the end, calculate the answer
    if j < K:
        tmp = (K - B[now]) % (cnt - B[now])

        # Move to the final node
        for _ in range(tmp):
            now = A[now]

    # Print the answer
    print(now)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
