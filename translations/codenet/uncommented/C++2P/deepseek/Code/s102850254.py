def visit():
    dx = [0, 1, 0, -1]
    dy = [-1, 0, 1, 0]
    sum_ = 0
    flg = 0
    x = 2
    y = n
    map_[y][x] = ' '
    ab = [2, 2, 2, 2]

    while True:
        sum_ = 0
        while True:
            if map_[y + dy[flg] * 2][x + dx[flg] * 2] != '#' and map_[y + dy[flg]][x + dx[flg]] != ' ':
                flg = (flg + 1) % 4
                break
            map_[y + dy[flg]][x + dx[flg]] = ' '
            y += dy[flg]
            x += dx[flg]
            sum_ += 1
        if sum_ == 0:
            break
        ab[0] = ab[1]
        ab[1] = ab[2]
        ab[2] = sum_
        if ab[0] == 1 and ab[2] == 1 and ab[1] == 1:
            break


d = int(input())

for l in range(d):
    n = int(input())

    if n == 1:
        print("#")
        if l != d - 1:
            print()
        continue

    map_ = [['#' for _ in range(n + 2)] for _ in range(n + 2)]
    for i in range(n + 2):
        for j in range(n + 2):
            if i == 0 or j == 0 or i == n + 1 or j == n + 1:
                map_[i][j] = '.'

    visit()

    for i in range(1, n + 1):
        for j in range(1, len(map_[i]) - 1):
            print(map_[i][j], end='')
        print()
    if l != d - 1:
        print()

print("<END-OF-CODE>")