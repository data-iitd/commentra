class Card:
    def __init__(self, suit, value):
        self.s = suit
        self.v = value

# Merge function to merge two subarrays
def merge(a, l, m, r):
    n1 = m - l
    n2 = r - m
    L = a[l:m] + [Card('', 2000000000)]  # Sentinel value
    R = a[m:r] + [Card('', 2000000000)]  # Sentinel value

    i = 0
    j = 0

    for k in range(l, r):
        if L[i].v <= R[j].v:
            a[k] = L[i]
            i += 1
        else:
            a[k] = R[j]
            j += 1

# Merge sort function to sort the array
def merge_sort(a, l, r):
    if l + 1 < r:
        m = (l + r) // 2
        merge_sort(a, l, m)
        merge_sort(a, m, r)
        merge(a, l, m, r)

# Partition function to partition the array around a pivot
def partition(a, p, r):
    x = a[r]
    i = p - 1
    for j in range(p, r):
        if a[j].v <= x.v:
            i += 1
            a[i], a[j] = a[j], a[i]
    a[i + 1], a[r] = a[r], a[i + 1]
    return i + 1

# Quick sort function to sort the array
def quick_sort(a, p, r):
    if p < r:
        q = partition(a, p, r)
        quick_sort(a, p, q - 1)
        quick_sort(a, q + 1, r)

# Main function to read input, sort the arrays, check for stability, and print the result
def main():
    n = int(input())
    a = []
    b = []
    
    for _ in range(n):
        s, v = input().split()
        v = int(v)
        a.append(Card(s, v))
        b.append(Card(s, v))

    # Sort the array using merge sort
    merge_sort(a, 0, n)

    # Sort the array using quick sort
    quick_sort(b, 0, n - 1)

    # Check if the sorting is stable
    stable = True
    for i in range(n):
        if a[i].s != b[i].s:
            stable = False

    # Print the stability status
    if stable:
        print("Stable")
    else:
        print("Not stable")

    # Print the sorted array
    for card in b:
        print(f"{card.s} {card.v}")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
