# Declare variables
a = []
n = int(input("Enter the number of elements in the array: "))  # Read the number of elements in the array

# Read the elements of the array
for i in range(n):
    a.append(int(input()))

# Bubble sort algorithm to sort the array in ascending order
d = 0  # Swap counter
for i in range(n):
    for j in range(n - 1, i, -1):
        if a[j] < a[j - 1]:
            # Swap the elements if they are in the wrong order
            a[j], a[j - 1] = a[j - 1], a[j]
            # Increment the swap counter
            d += 1

# Print the sorted array
print(a[0], end="")
for i in range(1, n):
    print(" ", a[i], end="")
print()

# Print the number of swaps made during the sorting process
print(d)

# <END-OF-CODE>
