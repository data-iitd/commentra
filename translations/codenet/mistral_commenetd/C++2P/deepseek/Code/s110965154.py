def sort(a_rvecIntValue):
    # Iterate through each element in the vector starting from the second element
    for i in range(len(a_rvecIntValue)):
        if i != 0:  # Check if we are not at the first element
            iIntValue = a_rvecIntValue[i]  # Get the value of the current element
            j = i - 1  # Initialize a variable to store the index of the previous element
            while j >= 0 and a_rvecIntValue[j] > iIntValue:  # While the previous element is greater than the current element
                a_rvecIntValue[j + 1] = a_rvecIntValue[j]  # Swap the previous and next elements
                j -= 1  # Decrement the index of the previous element
            a_rvecIntValue[j + 1] = iIntValue  # Place the current element at its correct position
 
        # Print the sorted vector after each insertion
        print(" ".join(map(str, a_rvecIntValue)))

# Main function to read input and call the sorting function
def main():
    iNum = int(input())  # Read the number of elements from the standard input
    vecIntValue = []  # Create an empty list to store the integers
    while iNum > 0:
        iIntValue = int(input())  # Read the next integer from the standard input
        vecIntValue.append(iIntValue)  # Add the integer to the list
        iNum -= 1  # Decrement the counter
 
    # Call the sorting function to sort the list
    sort(vecIntValue)

# Call the main function
main()
