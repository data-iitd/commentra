

import sys

def init(n):
    global x, y
    x, y = 10, 10
    field = [[0 for _ in range(21)] for _ in range(21)]
    for _ in range(n):
        a, b = map(int, input().split())
        field[b][a] = 1
    return field

def move(m):
    global x, y
    for _ in range(m):
        direction, steps = input().split()
        steps = int(steps)
        if direction == 'N':
            y -= steps
        elif direction == 'E':
            x += steps
        elif direction == 'S':
            y += steps
        elif direction == 'W':
            x -= steps
        if field[y][x] == 1:
            field[y][x] = 0
            global n
            n -= 1
    return field

if __name__ == '__main__':
    n = int(input())
    while n >= 0:
        m = int(input())
        field = init(n)
        field = move(m)
        print("No" if n else "Yes")
        n = int(input())