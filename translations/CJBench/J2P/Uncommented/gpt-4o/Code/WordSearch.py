class Main:
    def __init__(self):
        self.dx = [0, 0, 1, -1]
        self.dy = [1, -1, 0, 0]
        self.visited = None
        self.board = None
        self.word = None

    def is_valid(self, x, y):
        return 0 <= x < len(self.board) and 0 <= y < len(self.board[0])

    def do_dfs(self, x, y, next_idx):
        self.visited[x][y] = True
        if next_idx == len(self.word):
            return True
        for i in range(4):
            xi = x + self.dx[i]
            yi = y + self.dy[i]
            if self.is_valid(xi, yi) and self.board[xi][yi] == self.word[next_idx] and not self.visited[xi][yi]:
                exists = self.do_dfs(xi, yi, next_idx + 1)
                if exists:
                    return True
        self.visited[x][y] = False
        return False

    def exist(self, board, word):
        self.board = board
        self.word = word
        for i in range(len(board)):
            for j in range(len(board[0])):
                if board[i][j] == word[0]:
                    self.visited = [[False] * len(board[0]) for _ in range(len(board))]
                    exists = self.do_dfs(i, j, 1)
                    if exists:
                        return True
        return False

if __name__ == "__main__":
    rows = int(input())
    cols = int(input())
    board = [list(input().strip()) for _ in range(rows)]
    word = input().strip()
    word_search = Main()
    result = word_search.exist(board, word)
    if result:
        print("The word exists in the board.")
    else:
        print("The word does not exist in the board.")

# <END-OF-CODE>
