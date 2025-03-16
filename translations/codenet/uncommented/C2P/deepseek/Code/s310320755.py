def magic_square(n):
    if n == 0:
        return

    arr = [[0] * 16 for _ in range(16)]
    r = (n + 1) // 2 + 1
    c = (n + 1) // 2
    cnt = 1
    arr[r - 1][c - 1] = cnt
    flag = 1

    while cnt != n * n + 1:
        cnt += 1
        if flag:
            r += 1
            c += 1
            if c == n:
                c = 0
            if r == n:
                r = 0
            if arr[r][c]:
                flag = 0
                cnt -= 1
            else:
                arr[r][c] = cnt
        else:
            r += 1
            c -= 1
            if c == -1:
                c = n - 1
            if r == n:
                r = 0
            if arr[r][c]:
                flag = 1
            else:
                arr[r][c] = cnt
                flag = 1

    for r in range(n):
        for c in range(n):
            print(f"{arr[r][c]:4d}", end="")
        print()


while True:
    n = int(input())
    if n == 0:
        break
    magic_square(n)
