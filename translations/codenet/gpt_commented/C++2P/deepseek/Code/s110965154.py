def sort(a_vecIntValue):
    # Iterate through each element in the vector
    for i in range(len(a_vecIntValue)):
        # Check if we are not at the first element
        if i != 0:
            # Store the current element to be inserted
            iIntValue = a_vecIntValue[i]
            j = i - 1
            
            # Move elements of a_vecIntValue[0..i-1], that are greater than iIntValue,
            # to one position ahead of their current position
            while j >= 0 and a_vecIntValue[j] > iIntValue:
                a_vecIntValue[j + 1] = a_vecIntValue[j]  # Shift element to the right
                j -= 1  # Move to the previous element
            
            # Place the current element at its correct position
            a_vecIntValue[j + 1] = iIntValue

        # Print the current state of the sorted portion of the vector
        for k in range(len(a_vecIntValue)):
            print(a_vecIntValue[k], end='')  # Output the element
            # Print a space between elements, but not after the last element
            if k != len(a_vecIntValue) - 1:
                print(" ", end='')
        print()  # New line after printing the current state


# Main function to read input and call the sort function
if __name__ == "__main__":
    # Variable to hold the number of integers to be sorted
    iNum = int(input())
    
    # Vector to store the integers
    vecIntValue = []
    
    # Loop to read integers from input and store them in the vector
    while iNum > 0:
        iIntValue = int(input())  # Read an integer
        vecIntValue.append(iIntValue)  # Add the integer to the vector
        iNum -= 1  # Decrement the count of integers to read

    # Call the sort function to sort the vector of integers
    sort(vecIntValue)
