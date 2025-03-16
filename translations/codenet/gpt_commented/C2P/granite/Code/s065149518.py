
import sys

# Function prototypes
def init(n):
    global x, y
    x, y = 10, 10
    for i in range(n):
        a, b = map(int, input().split())
        field[b][a] = 1

def move(m):
    global x, y
    for i in range(m):
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

# Global variables to hold the state of the game
n = 0
x = 0
y = 0
field = [[0 for i in range(21)] for j in range(21)]

if __name__ == '__main__':
    for line in sys.stdin:
        n = int(line)
        if n == 0:
            break
        init(n)
        m = int(input())
        move(m)
        if n == 0:
            print('Yes')
        else:
            print('No')

