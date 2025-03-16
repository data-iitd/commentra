import sys
from collections import defaultdict

class Point:
    def __init__(self, name):
        self.name = name
        self.friends = defaultdict(int)

    def become_friend(self, p, length):
        self.friends[p] = length

def dfs(p, length):
    if colors[p.name] != -1:
        return
    if length % 2 == 0:
        colors[p.name] = 0
    else:
        colors[p.name] = 1
    for friend, length2 in p.friends.items():
        dfs(friend, length + length2)

# Read input
n = int(input().strip())
m = n - 1
colors = [-1] * n
points = [Point(i) for i in range(n)]

for _ in range(m):
    me, you, length = map(int, input().strip().split())
    me -= 1
    you -= 1
    points[me].become_friend(points[you], length)
    points[you].become_friend(points[me], length)

dfs(points[0], 0)

# Output the colors
for c in colors:
    print(c)
