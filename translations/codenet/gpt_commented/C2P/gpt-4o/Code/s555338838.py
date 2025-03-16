# Declare variables
len_array = int(input())  # Read the length of the array
a = list(map(int, input().split()))  # Read the elements of the array

# Perform insertion sort
for j in range(1, len_array):
    # Print the current state of the array
    print(" ".join(map(str, a)))  # Print the array elements in a single line
    
    # Store the current element to be positioned
    key = a[j]
    
    # Shift elements of the sorted segment to the right
    i = j - 1
    while i >= 0 and a[i] > key:
        a[i + 1] = a[i]
        i -= 1
    
    # Place the key in its correct position
    a[i + 1] = key

# Print the sorted array
print(" ".join(map(str, a)))  # Print the sorted array in a single line

# End of the program
# <END-OF-CODE>
