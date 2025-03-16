def exist(board, word):
    # Direction vectors for moving in four possible directions (right, left, down, up)
    dx = [0, 0, 1, -1]
    dy = [1, -1, 0, 0]
    
    # 2D array to keep track of visited cells during the DFS
    visited = [[False] * len(board[0]) for _ in range(len(board))]
    
    # Method to check if a cell (x, y) is within the bounds of the board
    def is_valid(x, y):
        return x >= 0 and x < len(board) and y >= 0 and y < len(board[0])
    
    # Depth-First Search (DFS) method to find the word in the board
    def do_dfs(x, y, next_idx):
        # Mark the current cell as visited
        visited[x][y] = True
        
        # If we have reached the end of the word, return True
        if next_idx == len(word):
            return True
        
        # Explore all four possible directions
        for i in range(4):
            xi = x + dx[i]
            yi = y + dy[i]
            
            # Check if the new cell is within bounds, matches the next character of the word, and hasn't been visited
            if is_valid(xi, yi) and board[xi][yi] == word[next_idx] and not visited[xi][yi]:
                # Recursively call do_dfs for the new cell
                if do_dfs(xi, yi, next_idx + 1):
                    return True
        
        # Backtrack: unmark the current cell as visited
        visited[x][y] = False
        
        # Return False if the word cannot be formed from the current path
        return False
    
    # Method to check if the word exists in the board
    def exist(board, word):
        # Iterate over each cell in the board to start a DFS search
        for i in range(len(board)):
            for j in range(len(board[0])):
                if board[i][j] == word[0]:
                    # Initialize the visited array for each DFS search
                    visited = [[False] * len(board[0]) for _ in range(len(board))]
                    
                    # Start DFS from the current cell
                    if do_dfs(i, j, 1):
                        return True
        return False
    
    # Main method to read input, create an instance of Main, and print the result
    if __name__ == "__main__":
        import sys
        input = sys.stdin.read
        data = input().split()
        
        # Read the dimensions of the board
        rows = int(data[0])
        cols = int(data[1])
        
        # Initialize the board with the given dimensions
        board = []
        for i in range(2, 2 + rows):
            board.append(list(data[i]))
        
        # Read the word to be searched
        word = data[2 + rows]
        
        # Create an instance of Main and check if the word exists in the board
        result = exist(board, word)
        
        # Print the result
        if result:
            print("The word exists in the board.")
        else:
            print("The word does not exist in the board.")
