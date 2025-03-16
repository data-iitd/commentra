import sys
input = sys.stdin.readline

def read():
    k = 0
    f = 1
    ch = input()
    while ch < '0' or ch > '9':
        if ch == '-':
            f = -1
        ch = input()
    while ch >= '0' and ch <= '9':
        k = k * 10 + ord(ch) - ord('0')
        ch = input()
    return k * f

def write(x):
    if x < 0:
        x = -x
        sys.stdout.write('-')
    if x > 9:
        write(x // 10)
    sys.stdout.write(chr(x % 10 + ord('0')))

def writeln(x):
    write(x)
    sys.stdout.write('\n')

n, m, l, r, vi, fa, v = None, None, None, None, None, None, None

def get(x):
    if x == fa[x]:
        return x
    f = get(fa[x])
    v[x] += v[fa[x]]
    return fa[x] = f

# Main function
def main():
    global n, m, l, r, vi, fa, v
    n = read()
    m = read()
    fa = [i for i in range(n + 1)]
    v = [0] * (n + 1)
    for _ in range(m):
        l = read()
        r = read()
        vi = read()
        li = get(l)
        ri = get(r)
        if li != ri:
            v[ri] = vi - v[r] + v[l]
            fa[ri] = li
        else:
            if v[r] - v[l] != vi:
                print("No")
                return
    print("Yes")

main()
