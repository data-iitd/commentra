import math

def dist(x1, y1, x2, y2):
    return math.sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2))

N = int(input())
pos = []
for i in range(N):
    pos.append([int(x) for x in input().split()])

sum = 0
for i in range(N):
    for j in range(N):
        if i == j:
            continue
        sum += dist(pos[i][0], pos[i][1], pos[j][0], pos[j][1])

print(sum / N)

