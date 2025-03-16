# Variables declaration
n, r, i, j, p, c = 0, 0, 0, 0, 0, 0
a = []
b = []

while True:
    n = int(input("Enter the number of elements in array a: "))
    r = int(input("Enter the number of rotations: "))

    if n == 0 and r == 0:  # Exit the loop if n and r are both 0
        break

    # Initialize array a with the given size
    a = [n - i for i in range(n)]  # Set the initial values of array a

    # Rotate the array r times
    for i in range(r):
        print(f"\nBefore rotation {i + 1}:")
        # Print the current state of array a before rotation
        print(" ".join(map(str, a)))

        # Create a copy of array a and store it in array b
        b = a.copy()  # Copy each element of array a to array b

        # Read the number of elements to be rotated and the position from user
        c = int(input("Enter the number of elements to be rotated: "))
        p = int(input("Enter the position: "))

        # Rotate the array b by c positions to the left
        for j in range(c):
            b[j] = b[j + 1]  # Shift each element of array b one position to the left

        # Rotate the first part of array a by c positions to the left
        for j in range(c):
            a[j] = b[p - 1 + j]  # Shift each element of the first part of array a by c positions to the left

        # Rotate the second part of array a by (p-c) positions to the right
        for j in range(c, n):
            a[j] = b[j - c]  # Shift each element of the second part of array a by (p-c) positions to the right

        # Print the current state of array a after rotation
        print(f"\nAfter rotation {i + 1}:")
        print(" ".join(map(str, a)))

    # Print the first element of the final array a
    print(f"\nThe first element of the final array is: {a[0]}")

# <END-OF-CODE>
