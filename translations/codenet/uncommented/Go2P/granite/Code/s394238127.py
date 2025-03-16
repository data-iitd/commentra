
import sys

c = [[0 for _ in range(3)] for _ in range(3)]
a = [0 for _ in range(3)]
b = [0 for _ in range(3)]
for i in range(3):
    for j in range(3):
        c[i][j] = int(sys.stdin.readline())

b[0] = c[0][0] - a[0]
b[1] = c[0][1] - a[0]
b[2] = c[0][2] - a[0]
a[1] = c[1][0] - c[0][0]
a[2] = c[2][0] - c[0][0]
if a[1] == c[1][1] - c[0][1] and a[1] == c[1][2] - c[0][2] and \
   a[2] == c[2][1] - c[0][1] and a[2] == c[2][2] - c[0][2]:
    print("Yes")
else:
    print("No")
