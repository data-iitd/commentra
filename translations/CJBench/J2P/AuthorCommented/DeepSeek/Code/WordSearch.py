class Solution:
    def __init__(self):
        self.dx = [0, 0, 1, -1]
        self.dy = [1, -1, 0, 0]

    def isValid(self, x, y, board):
        return 0 <= x < len(board) and 0 <= y < len(board[0])

    def doDFS(self, x, y, nextIdx, board, word, visited):
        visited[x][y] = True
        if nextIdx == len(word):
            return True

        for i in range(4):
            xi = x + self.dx[i]
            yi = y + self.dy[i]
            if self.isValid(xi, yi, board) and board[xi][yi] == word[nextIdx] and not visited[xi][yi]:
                if self.doDFS(xi, yi, nextIdx + 1, board, word, visited):
                    return True

        visited[x][y] = False  # Backtrack
        return False

    def exist(self, board, word):
        self.board = board
        self.word = word
        for i in range(len(board)):
            for j in range(len(board[0])):
                if board[i][j] == word[0]:
                    visited = [[False] * len(board[0]) for _ in range(len(board))]
                    if self.doDFS(i, j, 1, board, word, visited):
                        return True
        return False

# Main function to take input and output result
def main():
    import sys
    input = sys.stdin.read
    data = input().split()

    rows = int(data[0])
    cols = int(data[1])

    board = []
    word_index = 2
    for i in range(rows):
        board.append(list(data[word_index]))
        word_index += 1

    word = data[word_index]

    solution = Solution()
    result = solution.exist(board, word)

    if result:
        print("The word exists in the board.")
    else:
        print("The word does not exist in the board.")

if __name__ == "__main__":
    main()
