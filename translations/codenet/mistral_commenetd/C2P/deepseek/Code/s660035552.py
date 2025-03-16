# Initialize low and high arrays for quicksort
low = [0] * 200000
high = [0] * 200000

# Array 'a' to store elements after sorting
a = [0] * 200000

# Array 'b' to store elements for quicksort partitioning
b = [0] * 200000

# Function to partition the array using quicksort algorithm
def part(a, b, l, r):
    i = l - 1
    j = r
    x = b[r]

    while True:
        while b[i + 1] < x:
            i += 1
        while i < j and x < b[j - 1]:
            j -= 1

        if i >= j:
            break

        a[i], a[j] = a[j], a[i]
        b[i], b[j] = b[j], b[i]

    a[i], a[r] = a[r], a[i]
    b[i], b[r] = b[r], b[i]
    return i

# Function to perform quicksort on the array 'a'
def quicksort(a, b, n):
    sp = 1
    low[0] = 0
    high[0] = n - 1

    while sp > 0:
        sp -= 1
        l = low[sp]
        r = high[sp]

        if l >= r:
            continue

        v = part(a, b, l, r)

        if v - l < r - v:
            low[sp] = v + 1
            high[sp] = r
            sp += 1
            low[sp] = l
            high[sp] = v - 1
        else:
            low[sp] = l
            high[sp] = v - 1
            sp += 1
            low[sp] = v + 1
            high[sp] = r

# Main function to read input and call quicksort
def main():
    n, m = map(int, input().split())
    for i in range(m):
        a[i], b[i] = map(int, input().split())

    quicksort(a, b, m)

    t = 0
    cnt = 0
    for i in range(m):
        if t <= a[i]:
            t = b[i]
            cnt += 1

    print(cnt)

main()
