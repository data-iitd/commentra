
import sys
import math

def main():
    r = sys.stdin
    n, m, R = map(int, r.readline().split())
    rs = [int(x) - 1 for x in r.readline().split()]

    costs = [[INF for _ in range(n)] for _ in range(n)]
    for i in range(n):
        costs[i][i] = 0
    for i in range(m):
        a, b, c = map(int, r.readline().split())
        costs[a - 1][b - 1] = c
        costs[b - 1][a - 1] = c

    # ワーシャルフロイド法で最短経路を算出
    for k in range(n):
        for i in range(n):
            for j in range(n):
                costs[i][j] = min(costs[i][j], costs[i][k] + costs[k][j])

    # 順列で訪問先の順序をすべて試す
    # これでは重複して訪問する町がでてしまうか。。
    perms = permutations(rs)
    ans = INF
    for perm in perms:
        tmp = 0
        for j in range(1, len(perm)):
            from = perm[j - 1]
            to = perm[j]
            tmp += costs[from][to]
        ans = min(ans, tmp)
    print(ans)

def min(x, y):
    if x < y:
        return x
    return y

def permutations(arr):
    res = []

    def helper(arr, n):
        if n == 1:
            tmp = arr[:]
            res.append(tmp)
        else:
            for i in range(n):
                helper(arr, n - 1)
                if n % 2 == 1:
                    tmp = arr[i]
                    arr[i] = arr[n - 1]
                    arr[n - 1] = tmp
                else:
                    tmp = arr[0]
                    arr[0] = arr[n - 1]
                    arr[n - 1] = tmp

    helper(arr, len(arr))
    return res

if __name__ == "__main__":
    main()

