from collections import deque

def main():
    H, W = map(int, input().split())
    A = [list(input().strip()) for _ in range(H)]
    queue = deque()
    
    for i in range(H):
        for j in range(W):
            if A[i][j] == '#':
                queue.append((i, j, 0))
    
    flag = [[0] * W for _ in range(H)]
    ans = 0
    dx = [1, -1, 0, 0]
    dy = [0, 0, 1, -1]
    
    while queue:
        y, x, depth = queue.popleft()
        
        for i in range(4):
            new_y = y + dy[i]
            new_x = x + dx[i]
            
            if 0 <= new_y < H and 0 <= new_x < W:
                if flag[new_y][new_x] == 0 and A[new_y][new_x] == '.':
                    flag[new_y][new_x] = 1
                    queue.append((new_y, new_x, depth + 1))
                    ans = depth + 1
    
    print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
