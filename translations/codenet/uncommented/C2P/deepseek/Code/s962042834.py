def kansu(a, b):
    n = int(input())
    kouji = [[0] * (b + 1) for _ in range(a + 1)]
    suu = [[0] * (b + 1) for _ in range(a + 1)]
    
    for _ in range(n):
        x, y = map(int, input().split())
        kouji[x][y] = 1
    
    for i in range(1, a + 1):
        for j in range(1, b + 1):
            if kouji[i][j] == 1:
                suu[i][j] = 0
            else:
                if i == 1 and j == 1:
                    suu[i][j] = 1
                else:
                    if i == 1:
                        suu[i][j] = suu[i][j - 1]
                    elif j == 1:
                        suu[i][j] = suu[i - 1][j]
                    else:
                        suu[i][j] = suu[i][j - 1] + suu[i - 1][j]
    
    print(suu[a][b])

def main():
    while True:
        a, b = map(int, input().split())
        if a == 0 and b == 0:
            break
        kansu(a, b)

if __name__ == "__main__":
    main()
