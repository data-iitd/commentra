import sys
from collections import defaultdict

# Constants and macro definitions
BIG = 2000000007
VERYBIG = 20000000000000007
MOD = 1000000007
FOD = 998244353
N_MAX = 1048576

# Variable declarations
n = 4
m = 0
h = 0
w = 0
k = 0
q = 0
va = vb = vc = vd = ve = vf = 0
ua = ub = uc = ud = ue = uf = 0
vra = vrb = vrc = 0.0
vda = vdb = vdc = 0.0
ch = dh = ''
s = ''
a = [0] * N_MAX
b = [0] * N_MAX
c = [0] * N_MAX
cnt = [0] * 3
pcnt = 0

# Main function implementation
def main():
    global n, m, h, w, k, q, va, vb, vc, vd, ve, vf, ua, ub, uc, ud, ue, uf
    global vra, vrb, vrc, vda, vdb, vdc, ch, dh, s, a, b, c, cnt, pcnt

    # Read input values
    s = input().strip()

    # Initialize arrays
    for i in range(N_MAX):
        a[i] = 0
        b[i] = 0
        c[i] = 0

    # Read input values
    for i in range(n):
        b[i] = int(input().strip())

    # Read input values
    for i in range(m):
        c[i] = int(input().strip())

    # Read input value
    q = int(input().strip())

    # Call the solve function
    solve()

# Solve function implementation
def solve():
    global n, m, h, w, k, q, va, vb, vc, vd, ve, vf, ua, ub, uc, ud, ue, uf
    global vra, vrb, vrc, vda, vdb, vdc, ch, dh, s, a, b, c, cnt, pcnt

    # Initialize variables
    result = 1
    global maybe, sum, item, dpcell

    for i in range(n * 3):
        v = 0
        if s[i] == 'R':
            v = 0
        elif s[i] == 'G':
            v = 1
        elif s[i] == 'B':
            v = 2

        if cnt[(v + 1) % 3] and cnt[(v + 2) % 3]:
            result *= pcnt
            pcnt -= 1
            result %= FOD
            cnt[(v + 1) % 3] -= 1
            cnt[(v + 2) % 3] -= 1
        else:
            if (cnt[(v + 1) % 3] + cnt[(v + 2) % 3]) > cnt[v]:
                result *= (cnt[(v + 1) % 3] + cnt[(v + 2) % 3]) - cnt[v]
                result %= FOD
                pcnt += 1

            cnt[v] += 1

    for i in range(1, n + 1):
        result = (result * i) % FOD

    print(result)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
