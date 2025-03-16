
import sys
from operator import itemgetter

def nextInt():
    return int(sys.stdin.readline())

class Point:
    def __init__(self, x, l, r):
        self.x = x
        self.l = l
        self.r = r

def main():
    N = nextInt()
    points = []
    for i in range(N):
        x = nextInt()
        L = nextInt()
        l = x - L
        r = x + L
        points.append(Point(x, l, r))
    points.sort(key=itemgetter(2))
    start = points[0].r
    ans = 1
    for i in range(1, N):
        if points[i].l < start:
            continue
        start = points[i].r
        ans += 1
    print(ans)

if __name__ == "__main__":
    main()

