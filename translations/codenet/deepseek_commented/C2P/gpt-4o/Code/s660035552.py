def part(a, b, l, r):
    i = l - 1
    j = r
    x = b[r]

    while True:
        while b[i + 1] < x:
            i += 1
        while i < j - 1 and x < b[j - 1]:
            j -= 1

        if i >= j:
            break

        # Swap elements in array 'a'
        a[i], a[j] = a[j], a[i]
        # Swap elements in array 'b'
        b[i], b[j] = b[j], b[i]

    # Swap elements in array 'a' and 'b' to place pivot in the correct position
    a[i], a[r] = a[r], a[i]
    b[i], b[r] = b[r], b[i]
    return i

def quicksort(a, b, n):
    low = [0] * n
    high = [0] * n
    sp = 0

    # Initialize the stack with the first range to be sorted
    low[sp] = 0
    high[sp] = n - 1
    sp += 1

    while sp > 0:
        sp -= 1
        l = low[sp]
        r = high[sp]

        if l < r:
            # Partition the array and get the pivot index
            v = part(a, b, l, r)

            # Push the sub-ranges onto the stack based on the pivot position
            if v - l < r - v:
                low[sp] = v + 1
                high[sp] = r
                sp += 1
                low[sp] = l
                high[sp] = v - 1
                sp += 1
            else:
                low[sp] = l
                high[sp] = v - 1
                sp += 1
                low[sp] = v + 1
                high[sp] = r
                sp += 1

def main():
    n, m = map(int, input().split())
    a = [0] * m
    b = [0] * m

    # Read the pairs of integers into arrays 'a' and 'b'
    for i in range(m):
        a[i], b[i] = map(int, input().split())

    # Sort the pairs using the quicksort function
    quicksort(a, b, m)

    # Count the number of unique intervals
    t = 0
    cnt = 0
    for i in range(m):
        if t <= a[i]:
            t = b[i]
            cnt += 1

    # Print the count of unique intervals
    print(cnt)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
