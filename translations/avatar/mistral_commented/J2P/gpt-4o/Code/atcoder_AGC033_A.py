from collections import deque

# Create a function to encapsulate the main logic
def main():
    # Read the number of rows and columns from the input
    H, W = map(int, input().split())

    # Initialize a 2D list 'A' to store the input grid
    A = [list(input().strip()) for _ in range(H)]

    # Initialize a deque to store the cells to be processed
    queue = deque()

    # Read the grid and initialize the queue with the starting points of '#'
    for i in range(H):
        for j in range(W):
            # If the cell contains '#', add its starting point to the queue
            if A[i][j] == '#':
                queue.append((i, j, 0))  # (row, column, depth)

    # Initialize a 2D list 'flag' to mark the visited cells
    flag = [[0] * W for _ in range(H)]

    # Initialize variables for the answer and the directions
    ans = 0
    dx = [1, -1, 0, 0]
    dy = [0, 0, 1, -1]

    # Process the queue and find the answer
    while queue:
        y, x, depth = queue.popleft()

        # Process the neighboring cells
        for i in range(4):
            newY = y + dy[i]
            newX = x + dx[i]

            # If the cell is within the grid and hasn't been visited yet,
            # and contains a '.', mark it as visited and add it to the queue
            if 0 <= newY < H and 0 <= newX < W:
                if flag[newY][newX] == 0 and A[newY][newX] == '.':
                    flag[newY][newX] = 1
                    queue.append((newY, newX, depth + 1))
                    ans = max(ans, depth + 1)

    # Print the answer
    print(ans)

# Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
