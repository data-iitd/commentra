import sys

def main():
    # Initializing variables
    x, y, k = 0, 0, 0
    dx, dy = 0, 0
    flag = True
    s = sys.stdin.readline().strip()
    ch = list(s)
    co = [[0 for i in range(101)] for j in range(2)]
    co[0][k] = x
    co[1][k] = y
    k += 1

    # Updating the positions based on the direction commands
    for i in range(len(s)):
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

    # Checking for "BUG" pattern
    for i in range(k - 3):
        for j in range(i + 3, k):
            dx = abs(co[0][i] - co[0][j])
            dy = abs(co[1][i] - co[1][j])
            if (dx <= 1 and dy == 0) or (dy <= 1 and dx == 0):
                flag = False
                break
        if not flag:
            break

    # Outputting the result
    if flag:
        print("OK")
    else:
        print("BUG")

if __name__ == "__main__":
    main()
