def exist(board, word):
    dx = [0, 0, 1, -1]
    dy = [1, -1, 0, 0]
    rows, cols = len(board), len(board[0])
    visited = [[False] * cols for _ in range(rows)]

    def is_valid(x, y):
        return 0 <= x < rows and 0 <= y < cols

    def do_dfs(x, y, next_idx):
        visited[x][y] = True
        if next_idx == len(word):
            return True
        for i in range(4):
            xi = x + dx[i]
            yi = y + dy[i]
            if is_valid(xi, yi) and board[xi][yi] == word[next_idx] and not visited[xi][yi]:
                if do_dfs(xi, yi, next_idx + 1):
                    return True
        visited[x][y] = False
        return False

    for i in range(rows):
        for j in range(cols):
            if board[i][j] == word[0]:
                if do_dfs(i, j, 1):
                    return True
    return False


# Example usage:
# board = [
#     ['A', 'B', 'C', 'E'],
#     ['S', 'F', 'C', 'S'],
#     ['A', 'D', 'E', 'E']
# ]
# word = "ABCCED"
# print(exist(board, word))  # Output: True
