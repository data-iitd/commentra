# Read five integers from the input and store them in the list 'io'
io = list(map(int, input().split()))

# Outer loop to iterate over each element in the list 'io'
for i in range(5):
    max_value = io[i]  # Initialize 'max_value' with the current element
    max_j = i          # Store the index of the current element in 'max_j'
    
    # Inner loop to find the maximum element in the unsorted part of the list
    for j in range(i + 1, 5):
        if max_value < io[j]:  # If the current maximum is less than the element at index 'j'
            max_value = io[j]   # Update 'max_value' with the new maximum value
            max_j = j           # Update 'max_j' with the index of the new maximum value
    
    # Swap the current element with the maximum element found in the unsorted part
    io[i], io[max_j] = io[max_j], io[i]
    
    # Print the current element, with a space for all but the last element, and a newline for the last element
    print(io[i], end=' ' if i < 4 else '\n')

# <END-OF-CODE>
