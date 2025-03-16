
import sys

# Read the number of elements and the number of pairs
n, m = map(int, input().split())

# Read the pairs of integers into arrays 'a' and 'b'
a = []
b = []
for _ in range(m):
    x, y = map(int, input().split())
    a.append(x)
    b.append(y)

# Sort the pairs using the quicksort function
def part(a, b, l, r):
    i = l - 1
    j = r
    x = b[r]
    while True:
        while b[i + 1] < x:
            i += 1
        while x < b[j - 1]:
            j -= 1
        if i >= j:
            break
        # Swap elements in array 'a'
        a[i], a[j] = a[j], a[i]
        # Swap elements in array 'b'
        b[i], b[j] = b[j], b[i]
    # Swap elements in array 'a' and 'b' to place pivot in the correct position
    a[i], a[r] = a[r], a[i]
    b[i], b[r] = b[r], b[i]
    return i

def quicksort(a, b, n):
    l = 0
    r = n - 1
    sp = 0
    low = [0] * 200000
    high = [0] * 200000
    low[sp] = l
    high[sp] = r
    sp += 1
    while sp > 0:
        sp -= 1
        l = low[sp]
        r = high[sp]
        if l >= r:
            continue
        v = part(a, b, l, r)
        if v - l < r - v:
            low[sp] = v + 1
            high[sp] = r
            sp += 1
            low[sp] = l
            high[sp] = v - 1
            sp += 1
        else:
            low[sp] = l
            high[sp] = v - 1
            sp += 1
            low[sp] = v + 1
            high[sp] = r
            sp += 1

quicksort(a, b, m)

# Count the number of unique intervals
t = 0
cnt = 0
for i in range(m):
    if t <= a[i]:
        t = b[i]
        cnt += 1

# Print the count of unique intervals
print(cnt)

