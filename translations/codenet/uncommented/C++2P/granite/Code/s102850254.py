
d = int(input())

for l in range(d):
    n = int(input())

    if n == 1:
        print("#")
        if l!= d-1:
            print()
        continue

    map = [['#'] * (n+2) for _ in range(n+2)]
    for i in range(n+2):
        map[i][0] = '.'
        map[i][n+1] = '.'
    for i in range(n+2):
        map[0][i] = '.'
        map[n+1][i] = '.'

    def visit():
        dx = [0, 1, 0, -1]
        dy = [-1, 0, 1, 0]
        sum = 0
        flg = 0
        x = 2
        y = n
        map[y][x] =''
        ab = [2, 2, 2, 2]

        while True:
            sum = 0
            while True:
                if map[y+dy[flg]*2][x+dx[flg]*2]!= '#' and map[y+dy[flg]][x+dx[flg]]!='':
                    flg += 1
                    # print(sum)
                    break

                map[y+dy[flg]][x+dx[flg]] =''
                y += dy[flg]
                x += dx[flg]
                sum += 1
            if flg == 4:
                flg = 0
            if sum == 0:
                break
            ab[0] = ab[1]
            ab[1] = ab[2]
            ab[2] = sum
            if ab[0] == 1 and ab[2] == 1 and ab[1] == 1:
                break

    visit()

    for i in range(1, n+1):
        print(''.join(map[i][1:-1]))
    if l!= d-1:
        print()

print("