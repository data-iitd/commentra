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

def binary_search(k, l, r, x):
    global ans
    if r >= l:
        mid = l + (r - l) // 2
        if mid > ans and mid * k <= x:
            ans = mid

        if k * mid == x:
            return mid

        if k * mid > x:
            return binary_search(k, l, mid - 1, x)

        return binary_search(k, mid + 1, r, x)

import sys

# Setup for input and output
input = sys.stdin.read
data = input().split()
gen = int(data[0])
st = int(data[1])
tim = int(data[2])
gen //= tim

beg = st - 1
end = 10**18
ans = 0

while True:
    med = (beg + end) // 2 + 1
    if get(med) - get(st - 1) > gen:
        end = med - 1
    else:
        beg = med
    if beg == end:
        print(beg - st + 1)
        break

# <END-OF-CODE>
