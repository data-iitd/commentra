
import sys
import collections

class Main:
    def __init__(self):
        self.colors = []
        self.points = []

    def main(self):
        sc = sys.stdin
        n = int(sc.readline())
        m = n - 1
        self.colors = [-1] * n
        for i in range(n):
            self.points.append(Point(i))
        while m > 0:
            me = int(sc.readline()) - 1
            you = int(sc.readline()) - 1
            length = int(sc.readline())
            self.points[me].becomeFriend(self.points[you], length)
            self.points[you].becomeFriend(self.points[me], length)
            m -= 1
        self.dfs(self.points[0], 0)
        for c in self.colors:
            print(c)

    def dfs(self, p, length):
        alreadyKnown = self.colors[p.name]!= -1
        if alreadyKnown:
            return
        if length % 2 == 0:
            self.colors[p.name] = 0
        else:
            self.colors[p.name] = 1
        for entry in p.friends.items():
            friend = entry[0]
            length2 = entry[1]
            self.dfs(friend, length + length2)

class Point:
    def __init__(self, name):
        self.name = name
        self.friends = collections.defaultdict(int)

    def becomeFriend(self, p, length):
        self.friends[p] = length

if __name__ == "__main__":
    main = Main()
    main.main()

# 