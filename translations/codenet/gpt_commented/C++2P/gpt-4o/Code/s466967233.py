def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    N = int(data[0])  # Number of elements
    K = int(data[1])  # Number of steps
    A = [0] * (N + 1)  # Array to store the input values
    B = [-1] * (200100)  # Array to track the first visit time to each position, initialized to -1
    now = 1  # Current position, starting at 1
    cnt = 0  # Counter for the number of steps taken

    # Read the elements into array A
    for i in range(1, N + 1):
        A[i] = int(data[i + 1])  # Store input values in A, starting from index 1

    # Mark the starting position as visited at step 0
    B[1] = 0  # Starting point is visited at step 0

    # Traverse the positions based on the values in A
    for j in range(1, K + 1):
        now = A[now]  # Move to the next position based on the current position

        # Check if the current position has been visited before
        if B[now] == -1:
            B[now] = j  # Mark the position with the current step count
        else:
            # If the position has been visited, calculate the cycle length
            cnt = j  # Store the current step count
            break  # Exit the loop as we found a cycle

    # If we did not reach the maximum steps K
    if j < K:
        # Calculate how many additional steps to take within the cycle
        tmp = (K - B[now]) % (cnt - B[now])
        
        # Move to the final position after the calculated additional steps
        for _ in range(tmp):
            now = A[now]  # Continue moving to the next position

    # Output the final position after all movements
    print(now)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
