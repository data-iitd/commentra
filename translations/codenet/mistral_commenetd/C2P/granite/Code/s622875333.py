

# Python code

# Infinite loop until user inputs 0 for both n and r
while True:
    n = int(input("Enter the number of elements in array a: "))
    r = int(input("Enter the number of rotations: "))

    if n == 0 and r == 0: # Exit the loop if n and r are both 0
        break

    # Initialize array a with the given size
    a = [n - i for i in range(n)]

    # Rotate the array r times
    for i in range(r):
        print("\nBefore rotation", i + 1, ":\n", a)

        # Create a copy of array a and store it in array b
        b = a[:]

        # Read the number of elements to be rotated and the position from user
        c = int(input("Enter the number of elements to be rotated: "))
        p = int(input("Enter the position: "))

        # Rotate the array b by c positions to the left
        b = b[c:] + b[:c]

        # Rotate the first part of array a by c positions to the left
        a = b[:p - 1] + b[p - 1 + c:]

        # Print the current state of array a after rotation
        print("\nAfter rotation", i + 1, ":\n", a)

    # Print the first element of the final array a
    print("\nThe first element of the final array is:", a[0])

