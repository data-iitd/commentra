
while True:
    n = int(input())
    if n == 0:
        break
    flag = True
    r = (n + 1) // 2 + 1
    c = (n + 1) // 2
    arr = [[0 for _ in range(n)] for _ in range(n)]
    arr[r - 1][c - 1] = cnt = 1
    while cnt!= n * n + 1:
        cnt += 1
        if flag:
            r += 1
            c += 1
            if c > n:
                c = 1
            if r > n:
                r = 1
            if arr[r - 1][c - 1]:
                flag = False
                cnt -= 1
            else:
                arr[r - 1][c - 1] = cnt
        else:
            r += 1
            c -= 1
            if c < 1:
                c = n
            if r > n:
                r = 1
            if arr[r - 1][c - 1]:
                flag = False
            else:
                arr[r - 1][c - 1] = cnt
                flag = True
    for r in range(n):
        for c in range(n):
            print(f"{arr[r][c]:4d}", end="")
        print()

