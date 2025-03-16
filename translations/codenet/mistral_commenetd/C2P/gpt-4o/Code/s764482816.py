# Declare variables
io = [0] * 5

# Read 5 integers from the user and store them in the array io
def read_input():
    global io
    io = list(map(int, input().split()))

def main():
    # Initialize variables
    read_input()

    # Perform bubble sort on the array io
    for i in range(5):
        # Initialize max and max_j with the first element of the array
        max_val = io[i]
        max_j = i

        # Compare the current element with the remaining elements
        for j in range(i + 1, 5):
            # If the current max is smaller than the next element, update max and max_j
            if max_val < io[j]:
                max_val = io[j]
                max_j = j

        # Swap the current element with the maximum element
        io[i], io[max_j] = io[max_j], io[i]

        # Print the sorted elements, except for the last one
        if i < 4:
            print(io[i], end=' ')
        else:
            print(io[i])

# Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
