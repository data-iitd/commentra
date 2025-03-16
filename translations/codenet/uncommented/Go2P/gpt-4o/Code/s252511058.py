import sys

def next_int():
    return int(sys.stdin.readline().strip())

class Point:
    def __init__(self, x, l, r):
        self.x = x
        self.l = l
        self.r = r

def main():
    N = next_int()
    points = []
    
    for _ in range(N):
        x = next_int()
        L = next_int()
        points.append(Point(x, x - L, x + L))
    
    # Sort points by their right endpoint
    points.sort(key=lambda p: p.r)
    
    # Interval scheduling problem
    start = points[0].r
    ans = 1
    
    for i in range(1, len(points)):
        if points[i].l < start:
            continue
        start = points[i].r
        ans += 1
    
    print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
