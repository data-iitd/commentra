
import sys

# Step 1: Initializing variables
a = []
r = []
map = {}

# Step 2: Reading input and storing remainders
for i in range(5):
    line = sys.stdin.readline().strip()
    a.append(int(line))
    r.append(a[i] % 10)
    if r[i]!= 0:
        map[10 - r[i]] = a[i]

# Step 3: Handling edge cases
if len(map) == 0:
    ans = 0
    for i in range(5):
        ans += a[i]
    print(ans)
    sys.exit(0)

# Step 4: Finding the maximum and adjusting values
last = map[max(map.keys())]
idx = 0
for i in range(5):
    if a[i] == last:
        idx = i
ans = 0
for i in range(5):
    if i!= idx:
        if a[i] % 10 == 0:
            ans += a[i]
        else:
            ans += a[i] + (10 - r[i])
ans += last
print(ans)

