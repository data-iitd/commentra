import sys

INF = 0x5fffffff  # Define a constant for infinity

# Function to read an integer from the input buffer
def getint():
    n = 0
    if p[0] == '-':
        p = p[1:]
        while p[0] >= '0':
            n = (n << 3) + (n << 1) + ord(p[0]) - ord('0')
            p = p[1:]
        return -n
    while p[0] >= '0':
        n = (n << 3) + (n << 1) + ord(p[0]) - ord('0')
        p = p[1:]
    return n

# Read the width of the evacuation route
w = int(input().strip())
# Read the evacuation route values
buf = input().strip()
p = buf

# Initialize answer and flags, and process the route values
a = []
ans = 0
f = 0
i = 0
while i < w:
    k = getint()
    a.append(k)
    p = p[1:]
    if k == 0:
        f |= 1
    elif k < 0:
        f |= 2
    else:
        ans += k

# Check for special cases: no positive values or only zeros
if ans == 0 or (f & 1) == 0:
    print(0)
    sys.exit(0)
if (f & 2) == 0:
    print(ans)
    sys.exit(0)

# Calculate the minimum distance to the closest zero from the left
b = [INF] * w
close = 0
f = 0
for i in range(w):
    if a[i] == 0:
        close = INF
        f = -1
    elif a[i] < 0:
        if f < 0 or close - (i - f) > -a[i]:
            close = -a[i]
            f = i
    else:
        if f < 0:
            b[i] = INF
        else:
            k = close - (i - f)
            if k < 0:
                k = 0
            b[i] = k

# Calculate the minimum distance to the closest zero from the right
close = 0
f = w - 1
for i in range(w - 1, -1, -1):
    if a[i] == 0:
        close = INF
        f = -1
    elif a[i] < 0:
        if f < 0 or close - (f - i) > -a[i]:
            close = -a[i]
            f = i
    else:
        if f < 0:
            b[i] = INF
        else:
            k = close - (f - i)
            if k < 0:
                k = 0
            if k > b[i]:
                b[i] = k

# Calculate the final answer based on the minimum distances
ans = 0
for i in range(w):
    if a[i] > 0:
        if b[i] > a[i]:
            ans += a[i]
        else:
            ans += b[i]

# Print the final answer
print(ans)
