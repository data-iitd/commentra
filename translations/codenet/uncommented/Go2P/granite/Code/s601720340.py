

import sys
import math

def find(n):
    for i in range(N):
        if n == p[i]:
            return 0
    return 1

def solve():
    # PARSE HELPER SESSION

    # STR = io.Next()
    # Log("string", STR)

    # F = io.NextFloat()
    # Log("float", F)

    # parsing int array
    X = io.NextInt()
    Logf("%v\n", X)
    N = io.NextInt()
    Logf("%v\n", N)
    p = []
    for i in range(N):
        p.append(io.NextInt())
    Logf("p %v\n", p[0:10])

    for i in range(101):
        if find(X-i) == 1:
            print(X-i)
            sys.exit(0)
        if find(X+i) == 1:
            print(X+i)
            sys.exit(0)

    # sort.Sort(sort.Reverse(sort.IntSlice(A[:])))
    # sort.Sort(sort.IntSlice(A[:]))

    # parsing string as byte array
    # var s [10000]byte
    # var si [10000]int
    # str = io.Next()
    # for i in range(len(str)):
    #     s[i] = ord(str[i])
    #     # "0" = 48, "A" = 65, "a" = 97
    #     si[i] = int(str[i]) - 48
    # Log("byte array", s[0:10])

    # OUTPUT GENERATION PART
    # ans = 0
    # print(ans)

    # if ans > 0:
    #   print("Yes")
    # else:
    #   print("No")

    # BFS/DFS PART
    # visited = []
    # bfs/dfs(1, neighbor, lambda node: visited.append(node))
    # print(visited)

    # DFS 2
    # dp = [0]*2000000
    # nei = {0:[1,2], 1:[0], 2:[0,3], 3:[2]}
    # dfs2(0, nei, lambda n, p: Logf("%v -> %v\n", p, n), lambda n, p: Logf("%v -> %v\n", n, p))
    # Logf("%v\n", dp[0:5])

    # COMBINATION
    # print("%d %d %d" % (N, M, intMax(N, M)))
    # print("Lucas %d %d" % (combMod(N, M, 13), combination(N, M)))

def main():
    global N, M, p
    N = io.NextInt()
    M = io.NextInt()
    p = []
    for i in range(N):
        p.append(io.NextInt())
    solve()

if __name__ == "__main__":
    main()

