
# Read the number of elements in the array
n = int(input())

# Read the elements of the array
a = list(map(int, input().split()))

# Bubble sort algorithm to sort the array in ascending order
for i in range(n):
    for j in range(n - 1, i, -1):
        if a[j] < a[j - 1]:
            # Swap the elements if they are in the wrong order
            a[j], a[j - 1] = a[j - 1], a[j]
            # Increment the swap counter
            d += 1

# Print the sorted array
print(*a)

# Print the number of swaps made during the sorting process
print(d)

