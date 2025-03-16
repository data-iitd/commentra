
import sys

class Solution:
    def __init__(self):
        self.dx = [0, 0, 1, -1]
        self.dy = [1, -1, 0, 0]
        self.visited = []
        self.board = []
        self.word = ""

    def isValid(self, x, y):
        return x >= 0 and x < len(self.board) and y >= 0 and y < len(self.board[0])

    def doDFS(self, x, y, nextIdx):
        self.visited[x][y] = True
        if nextIdx == len(self.word):
            return True
        for i in range(4):
            xi = x + self.dx[i]
            yi = y + self.dy[i]
            if self.isValid(xi, yi) and self.board[xi][yi] == self.word[nextIdx] and not self.visited[xi][yi]:
                exists = self.doDFS(xi, yi, nextIdx + 1)
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
                    self.visited = [[False for _ in range(len(board[0]))] for _ in range(len(board))]
                    exists = self.doDFS(i, j, 1)
                    if exists:
                        return True
        return False

if __name__ == "__main__":
    rows = int(sys.stdin.readline().strip())
    cols = int(sys.stdin.readline().strip())
    board = []
    for _ in range(rows):
        row = sys.stdin.readline().strip()
        board.append(list(row))
    word = sys.stdin.readline().strip()
    solution = Solution()
    result = solution.exist(board, word)
    if result:
        print("The word exists in the board.")
    else:
        print("The word does not exist in the board.")
    # 