
def kansu(a, b):
    n = int(input())
    kouji = [[0 for j in range(b+1)] for i in range(a+1)]
    suu = [[0 for j in range(b+1)] for i in range(a+1)]
    for i in range(n):
        x, y = map(int, input().split())
        kouji[x][y] = 1
    for i in range(1, a+1):
        for j in range(1, b+1):
            if kouji[i][j] == 1:
                suu[i][j] = 0
            else:
                suu[i][j] = suu[i][j-1] + suu[i-1][j]
    print(suu[a][b])

while True:
    a, b = map(int, input().split())
    if a == 0 and b == 0:
        break
    kansu(a, b)

