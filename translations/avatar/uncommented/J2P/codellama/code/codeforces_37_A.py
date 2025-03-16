
import sys

n = int(sys.stdin.readline())

map = {}

for i in range(n):

    val = int(sys.stdin.readline())

    if val in map:

        map[val] += 1

    else:

        map[val] = 1

max = -1

for key, value in map.items():

    if value > max:

        max = value

print(max, len(map))

