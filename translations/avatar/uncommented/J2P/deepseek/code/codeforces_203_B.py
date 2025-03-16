import sys

def main():
    inp = sys.stdin.readline
    N, M = map(int, inp().split())
    black = [[0] * (N + 2) for _ in range(N + 2)]
    
    for m in range(1, M + 1):
        x, y = map(int, inp().split())
        for xx in range(x - 1, x + 2):
            for yy in range(y - 1, y + 2):
                if black[xx][yy] == 8:
                    print(m)
                    return
                black[xx][yy] += 1
    print(-1)

if __name__ == "__main__":
    main()
