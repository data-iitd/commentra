# InsertionSort.py

def sort(a_rvecIntValue):
    # Iterate through each element in the list starting from the second element
    for i in range(len(a_rvecIntValue)):
        if i != 0:  # Check if we are not at the first element
            iIntValue = a_rvecIntValue[i]  # Get the value of the current element
            j = i - 1  # Initialize a variable to store the index of the previous element
            while j >= 0 and a_rvecIntValue[j] > iIntValue:  # While the previous element is greater than the current element
                a_rvecIntValue[j + 1] = a_rvecIntValue[j]  # Swap the previous and next elements
                j -= 1  # Decrement the index of the previous element
            a_rvecIntValue[j + 1] = iIntValue  # Place the current element at its correct position

        # Print the sorted list after each insertion
        print(" ".join(map(str, a_rvecIntValue)))  # Print the current state of the list

def main():
    iNum = int(input())  # Read the number of elements from the standard input
    vecIntValue = []  # Create an empty list to store the integers
    for _ in range(iNum):
        iIntValue = int(input())  # Read the next integer from the standard input
        vecIntValue.append(iIntValue)  # Add the integer to the list

    # Call the sorting function to sort the list
    sort(vecIntValue)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
