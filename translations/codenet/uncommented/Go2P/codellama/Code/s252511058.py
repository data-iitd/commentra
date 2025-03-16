
import sys

def nextInt(sc):
    sc.next()
    return int(sc.next())

def main():
    sc = sys.stdin
    N = nextInt(sc)
    points = []
    for i in range(N):
        points.append((nextInt(sc), nextInt(sc), nextInt(sc)))
    points.sort(key=lambda x: x[2])
    start = points[0][2]
    ans = 1
    for i in range(len(points)):
        if points[i][0] < start:
            continue
        start = points[i][2]
        ans += 1
    print(ans)

if __name__ == '__main__':
    main()

