def visit():
    dx = [0, 1, 0, -1]
    dy = [-1, 0, 1, 0]
    ab = [2, 2, 2, 2]
    x, y = 2, n
    map[y][x] = ' '
    
    flg = 0
    while True:
        sum_steps = 0
        while True:
            if map[y + dy[flg] * 2][x + dx[flg] * 2] != '#' and map[y + dy[flg]][x + dx[flg]] != ' ':
                flg += 1
                break
            
            map[y + dy[flg]][x + dx[flg]] = ' '
            y += dy[flg]
            x += dx[flg]
            sum_steps += 1
        
        if flg == 4:
            flg = 0
        if sum_steps == 0:
            break
        
        ab[0] = ab[1]
        ab[1] = ab[2]
        ab[2] = sum_steps
        if ab[0] == 1 and ab[1] == 1 and ab[2] == 1:
            break

d = int(input())

for l in range(d):
    n = int(input())
    
    if n == 1:
        print("#")
        if l != d - 1:
            print()
        continue
    
    map = [['#' for _ in range(n + 2)] for _ in range(n + 2)]
    
    for i in range(1, n + 1):
        for j in range(1, n + 1):
            map[i][j] = '.'
    
    visit()
    
    for i in range(1, n + 1):
        print(''.join(map[i][1:n + 1]))
    
    if l != d - 1:
        print()

# <END-OF-CODE>
