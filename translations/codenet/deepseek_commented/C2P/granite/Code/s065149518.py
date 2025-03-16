
import sys

# Function prototypes
def init(n):
    global x, y
    x, y = 10, 10
    for _ in range(n):
        a, b = map(int, input().split())
        fld[b][a] = 1

def move(m):
    global x, y
    for _ in range(m):
        d, a = input().split()
        d = {'N': 0, 'E': 1, 'S': 2, 'W': 3}[d]
        while a:
            a = int(a)
            if d % 2:
                if d:
                    y -= 1
                else:
                    y += 1
            else:
                if d:
                    x -= 1
                else:
                    x += 1
            if fld[y][x]:
                fld[y][x] = 0
                n -= 1

# Global variables
n = 0
x = 0
y = 0
fld = [[0] * 21 for _ in range(21)]

for line in sys.stdin:
    n = int(line)
    if not n:
        break
    init(n)
    m = int(input())
    move(m)
    print('No' if n else 'Yes')

