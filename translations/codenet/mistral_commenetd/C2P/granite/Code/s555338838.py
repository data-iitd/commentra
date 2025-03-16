
# Read the length of the array from the user
len = int(input("Enter the length of the array: "))

# Read the elements of the array from the user
a = list(map(int, input("Enter {} integers: ".format(len)).split()))

# Sort the array using bubble sort algorithm
for j in range(1, len):
    # Iterate through the array and compare each element with the current key
    for i in range(len):
        # If the current element is not the first one, print it with a space
        if i!= 0: print(" {}".format(a[i]), end="")
        # Otherwise, print it without a space
        else: print(a[i], end="")
    # Print a new line after each pass
    print()

    # Set the current key to the next element
    key = a[j]

    # Swap the current key with the previous element if it is greater
    for i in range(j - 1, -1, -1):
        if a[i] > key:
            a[i + 1] = a[i]
        else:
            break

    # Swap the current key with the previous element
    a[i + 1] = key

# Print the sorted array
for i in range(len):
    # If the current index is not the first one, print it with a space
    if i!= 0: print(" {}".format(a[i]), end="")
    # Otherwise, print it without a space
    else: print(a[i], end="")
# Print a new line after printing the sorted array
print()

# 