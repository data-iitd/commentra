
import sys

# Global arrays to hold the low and high indices for the quicksort stack
low = [0]
high = [0]
a = []
b = []

# Function to partition the arrays based on the quicksort algorithm
def part(a, b, l, r):
    i = l - 1
    j = r
    x = b[r]

    while True:
        while b[++i] < x:
            pass
        while i < --j and x < b[j]:
            pass
        if i >= j:
            break
        t = a[i]
        a[i] = a[j]
        a[j] = t
        t = b[i]
        b[i] = b[j]
        b[j] = t

    t = a[i]
    a[i] = a[r]
    a[r] = t
    t = b[i]
    b[i] = b[r]
    b[r] = t
    return i

# Function to perform quicksort on two arrays
def quicksort(a, b, n):
    sp = 1
    while sp > 0:
        sp -= 1
        l = low[sp]
        r = high[sp]
        if l >= r:
            continue
        v = part(a, b, l, r)
        if v - l < r - v:
            high[sp] = r
            low[sp] = v + 1
            high[sp + 1] = v - 1
            low[sp + 1] = l
            sp += 1
        else:
            high[sp] = v - 1
            low[sp] = l
            high[sp + 1] = r
            low[sp + 1] = v + 1
            sp += 1

# Main function to execute the program
def main():
    n, m = map(int, input().split())
    for i in range(m):
        a.append(0)
        b.append(0)
    for i in range(m):
        a[i], b[i] = map(int, input().split())
    quicksort(a, b, m)
    t = 0
    cnt = 0
    for i in range(m):
        if t <= a[i]:
            t = b[i]
            cnt += 1
    print(cnt)

if __name__ == "__main__":
    main()

