
import sys
import math

magic = 1000000007

def find(n):
    for i in range(N):
        if n == p[i]:
            return 0
    return 1

def solve():
    # PARSE HELPER SESSION

    # STR = sys.stdin.readline().rstrip()
    # print("string", STR)

    # F = float(sys.stdin.readline().rstrip())
    # print("float", F)

    # parsing int array
    X = int(sys.stdin.readline().rstrip())
    print(X)
    N = int(sys.stdin.readline().rstrip())
    print(N)
    for i in range(N):
        p[i] = int(sys.stdin.readline().rstrip())
    print("p", p[0:10])

    for i in range(100):
        if find(X-i) == 1:
            print(X-i)
            sys.exit(0)
        if find(X+i) == 1:
            print(X+i)
            sys.exit(0)

    # sort.Sort(sort.Reverse(sort.IntSlice(A[:])))
    # sort.Sort(sort.IntSlice(A[:]))

    # parsing string as byte array
    # s = sys.stdin.readline().rstrip()
    # si = [0] * len(s)
    # for i in range(len(s)):
    #     si[i] = ord(s[i]) - 48
    # print("byte array", s[0:10])

    # OUTPUT GENERATION PART
    # ans = 0
    # print(ans)

    # if ans > 0:
    #   print("Yes")
    # else:
    #   print("No")

    # BFS/DFS PART
    # visited = []
    # bfs(1, neighbor, lambda node: visited.append(node))
    # print(visited)

    # DFS 2
    # dp = [0] * 2000000
    # nei = {}
    # nei[0] = [1, 2]
    # nei[1] = [0]
    # nei[2] = [0, 3]
    # nei[3] = [2]
    # dfs2(0, nei, lambda n, p: print(p, n), lambda n, p: print(n, p))
    # print(dp[0:5])

    # COMBINATION
    # print(N, M, intMax(N, M))
    # print("Lucas", combMod(N, M, 13), combination(N, M))

if __name__ == "__main__":
    solve()

