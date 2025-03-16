def quicksort(a, b, l, r):
    if l >= r:
        return
    i = l - 1
    j = r
    x = b[r]
    while True:
        while b[i + 1] < x:
            i += 1
        while i < j and x < b[j - 1]:
            j -= 1
        if i >= j:
            break
        a[i], a[j - 1] = a[j - 1], a[i]
        b[i], b[j - 1] = b[j - 1], b[i]
        i += 1
        j -= 1
    a[i], a[r] = a[r], a[i]
    b[i], b[r] = b[r], b[i]
    quicksort(a, b, l, i - 1)
    quicksort(a, b, i + 1, r)

def partition(a, b, l, r):
    i = l - 1
    j = r
    x = b[r]
    while True:
        while b[i + 1] < x:
            i += 1
        while i < j and x < b[j - 1]:
            j -= 1
        if i >= j:
            break
        a[i], a[j - 1] = a[j - 1], a[i]
        b[i], b[j - 1] = b[j - 1], b[i]
        i += 1
        j -= 1
    a[i], a[r] = a[r], a[i]
    b[i], b[r] = b[r], b[i]
    return i

def quicksort_iterative(a, b, n):
    stack = [(0, n - 1)]
    while stack:
        l, r = stack.pop()
        if l >= r:
            continue
        pivot_index = partition(a, b, l, r)
        if pivot_index - l < r - pivot_index:
            stack.append((l, pivot_index - 1))
            stack.append((pivot_index + 1, r))
        else:
            stack.append((pivot_index + 1, r))
            stack.append((l, pivot_index - 1))

def main():
    n, m = map(int, input().split())
    a = [0] * m
    b = [0] * m
    for i in range(m):
        a[i], b[i] = map(int, input().split())
    
    quicksort_iterative(a, b, m)
    
    cnt = 0
    t = 0
    for i in range(m):
        if t <= a[i]:
            t = b[i]
            cnt += 1
    print(cnt)

if __name__ == "__main__":
    main()
