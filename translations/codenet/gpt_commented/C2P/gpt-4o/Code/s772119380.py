# Declare a list to hold up to 1000 integers and variables for size and counters
a = [0] * 1000
n = int(input())  # Read the number of elements to be sorted

# Read the elements into the list
for i in range(n):
    a[i] = int(input())

d = 0  # Swap counter

# Perform a bubble sort on the list
for i in range(n):
    # Inner loop for comparing adjacent elements
    for j in range(n - 1, i, -1):
        # If the current element is less than the previous one, swap them
        if a[j] < a[j - 1]:
            a[j], a[j - 1] = a[j - 1], a[j]  # Swap elements
            d += 1  # Increment the swap counter

# Print the sorted list
print(a[0], end='')  # Print the first element
for i in range(1, n):
    print(" ", a[i], end='')  # Print the remaining elements

# Print the total number of swaps made during sorting
print("\n{}".format(d))

# Return success
# <END-OF-CODE>
