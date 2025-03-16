from collections import deque  # Importing deque for BFS

def main():
    H, W = map(int, input().split())  # Step 1: Read height and width of the grid
    A = [input().strip() for _ in range(H)]  # Step 2: Read the grid row by row
    queue = deque()  # Initialize the queue for BFS

    # Step 3: Initialize the queue with positions of '#' characters
    for i in range(H):
        for j in range(W):
            if A[i][j] == '#':  # If the character is '#'
                queue.append((i, j, 0))  # Add the starting point to the queue

    # Step 4: Initialize a flag array to keep track of visited cells
    flag = [[0] * W for _ in range(H)]
    ans = 0  # Variable to store the maximum distance

    # Directions for moving in the grid (right, left, down, up)
    dx = [1, -1, 0, 0]
    dy = [0, 0, 1, -1]

    # Step 5: Perform BFS to find the maximum distance from any '#' to a '.'
    while queue:
        y, x, depth = queue.popleft()  # Remove the first element from the queue

        # Check all four possible directions
        for i in range(4):
            new_y, new_x = y + dy[i], x + dx[i]
            if 0 <= new_y < H and 0 <= new_x < W:  # Check bounds
                if flag[new_y][new_x] == 0 and A[new_y][new_x] == '.':
                    flag[new_y][new_x] = 1  # Mark the cell as visited
                    queue.append((new_y, new_x, depth + 1))  # Add the new position to the queue
                    ans = depth + 1  # Update the maximum distance

    # Step 6: Output the maximum distance found
    print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
