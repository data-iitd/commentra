# AOJ 2601: Evacuation Route
# 2017.11.26 bal4u@uu

import sys

# Define a constant for infinity
INF = 0x5fffffff

# Read the width of the evacuation route
w = int(sys.stdin.readline())
# Read the evacuation route values
a = [int(sys.stdin.readline()) for i in range(w+1)]

# Initialize answer and flags, and process the route values
ans = 0
f = 0
for i in range(1, w+1):
    k = a[i]
    if not k: f |= 1
    elif k < 0: f |= 2
    else: ans += k

# Check for special cases: no positive values or only zeros
if not ans or not f & 1:
    print('0')
    sys.exit(0)
# If there are no negative values, print the total sum
if not f & 2:
    print(ans)
    sys.exit(0)

# Calculate the minimum distance to the closest zero from the left
close = 0
f = 0
for i in range(1, w+1):
    if not a[i]:
        close = INF
        f = -1
    elif a[i] < 0:
        if f < 0 or close - (i-f) > -a[i]:
            close = -a[i]
            f = i

# Calculate the minimum distance to the closest zero from the right
b = [INF] * (w+1)
close = 0
f = w
for i in range(w, 0, -1):
    if not a[i]:
        close = INF
        f = -1
    elif a[i] < 0:
        if f < 0 or close - (f-i) > -a[i]:
            close = -a[i]
            f = i
    else:
        if f < 0:
            b[i] = INF
        else:
            k = close - (f-i)
            if k < 0:
                k = 0
            if k > b[i]:
                b[i] = k

# Calculate the final answer based on the minimum distances
for i in range(1, w+1):
    if a[i] > 0:
        if b[i] > a[i]:
            ans += a[i]
        else:
            ans += b[i]

# Print the final answer
print(ans)

