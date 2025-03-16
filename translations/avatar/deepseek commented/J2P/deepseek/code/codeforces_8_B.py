def main():
    scan = input()
    ch = list(scan)
    x, y = 0, 0
    co = [[0 for _ in range(101)] for _ in range(2)]
    k = 0
    flag = True

    co[0][k] = x
    co[1][k] = y
    k += 1

    for i in range(len(ch)):
        if ch[i] == 'L':
            x -= 1
        elif ch[i] == 'R':
            x += 1
        elif ch[i] == 'U':
            y += 1
        elif ch[i] == 'D':
            y -= 1
        co[0][k] = x
        co[1][k] = y
        k += 1

    for i in range(k - 3):
        for j in range(i + 3, k):
            dx = abs(co[0][i] - co[0][j])
            dy = abs(co[1][i] - co[1][j])
            if (dx <= 1 and dy == 0) or (dy <= 1 and dx == 0):
                flag = False
                break
        if not flag:
            break

    if flag:
        print("OK")
    else:
        print("BUG")


main()
