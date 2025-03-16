MOD = 1000000007
MAX = 2**31 - 1
LMAX = 2**63 - 1

def do_it():
    N = int(input())
    K = int(input())
    A = list(map(lambda x: int(x) - 1, input().split()))
    used = set()
    idx = [0] * N
    pos = [0] * N
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
    print(pos[ans] + 1)

if __name__ == "__main__":
    do_it()
