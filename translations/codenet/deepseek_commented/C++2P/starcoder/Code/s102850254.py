d = int(input())
for i in range(d):
    n = int(input())
    if n == 1:
        print("#")
    else:
        map = [['#' for i in range(n+2)] for j in range(n+2)]
        for i in range(1, n+1):
            map[i][0] = '.'
            map[i][n+1] = '.'
        for i in range(1, n+1):
            map[0][i] = '.'
            map[n+1][i] = '.'
        map[1][1] = '.'
        map[1][n] = '.'
        map[n][1] = '.'
        map[n][n] = '.'
        x, y = 1, 1
        while True:
            if map[y][x+1] == '.' and map[y][x-1] == '.' and map[y+1][x] == '.' and map[y-1][x] == '.':
                break
            if map[y][x+1] == '.':
                x += 1
            elif map[y][x-1] == '.':
                x -= 1
            elif map[y+1][x] == '.':
                y += 1
            else:
                y -= 1
            map[y][x] = '.'
        x, y = 1, n
        while True:
            if map[y][x+1] == '.' and map[y][x-1] == '.' and map[y+1][x] == '.' and map[y-1][x] == '.':
                break
            if map[y][x+1] == '.':
                x += 1
            elif map[y][x-1] == '.':
                x -= 1
            elif map[y+1][x] == '.':
                y += 1
            else:
                y -= 1
            map[y][x] = '.'
        x, y = n, 1
        while True:
            if map[y][x+1] == '.' and map[y][x-1] == '.' and map[y+1][x] == '.' and map[y-1][x] == '.':
                break
            if map[y][x+1] == '.':
                x += 1
            elif map[y][x-1] == '.':
                x -= 1
            elif map[y+1][x] == '.':
                y += 1
            else:
                y -= 1
            map[y][x] = '.'
        x, y = n, n
        while True:
            if map[y][x+1] == '.' and map[y][x-1] == '.' and map[y+1][x] == '.' and map[y-1][x] == '.':
                break
            if map[y][x+1] == '.':
                x += 1
            elif map[y][x-1] == '.':
                x -= 1
            elif map[y+1][x] == '.':
                y += 1
            else:
                y -= 1
            map[y][x] = '.'
        for i in range(1, n+1):
            for j in range(1, n+1):
                print(map[i][j], end='')
            print()
    if i!= d-1:
        print()

