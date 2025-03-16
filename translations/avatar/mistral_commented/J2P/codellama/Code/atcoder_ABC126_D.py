
import sys

def dfs(p, length):
    if colors[p.name] != -1:
        return

    if length % 2 == 0:
        colors[p.name] = 0
    else:
        colors[p.name] = 1

    for friend, length2 in p.friends.items():
        dfs(friend, length + length2)

class Point:
    def __init__(self, name):
        self.name = name
        self.friends = {}

    def becomeFriend(self, p, length):
        self.friends[p] = length

if __name__ == "__main__":
    n = int(sys.stdin.readline())
    m = n - 1
    colors = [-1] * n
    points = [Point(i) for i in range(n)]

    for _ in range(m):
        me, you, length = map(int, sys.stdin.readline().split())
        points[me - 1].becomeFriend(points[you - 1], length)
        points[you - 1].becomeFriend(points[me - 1], length)

    dfs(points[0], 0)

    for c in colors:
        print(c)

