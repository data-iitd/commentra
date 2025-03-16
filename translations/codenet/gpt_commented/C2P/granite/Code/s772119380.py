
# Read the number of elements to be sorted
n = int(input())

# Read the elements into a list
a = list(map(int, input().split()))

# Perform a bubble sort on the list
for i in range(n):
    for j in range(n - 1, i, -1):
        if a[j] < a[j - 1]:
            a[j], a[j - 1] = a[j - 1], a[j]

# Print the sorted list
print(*a)

# Print the total number of swaps made during sorting
swaps = 0
for i in range(n):
    for j in range(n - 1, i, -1):
        if a[j] < a[j - 1]:
            swaps += 1
print(swaps)

