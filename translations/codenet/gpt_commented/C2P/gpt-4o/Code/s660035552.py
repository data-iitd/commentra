def partition(a, b, l, r):
    i = l - 1
    j = r
    x = b[r]

    while True:
        while b[i + 1] < x:
            i += 1
        while i < j - 1 and x < b[j - 1]:
            j -= 1
        if i >= j:
            break
        a[i], a[j] = a[j], a[i]
        b[i], b[j] = b[j], b[i]

    a[i], a[r] = a[r], a[i]
    b[i], b[r] = b[r], b[i]
    return i

def quicksort(a, b, n):
    low = [0] * 200000
    high = [0] * 200000
    sp = 0
    low[sp] = 0
    high[sp] = n - 1
    sp += 1

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
    a = [0] * 100006
    b = [0] * 100006
    cnt = 0
    t = 0

    for i in range(m):
        a[i], b[i] = map(int, input().split())

    quicksort(a, b, m)

    for i in range(m):
        if t <= a[i]:
            t = b[i]
            cnt += 1

    print(cnt)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
