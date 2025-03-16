
# Read the length of the array
len = int(input())

# Read the elements of the array
a = list(map(int, input().split()))

# Perform Insertion Sort
for j in range(1, len):
    # Print the array before each iteration
    print(*a)
    
    # Store the current element to be inserted
    key = a[j]
    
    # Shift elements to the right to make space for the key
    for i in range(j - 1, -1, -1):
        if a[i] > key:
            a[i + 1] = a[i]
        else:
            break
    
    # Insert the key into the correct position
    a[i + 1] = key

# Print the sorted array
print(*a)

