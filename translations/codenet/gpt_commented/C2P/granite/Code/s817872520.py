

import sys

# Read the width of the evacuation route
w = int(input())
# Read the evacuation route values
a = list(map(int, input().split()))

ans = 0
f = 0
for i in range(1, w+1):
    if a[i-1] == 0:
        f |= 1
    elif a[i-1] < 0:
        f |= 2
    else:
        ans += a[i-1]

if ans == 0 or (f & 1) == 0:
    print(0)
    sys.exit(0)

if (f & 2) == 0:
    print(ans)
    sys.exit(0)

b = [0] * (w+1)
close = 0
f = 0
for i in range(1, w+1):
    if a[i-1] == 0:
        close = 10**9
        f = -1
    elif a[i-1] < 0:
        if f < 0 or close - (i-f) > -a[i-1]:
            close = -a[i-1]
            f = i
    else:
        if f < 0:
            b[i] = 10**9
        else:
            k = close - (i-f)
            if k < 0:
                k = 0
            b[i] = k

close = 0
f = w
for i in range(w, 0, -1):
    if a[i-1] == 0:
        close = 10**9
        f = -1
    elif a[i-1] < 0:
        if f < 0 or close - (f-i) > -a[i-1]:
            close = -a[i-1]
            f = i
    else:
        if f < 0:
            b[i] = 10**9
        else:
            k = close - (f-i)
            if k < 0:
                k = 0
            if k > b[i]:
                b[i] = k

for i in range(1, w+1):
    if a[i-1] > 0:
        ans += min(a[i-1], b[i])

print(ans)

