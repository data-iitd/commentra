class Card:
    def __init__(self, s, v):
        self.s = s
        self.v = v

def merge(a, l, m, r):
    n1 = m - l
    n2 = r - m
    L = a[l:m] + [Card('', 2000000000)]
    R = a[m:r] + [Card('', 2000000000)]
    
    i = 0
    j = 0
    for k in range(l, r):
        if L[i].v <= R[j].v:
            a[k] = L[i]
            i += 1
        else:
            a[k] = R[j]
            j += 1

def merge_sort(a, l, r):
    if l + 1 < r:
        m = (l + r) // 2
        merge_sort(a, l, m)
        merge_sort(a, m, r)
        merge(a, l, m, r)

def partition(a, p, r):
    x = a[r]
    i = p - 1
    for j in range(p, r):
        if a[j].v <= x.v:
            i += 1
            a[i], a[j] = a[j], a[i]
    a[i + 1], a[r] = a[r], a[i + 1]
    return i + 1

def quick_sort(a, p, r):
    if p < r:
        q = partition(a, p, r)
        quick_sort(a, p, q - 1)
        quick_sort(a, q + 1, r)

def main():
    n = int(input())
    a = []
    b = []
    
    for _ in range(n):
        s, v = input().split()
        v = int(v)
        a.append(Card(s, v))
        b.append(Card(s, v))

    merge_sort(a, 0, n)
    quick_sort(b, 0, n - 1)

    stable = True
    for i in range(n):
        if a[i].s != b[i].s:
            stable = False

    if stable:
        print("Stable")
    else:
        print("Not stable")

    for card in b:
        print(f"{card.s} {card.v}")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
