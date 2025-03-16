# Define a class to represent a card with a character and an integer value
class Card:
    def __init__(self, s, v):
        self.s = s
        self.v = v

    def __repr__(self):
        return f"{self.s} {self.v}"

# Merge function to combine two sorted halves of the array
def merge(a, n, l, m, r):
    n1 = m - l
    n2 = r - m
    L = [None] * (n1 + 1)
    R = [None] * (n2 + 1)

    for i in range(n1):
        L[i] = a[l + i]
    for i in range(n2):
        R[i] = a[m + i]

    L[n1] = Card('Z', 2000000000)  # Sentinel value
    R[n2] = Card('Z', 2000000000)  # Sentinel value

    i = 0
    j = 0
    for k in range(l, r):
        if L[i].v <= R[j].v:
            a[k] = L[i]
            i += 1
        else:
            a[k] = R[j]
            j += 1

# Merge sort function to recursively sort the array
def merge_sort(a, n, l, r):
    if l + 1 < r:
        m = (l + r) // 2
        merge_sort(a, n, l, m)
        merge_sort(a, n, m, r)
        merge(a, n, l, m, r)

# Partition function for quicksort
def partition(a, n, p, r):
    x = a[r]
    i = p - 1
    for j in range(p, r):
        if a[j].v <= x.v:
            i += 1
            a[i], a[j] = a[j], a[i]
    a[i + 1], a[r] = a[r], a[i + 1]
    return i + 1

# Quicksort function to recursively sort the array
def quick_sort(a, n, p, r):
    if p < r:
        q = partition(a, n, p, r)
        quick_sort(a, n, p, q - 1)
        quick_sort(a, n, q + 1, r)

# Main function
def main():
    n = int(input())
    a = []
    b = []

    for _ in range(n):
        s, v = input().split()
        card_a = Card(s, int(v))
        card_b = Card(s, int(v))
        a.append(card_a)
        b.append(card_b)

    # Perform merge sort on array a
    merge_sort(a, n, 0, n)
    # Perform quicksort on array b
    quick_sort(b, n, 0, n - 1)

    # Check if the sorting is stable by comparing the original and sorted arrays
    stable = all(a[i].s == b[i].s for i in range(n))

    # Output the stability result
    print("Stable" if stable else "Not stable")

    # Print the sorted array
    for card in b:
        print(card)

if __name__ == "__main__":
    main()
