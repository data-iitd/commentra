def quicksort(a, b, low, high):
    if low >= high:
        return
    i = low - 1
    j = high
    x = b[high]
    while True:
        while a[i + 1] < x:
            i += 1
        while j > low and x < b[j - 1]:
            j -= 1
        if i >= j - 1:
            break
        a[i + 1], a[j - 1] = a[j - 1], a[i + 1]
        b[i + 1], b[j - 1] = b[j - 1], b[i + 1]
    a[i + 1], a[high] = a[high], a[i + 1]
    b[i + 1], b[high] = b[high], b[i + 1]
    quicksort(a, b, low, i)
    quicksort(a, b, i + 2, high)

def partition(a, b, l, r):
    i = l - 1
    j = r
    x = b[r]
    while True:
        while a[i + 1] < x:
            i += 1
        while i < j - 1 and x < b[j - 1]:
            j -= 1
        if i >= j - 1:
            break
        a[i + 1], a[j - 1] = a[j - 1], a[i + 1]
        b[i + 1], b[j - 1] = b[j - 1], b[i + 1]
    a[i + 1], a[r] = a[r], a[i + 1]
    b[i + 1], b[r] = b[r], b[i + 1]
    return i + 1

def quicksort_iterative(a, b, n):
    low = [0] * n
    high = [0] * n
    sp = 1
    low[0] = 0
    high[0] = n - 1
    while sp > 0:
        sp -= 1
        l = low[sp]
        r = high[sp]
        if l >= r:
            continue
        v = partition(a, b, l, r)
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

def main():
    n, m = map(int, input().split())
    a = [0] * m
    b = [0] * m
    for i in range(m):
        a[i], b[i] = map(int, input().split())

    quicksort_iterative(a, b, m)

    t = 0
    cnt = 0
    for i in range(m):
        if t <= a[i]:
            t = b[i]
            cnt += 1

    print(cnt)

if __name__ == "__main__":
    main()
