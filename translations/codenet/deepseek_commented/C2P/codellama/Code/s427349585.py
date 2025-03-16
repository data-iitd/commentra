#include <stdio.h>

# Define the card structure
class Card:
    def __init__(self, s, v):
        self.s = s
        self.v = v

# Define arrays for left and right subarrays
L = [Card('', 0) for i in range(100000/2+2)]
R = [Card('', 0) for i in range(100000/2+2)]

# Merge function to merge two subarrays
def me(a, n, l, m, r):
    i = 0
    j = 0
    n1 = m - l
    n2 = r - m

    # Copy elements to left and right subarrays
    for i in range(n1):
        L[i] = a[l + i]
    for i in range(n2):
        R[i] = a[m + i]

    # Sentinel values to avoid checking for array boundaries
    L[n1].v = R[n2].v = 2000000000

    # Merge the two subarrays back into the original array
    for k in range(l, r):
        if L[i].v <= R[j].v:
            a[k] = L[i]
            i += 1
        else:
            a[k] = R[j]
            j += 1

# Merge sort function to sort the array
def ms(a, n, l, r):
    if l + 1 < r:
        m = (l + r) // 2
        ms(a, n, l, m)
        ms(a, n, m, r)
        me(a, n, l, m, r)

# Partition function to partition the array around a pivot
def partition(a, n, p, r):
    i = p - 1
    x = a[r]
    for j in range(p, r):
        if a[j].v <= x.v:
            i += 1
            a[i], a[j] = a[j], a[i]
    a[i + 1], a[r] = a[r], a[i + 1]
    return i + 1

# Quick sort function to sort the array
def qs(a, n, p, r):
    if p < r:
        q = partition(a, n, p, r)
        qs(a, n, p, q - 1)
        qs(a, n, q + 1, r)

# Main function to read input, sort the arrays, check for stability, and print the result
def main():
    n = int(input())
    a = [Card('', 0) for i in range(n)]
    b = [Card('', 0) for i in range(n)]
    stable = 1

    # Read each card's suit and value
    for i in range(n):
        s, v = input().split()
        a[i].s = b[i].s = s[0]
        a[i].v = b[i].v = int(v)

    # Sort the array using merge sort
    ms(a, n, 0, n)

    # Sort the array using quick sort
    qs(b, n, 0, n - 1)

    # Check if the sorting is stable
    for i in range(n):
        if a[i].s != b[i].s:
            stable = 0

    # Print the stability status
    if stable == 1:
        print("Stable")
    else:
        print("Not stable")

    # Print the sorted array
    for i in range(n):
        print(b[i].s, b[i].v)

if __name__ == "__main__":
    main()

