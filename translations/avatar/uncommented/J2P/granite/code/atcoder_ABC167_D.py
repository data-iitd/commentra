
MOD = 1000000007
MAX = 2147483647
LMAX = 9223372036854775807
len = 1000001

def doIt():
    N = int(input())
    K = int(input())
    A = [int(input())-1 for i in range(N)]
    used = set()
    idx = [0]*N
    pos = [0]*N
    next = 0
    cur = 0
    while next not in used:
        used.add(next)
        idx[next] = cur
        pos[cur] = next
        next = A[next]
        cur += 1
    a = cur - idx[next]
    b = idx[next]
    ans = (10000 * a + K - b) % a + b
    if b > K:
        ans = K
    print(pos[ans]+1)

doIt()

