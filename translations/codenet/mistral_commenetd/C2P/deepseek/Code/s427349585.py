class Card:
    def __init__(self, suit, value):
        self.suit = suit
        self.value = value

    def __repr__(self):
        return f"{self.suit} {self.value}"

def merge(a, n, l, m, r):
    n1 = m - l
    n2 = r - m
    L = [a[l + i] for i in range(n1)]
    R = [a[m + i] for i in range(n2)]
    L.append(Card('Z', 2000000000))
    R.append(Card('Z', 2000000000))
    i = j = 0
    for k in range(l, r):
        if L[i].value <= R[j].value:
            a[k] = L[i]
            i += 1
        else:
            a[k] = R[j]
            j += 1

def merge_sort(a, n, l, r):
    if l + 1 < r:
        m = (l + r) // 2
        merge_sort(a, n, l, m)
        merge_sort(a, n, m, r)
        merge(a, n, l, m, r)

def partition(a, n, p, r):
    x = a[r]
    i = p - 1
    for j in range(p, r):
        if a[j].value <= x.value:
            i += 1
            a[i], a[j] = a[j], a[i]
    a[i + 1], a[r] = a[r], a[i + 1]
    return i + 1

def quick_sort(a, n, p, r):
    if p < r:
        q = partition(a, n, p, r)
        quick_sort(a, n, p, q - 1)
        quick_sort(a, n, q + 1, r)

def is_stable(a, b):
    for i in range(len(a)):
        if a[i].suit != b[i].suit:
            return False
    return True

n = int(input())
a = [Card(s[0], int(v)) for s, v in [input().split() for _ in range(n)]]
b = a.copy()

merge_sort(a, n, 0, n)
quick_sort(b, n, 0, n - 1)

stable = is_stable(a, b)
print("Stable" if stable else "Not stable")
for card in b:
    print(card)

