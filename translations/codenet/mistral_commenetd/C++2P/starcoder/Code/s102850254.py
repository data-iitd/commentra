
d = int(input())
for i in range(d):
    n = int(input())
    if n == 1:
        print("#")
        if i!= d-1:
            print()
        continue
    map = [['#' for i in range(n+2)] for j in range(n+2)]
    for i in range(1,n+1):
        map[i][0] = '.'
        map[i][n+1] = '.'
    for i in range(1,n+1):
        map[0][i] = '.'
        map[n+1][i] = '.'
    x,y = 2,n
    while True:
        sum = 0
        flg = 0
        while True:
            if map[y+dy[flg]*2][x+dx[flg]*2]!= '#' and map[y+dy[flg]][x+dx[flg]]!='':
                flg += 1
                map[y+dy[flg]][x+dx[flg]] =''
                y += dy[flg]
                x += dx[flg]
                sum += 1
                break
        if flg == 4:
            flg = 0
            if sum == 0:
                break
            ab = [ab[1],ab[2],sum]
            if ab[0] == 1 and ab[2] == 1 and ab[1] == 1:
                break
    for i in range(1,n+1):
        for j in range(1,n+1):
            print(map[i][j],end='')
        print()
    if i!= d-1:
        print()

