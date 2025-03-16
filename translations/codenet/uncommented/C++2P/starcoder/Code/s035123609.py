
import sys

def main(argv):
    rr, cc, k = map(int, sys.stdin.readline().split())
    mat = [[0 for x in range(cc)] for y in range(rr)]
    dp = [[[0 for x in range(4)] for y in range(cc)] for z in range(rr)]
    dpl = [0 for x in range(cc)]
    for i in range(k):
        r, c, v = map(int, sys.stdin.readline().split())
        mat[r - 1][c - 1] = v
    dp[0][0][1] = mat[0][0]
    for y in range(rr):
        for x in range(cc):
            for c in range(4):
                v = mat[y][x]
                q = 0
                if c == 0 or v == 0:
                    q = (x == 0) and dpl[x] or max(dpl[x], dp[y][x - 1][c])
                else:
                    q = (x == 0) and dpl[x] + v or max(dpl[x] + v, max(dp[y][x - 1][c], dp[y][x - 1][c - 1] + v))
                dp[y][x][c] = q
        for x in range(cc):
            dpl[x] = max(max(dp[y][x][0], dp[y][x][1]), max(dp[y][x][2], dp[y][x][3]))
    print(dpl[cc - 1])
    return 0

if __name__ == "__main__":
    sys.exit(main(sys.argv))

