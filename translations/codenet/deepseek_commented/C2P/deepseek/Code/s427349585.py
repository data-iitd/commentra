# Define the card class
class Card:
    def __init__(self, suit, value):
        self.suit = suit
        self.value = value

    def __repr__(self):
        return f"{self.suit} {self.value}"

# Merge function to merge two subarrays
def merge(a, n, l, m, r):
    n1 = m - l
    n2 = r - m
    L = [None] * (n1 + 1)
    R = [None] * (n2 + 1)

    # Copy elements to left and right subarrays
    for i in range(n1):
        L[i] = a[l + i]
    for i in range(n2):
        R[i] = a[m + i]
    
    # Sentinel values to avoid checking for array boundaries
    L[n1] = Card('S', 2000000000)
    R[n2] = Card('S', 2000000000)
    
    i = 0
    j = 0
    
    # Merge the two subarrays back into the original array
    for k in range(l, r):
        if L[i].value <= R[j].value:
            a[k] = L[i]
            i += 1
        else:
            a[k] = R[j]
            j += 1

# Merge sort function to sort the array
def merge_sort(a, n, l, r):
    if l + 1 < r:
        m = (l + r) // 2
        merge_sort(a, n, l, m)
        merge_sort(a, n, m, r)
        merge(a, n, l, m, r)

# Partition function to partition the array around a pivot
def partition(a, n, p, r):
    x = a[r]
    i = p - 1
    for j in range(p, r):
        if a[j].value <= x.value:
            i += 1
            a[i], a[j] = a[j], a[i]
    a[i + 1], a[r] = a[r], a[i + 1]
    return i + 1

# Quick sort function to sort the array
def quick_sort(a, n, p, r):
    if p < r:
        q = partition(a, n, p, r)
        quick_sort(a, n, p, q - 1)
        quick_sort(a, n, q + 1, r)

# Main function to read input, sort the arrays, check for stability, and print the result
def main():
    n = int(input())
    a = []
    b = []

    # Read each card's suit and value
    for _ in range(n):
        suit, value = input().split()
        a.append(Card(suit, int(value)))
        b.append(Card(suit, int(value)))

    # Sort the array using merge sort
    merge_sort(a, n, 0, n)
    
    # Sort the array using quick sort
    quick_sort(b, n, 0, n - 1)

    # Check if the sorting is stable
    stable = True
    for i in range(n):
        if a[i].suit != b[i].suit:
            stable = False
            break

    # Print the stability status
    print("Stable" if stable else "Not stable")

    # Print the sorted array
    for card in b:
        print(card)

if __name__ == "__main__":
    main()
