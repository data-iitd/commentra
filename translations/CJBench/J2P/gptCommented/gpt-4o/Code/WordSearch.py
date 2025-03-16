class Main:
    def __init__(self):
        # Direction vectors for moving up, down, left, and right
        self.dx = [0, 0, 1, -1]
        self.dy = [1, -1, 0, 0]
        
        # 2D array to track visited cells
        self.visited = []
        
        # 2D character array representing the board
        self.board = []
        
        # The word we are searching for
        self.word = ""

    # Method to check if the given coordinates are within the bounds of the board
    def is_valid(self, x, y):
        return 0 <= x < len(self.board) and 0 <= y < len(self.board[0])

    # Depth-First Search (DFS) method to explore the board for the word
    def do_dfs(self, x, y, next_idx):
        # Mark the current cell as visited
        self.visited[x][y] = True

        # Check if we have found the entire word
        if next_idx == len(self.word):
            return True

        # Explore all four possible directions
        for i in range(4):
            xi = x + self.dx[i]  # New x coordinate
            yi = y + self.dy[i]  # New y coordinate
            
            # Check if the next cell is valid, matches the next character in the word, and is not visited
            if (self.is_valid(xi, yi) and 
                self.board[xi][yi] == self.word[next_idx] and 
                not self.visited[xi][yi]):
                # Recursively call do_dfs for the next character in the word
                if self.do_dfs(xi, yi, next_idx + 1):
                    return True  # If the word exists, return true

        # Unmark the current cell as visited (backtrack)
        self.visited[x][y] = False 
        return False  # Return false if the word is not found

    # Main method to check if the word exists in the board
    def exist(self, board, word):
        self.board = board  # Initialize the board
        self.word = word    # Initialize the word
        self.visited = [[False] * len(board[0]) for _ in range(len(board))]  # Initialize visited array
        
        # Iterate through each cell in the board
        for i in range(len(board)):
            for j in range(len(board[0])):
                # If the current cell matches the first character of the word
                if board[i][j] == word[0]:
                    # Start DFS from the current cell for the next character
                    if self.do_dfs(i, j, 1):
                        return True  # If the word exists, return true
        return False  # Return false if the word is not found in the board

# Main entry point of the program
if __name__ == "__main__":
    import sys
    
    # Read the dimensions of the board
    rows, cols = map(int, sys.stdin.readline().split())
    
    # Initialize the board
    board = [list(sys.stdin.readline().strip()) for _ in range(rows)]
    
    # Read the word to search for
    word = sys.stdin.readline().strip()
    
    # Create an instance of Main to use the exist method
    word_search = Main()
    
    # Check if the word exists in the board
    result = word_search.exist(board, word)
    
    # Output the result
    if result:
        print("The word exists in the board.")
    else:
        print("The word does not exist in the board.")

# <END-OF-CODE>
