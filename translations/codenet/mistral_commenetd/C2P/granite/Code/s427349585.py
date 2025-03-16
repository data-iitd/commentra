

# Python code to sort cards using merge sort and quicksort

# Define a custom data structure 'card' with a character and an integer.
class Card:
    def __init__(self, s, v):
        self.s = s
        self.v = v

# Read the number of input cards 'n'.
n = int(input())

# Read input cards and initialize 'a' and 'b' arrays.
a = [Card(input().split()[0], int(input().split()[1])) for _ in range(n)]
b = a[:]

# Merge sort the 'a' array.
def merge_sort(a, l, r):
    if l + 1 < r:
        m = (l + r) // 2
        merge_sort(a, l, m)
        merge_sort(a, m, r)
        i, j, k = l, m, l
        while i < m and j < r:
            if a[i].v <= a[j].v:
                a[k] = a[i]
                i += 1
            else:
                a[k] = a[j]
                j += 1
            k += 1
        while i < m:
            a[k] = a[i]
            i += 1
            k += 1
        while j < r:
            a[k] = a[j]
            j += 1
            k += 1

merge_sort(a, 0, n)

# Quick sort the 'b' array.
def quick_sort(b, l, r):
    if l < r:
        pivot_index = partition(b, l, r)
        quick_sort(b, l, pivot_index - 1)
        quick_sort(b, pivot_index + 1, r)

def partition(b, l, r):
    pivot = b[r]
    i = l - 1
    for j in range(l, r):
        if b[j].v <= pivot.v:
            i += 1
            b[i], b[j] = b[j], b[i]
    b[i + 1], b[r] = b[r], b[i + 1]
    return i + 1

quick_sort(b, 0, n - 1)

# Check stability of the sorting algorithms.
stable = True
for i in range(n):
    if a[i].s!= b[i].s:
        stable = False
        break

# Print the result and the sorted array 'b'.
if stable:
    print("Stable")
else:
    print("Not stable")
for card in b:
    print(f"{card.s} {card.v}")

