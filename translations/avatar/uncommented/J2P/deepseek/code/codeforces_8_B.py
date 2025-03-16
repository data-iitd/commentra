import sys

def main():
    s = input().strip()
    ch = list(s)
    x, y = 0, 0
    co = [[0] * 101 for _ in range(2)]
    co[0][0], co[1][0] = x, y
    k = 1

    for i in range(len(s)):
        if ch[i] == 'L':
            x -= 1
        elif ch[i] == 'R':
            x += 1
        elif ch[i] == 'U':
            y += 1
        elif ch[i] == 'D':
            y -= 1
        co[0][k], co[1][k] = x, y
        k += 1

    flag = True
    for i in range(k - 3):
        for j in range(i + 3, k):
            dx = co[0][i] - co[0][j]
            dy = co[1][i] - co[1][j]
            if dx < 0:
                dx = -dx
            if dy < 0:
                dy = -dy
            if (dx <= 1 and dy == 0) or (dy <= 1 and dx == 0):
                flag = False
                break
        if not flag:
            break

    if flag:
        print("OK")
    else:
        print("BUG")

if __name__ == "__main__":
    main()
