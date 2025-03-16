import sys

heap = []
sz = 0

def push(x):
    global sz
    i = sz
    sz += 1

    while i > 0:
        p = (i - 1) // 2
        if heap[p] >= x:
            break
        heap.append(heap[p])
        i = p

    if i < len(heap):
        heap[i] = x
    else:
        heap.append(x)

def pop():
    global sz
    ret = heap[0]
    x = heap[sz - 1]
    sz -= 1

    i = 0
    while i * 2 + 1 < sz:
        a = i * 2 + 1
        b = i * 2 + 2

        if b < sz and heap[b] > heap[a]:
            a = b

        if heap[a] <= x:
            break

        heap[i] = heap[a]
        i = a

    if i < len(heap):
        heap[i] = x
    else:
        heap.append(x)

    return ret

def main():
    global heap, sz
    n, m = map(int, sys.stdin.readline().split())
    a = list(map(int, sys.stdin.readline().split()))

    for i in range(n):
        push(a[i])

    for i in range(m):
        tm = pop()
        tm //= 2
        push(tm)

    ans = sum(heap[:sz])
    print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
