# Declare a list to hold 5 integer inputs
io = list(map(int, input().split()))

# Iterate through each element in the list
for i in range(5):
    # Assume the current element is the maximum
    max_value = io[i]
    max_index = i  # Store the index of the maximum element

    # Inner loop to find the maximum element in the remaining unsorted portion of the list
    for j in range(i + 1, 5):
        # If a larger element is found, update max_value and max_index
        if max_value < io[j]:
            max_value = io[j]
            max_index = j

    # Swap the found maximum element with the current element
    io[i], io[max_index] = io[max_index], io[i]

    # Print the current element, ensuring proper formatting for the last element
    print(io[i], end=' ' if i < 4 else '\n')

# <END-OF-CODE>
