
# Python code to sort the array

# Read 5 integers from user input
io = list(map(int, input().split()))

# Outer loop to iterate through each element in the array
for i in range(len(io)):
    # Assume the current element is the maximum
    max = io[i]
    max_j = i # Store the index of the maximum element

    # Inner loop to find the maximum element in the remaining unsorted portion of the array
    for j in range(i + 1, len(io)):
        # If a larger element is found, update max and max_j
        if max < io[j]:
            max = io[j]
            max_j = j

    # Swap the found maximum element with the current element
    io[i], io[max_j] = io[max_j], io[i]

    # Print the current element, ensuring proper formatting for the last element
    if i < len(io) - 1:
        print(io[i], end=" ")
    else:
        print(io[i])

# End of Python code
