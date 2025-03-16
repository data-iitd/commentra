
# Read the length of the array
len = int(input())

# Read the elements of the array
a = list(map(int, input().split()))

# Perform insertion sort
for j in range(1, len):
    # Print the current state of the array
    print(*a)
    
    # Store the current element to be positioned
    key = a[j]
    
    # Shift elements of the sorted segment to the right
    for i in range(j - 1, -1, -1):
        if a[i] > key:
            a[i + 1] = a[i]
        else:
            break
    
    # Place the key in its correct position
    a[i + 1] = key

# Print the sorted array
print(*a)

