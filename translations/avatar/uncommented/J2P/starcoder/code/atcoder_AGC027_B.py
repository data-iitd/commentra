import sys

def solve():
    N = int(raw_input())
    X = long(raw_input())
    x = [long(raw_input()) for i in xrange(N)]
    xsum = [0]
    for i in xrange(N):
        xsum.append(xsum[-1] + x[i])
    ans = X * N + 5 * xsum[N]
    for i in xrange(1, N):
        cost = X * i + 5 * (xsum[N] - xsum[N - i])
        for j in xrange(5, 0, -2):
            for k in xrange(N - i, -1, -i):
                if cost > ans:
                    break
                cost += j * (xsum[k] - xsum[max(k - i, 0)])
            else:
                continue
            break
        ans = min(ans, cost)
    print ans + N * X

if __name__ == "__main__":
    solve()
#