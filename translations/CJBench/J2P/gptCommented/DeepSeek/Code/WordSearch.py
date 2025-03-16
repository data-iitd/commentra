class Solution:
    def __init__(self):
        # Direction vectors for moving up, down, left, and right
        self.dx = [0, 0, 1, -1]
        self.dy = [1, -1, 0, 0]
        
    def exist(self, board, word):
        self.board = board
        self.word = word
        
        # Initialize the visited array
        self.visited = [[False] * len(board[0]) for _ in range(len(board))]
        
        # Iterate through each cell in the board
        for i in range(len(board)):
            for j in range(len(board[0])):
                # If the current cell matches the first character of the word
                if board[i][j] == word[0]:
                    # Start DFS from the current cell for the next character
                    if self.doDFS(i, j, 1):
                        return True  # If the word exists, return True
        return False  # Return False if the word is not found in the board

    def doDFS(self, x, y, nextIdx):
        # Mark the current cell as visited
        self.visited[x][y] = True

        # Check if we have found the entire word
        if nextIdx == len(self.word):
            return True

        # Explore all four possible directions
        for i in range(4):
            xi = x + self.dx[i]  # New x coordinate
            yi = y + self.dy[i]  # New y coordinate
            
            # Check if the next cell is valid, matches the next character in the word, and is not visited
            if self.isValid(xi, yi) and self.board[xi][yi] == self.word[nextIdx] and not self.visited[xi][yi]:
                # Recursively call doDFS for the next character in the word
                if self.doDFS(xi, yi, nextIdx + 1):
                    return True  # If the word exists, return True

        # Unmark the current cell as visited (backtrack)
        self.visited[x][y] = False
        return False  # Return False if the word is not found

    def isValid(self, x, y):
        return 0 <= x < len(self.board) and 0 <= y < len(self.board[0])

# Main entry point of the program
if __name__ == "__main__":
    import sys
    input = sys.stdin.read
    data = input().split()
    
    # Read the dimensions of the board
    rows = int(data[0])
    cols = int(data[1])
    
    # Initialize the board
    board = []
    
    # Read the board input from the user
    for i in range(2, 2 + rows):
        board.append(list(data[i]))
    
    # Read the word to search for
    word = data[2 + rows]
    
    # Create an instance of Solution to use the exist method
    solution = Solution()
    
    # Check if the word exists in the board
    result = solution.exist(board, word)
    
    # Output the result
    if result:
        print("The word exists in the board.")
    else:
        print("The word does not exist in the board.")
