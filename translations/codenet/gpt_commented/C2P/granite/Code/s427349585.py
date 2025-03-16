
# Python code to perform merge sort and quicksort on cards

# Define a class to represent a card with a character and an integer value
class Card:
    def __init__(self, s, v):
        self.s = s  # Character representing the card's suit or type
        self.v = v  # Integer representing the card's value

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
    L[n1] = R[n2] = float('inf')  # Sentinels to avoid out-of-bounds access
    i = j = 0
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
    i = p - 1
    x = a[r]
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
    n = int(input("Enter the number of cards: "))
    a = [None] * n  # Array to hold the cards for sorting
    b = [None] * n  # Array to hold the sorted cards
    stable = True  # Flag to check if the sorting is stable

    # Read the cards into both arrays a and b
    for i in range(n):
        s, v = input("Enter the card (suit and value): ").split()
        a[i] = Card(s, int(v))
        b[i] = Card(s, int(v))

    # Perform merge sort on array a
    merge_sort(a, n, 0, n)
    # Perform quicksort on array b
    quick_sort(b, n, 0, n - 1)

    # Check if the sorting is stable by comparing the original and sorted arrays
    for i in range(n):
        if a[i].s!= b[i].s:
            stable = False  # If any character differs, it's not stable

    # Output the stability result
    if stable:
        print("Stable")
    else:
        print("Not stable")

    # Print the sorted array
    for i in range(n):
        print(f"{b[i].s} {b[i].v}")

if __name__ == "__main__":
    main()

