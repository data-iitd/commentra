
import sys
from operator import itemgetter

def main():
    N = int(input())
    points = []
    for _ in range(N):
        x, L = map(int, input().split())
        points.append((x, x + L, x - L))
    points.sort(key=itemgetter(2))
    ans = 1
    start = points[0][1]
    for i in range(1, N):
        if points[i][2] < start:
            continue
        start = points[i][1]
        ans += 1
    print(ans)

if __name__ == '__main__':
    main()

