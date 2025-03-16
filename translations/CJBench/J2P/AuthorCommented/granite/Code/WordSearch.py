

import sys

class Solution:
    def exist(self, board, word):
        """
        :type board: List[List[str]]
        :type word: str
        :rtype: bool
        """
        m, n = len(board), len(board[0])
        visited = [[False] * n for _ in range(m)]
        dx = [0, 0, 1, -1]
        dy = [1, -1, 0, 0]

        def dfs(x, y, idx):
            if idx == len(word):
                return True
            if x < 0 or x >= m or y < 0 or y >= n or board[x][y]!= word[idx] or visited[x][y]:
                return False
            visited[x][y] = True
            for i in range(4):
                if dfs(x + dx[i], y + dy[i], idx + 1):
                    return True
            visited[x][y] = False
            return False

        for i in range(m):
            for j in range(n):
                if board[i][j] == word[0] and dfs(i, j, 1):
                    return True
        return False

if __name__ == "__main__":
    rows = int(input("Enter the number of rows in the board: "))
    cols = int(input("Enter the number of columns in the board: "))
    board = []
    for _ in range(rows):
        row = list(input("Enter the elements of the board row by row: "))
        board.append(row)
    word = input("Enter the word to search: ")
    result = Solution().exist(board, word)
    print("The word exists in the board." if result else "The word does not exist in the board.")

