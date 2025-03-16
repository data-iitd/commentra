
import math
import sys

N = int(sys.stdin.readline().strip())
min = 0
for i in range(5):
    if i == 0:
        min = int(sys.stdin.readline().strip())
    else:
        min = min if min < int(sys.stdin.readline().strip()) else int(sys.stdin.readline().strip())

print(math.ceil(N / min) + 4)

