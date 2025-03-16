class Card:
    def __init__(self, suit, value):
        self.s = suit  # Character representing the card's suit or type
        self.v = value  # Integer representing the card's value

# Merge function to combine two sorted halves of the array
def merge(a, l, m, r):
    n1 = m - l  # Size of the left half
    n2 = r - m  # Size of the right half

    # Copy data to temporary arrays L and R
    L = a[l:m]
    R = a[m:r]

    # Sentinel values to avoid out-of-bounds access
    L.append(Card('', float('inf')))
    R.append(Card('', float('inf')))

    i = j = 0  # Indices for left and right arrays
    for k in range(l, r):
        if L[i].v <= R[j].v:
            a[k] = L[i]
            i += 1  # Take from left if it's smaller or equal
        else:
            a[k] = R[j]
            j += 1  # Take from right otherwise

# Merge sort function to recursively sort the array
def merge_sort(a, l, r):
    if l + 1 < r:  # Base case: if the segment has more than one element
        m = (l + r) // 2  # Find the midpoint
        merge_sort(a, l, m)  # Sort the left half
        merge_sort(a, m, r)  # Sort the right half
        merge(a, l, m, r)  # Merge the sorted halves

# Partition function for quicksort
def partition(a, p, r):
    x = a[r]  # Choose the last element as the pivot
    i = p - 1  # Index of smaller element
    for j in range(p, r):
        if a[j].v <= x.v:  # If current element is smaller than or equal to pivot
            i += 1  # Increment index of smaller element
            # Swap elements
            a[i], a[j] = a[j], a[i]
    # Swap the pivot element with the element at i + 1
    a[i + 1], a[r] = a[r], a[i + 1]
    return i + 1  # Return the partitioning index

# Quicksort function to recursively sort the array
def quick_sort(a, p, r):
    if p < r:  # Base case: if the segment has more than one element
        q = partition(a, p, r)  # Partition the array
        quick_sort(a, p, q - 1)  # Recursively sort the left half
        quick_sort(a, q + 1, r)  # Recursively sort the right half

# Main function
def main():
    n = int(input())  # Read the number of cards
    a = []  # Array to hold the cards for sorting
    b = []  # Another array to hold the cards for sorting

    # Read the cards into both arrays a and b
    for _ in range(n):
        s, v = input().split()
        v = int(v)
        a.append(Card(s, v))  # Store the character and value
        b.append(Card(s, v))  # Store the character and value

    # Perform merge sort on array a
    merge_sort(a, 0, n)
    # Perform quicksort on array b
    quick_sort(b, 0, n - 1)

    # Check if the sorting is stable by comparing the original and sorted arrays
    stable = True
    for i in range(n):
        if a[i].s != b[i].s:
            stable = False  # If any character differs, it's not stable

    # Output the stability result
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
