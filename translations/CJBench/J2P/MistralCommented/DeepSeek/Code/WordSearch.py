def exist(board, word):
    # Declare 2D arrays for visited cells and the board
    dx = [0, 0, 1, -1]
    dy = [1, -1, 0, 0]
    visited = [[False] * len(board[0]) for _ in range(len(board))]
    
    # Helper method to check if given coordinates are valid
    def is_valid(x, y):
        return 0 <= x < len(board) and 0 <= y < len(board[0])
    
    # Depth-First Search (DFS) helper method to find a word in the board
    def do_dfs(x, y, next_idx):
        # Mark the current cell as visited
        visited[x][y] = True
        
        # Base case: if we have visited all characters in the word
        if next_idx == len(word):
            return True
        
        # Iterate through all possible directions
        for i in range(4):
            xi = x + dx[i]
            yi = y + dy[i]
            
            # Check if the new coordinates are valid and the character matches the word
            if is_valid(xi, yi) and board[xi][yi] == word[next_idx] and not visited[xi][yi]:
                # Recursive call to search for the next character in the word
                if do_dfs(xi, yi, next_idx + 1):
                    return True
        
        # Backtrack: mark the current cell as unvisited
        visited[x][y] = False
        
        # Return false if we haven't found the word
        return False
    
    # Main method to check if the given word exists in the board
    def exist(board, word):
        # Iterate through all cells in the board
        for i in range(len(board)):
            for j in range(len(board[0])):
                # If we find the first character of the word, start the DFS search
                if board[i][j] == word[0]:
                    if do_dfs(i, j, 1):
                        return True
        return False
    
    # Main method to run the program
    if __name__ == "__main__":
        import sys
        input = sys.stdin.read
        data = input().split()
        
        # Read the dimensions of the board and initialize it
        rows = int(data[0])
        cols = int(data[1])
        board = []
        for i in range(2, 2 + rows):
            board.append(list(data[i]))
        
        # Read the word to search for
        word = data[2 + rows]
        
        # Create an instance of the Main class and call the exist method
        result = exist(board, word)
        
        # Print the result
        if result:
            print("The word exists in the board.")
        else:
            print("The word does not exist in the board.")
