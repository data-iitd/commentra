import sys

def get(a):
    ret = 0
    now = 1
    t = 1
    while True:
        if now * 10 > a:
            ret += (a - now + 1) * t
            break
        ret += now * 9 * t
        now *= 10
        t += 1
    return ret

def binarySearch(k, l, r, x):
    if r >= l:
        mid = l + (r - l) / 2
        if mid > ans and mid * k <= x:
            ans = mid
        if k * mid == x:
            return mid
        if k * mid > x:
            return binarySearch(k, l, mid - 1, x)
        return binarySearch(k, mid + 1, r, x)
    return -1

br = sys.stdin
pw = sys.stdout

gen, st, tim = map(int, br.readline().split())
gen /= tim
beg = st - 1
end = 10 ** 18
while True:
    med = (beg + end) / 2 + 1
    if get(med) - get(st - 1) > gen:
        end = med - 1
    else:
        beg = med
    if beg == end:
        pw.write(str(beg - st + 1))
        break

# 