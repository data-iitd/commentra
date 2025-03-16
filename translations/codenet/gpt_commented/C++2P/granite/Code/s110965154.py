
# InsertionSort.py

# Function to perform insertion sort on a list of integers
def sort(a_rvecIntValue):
    # Iterate through each element in the list
    for i in range(len(a_rvecIntValue)):
        # Check if we are not at the first element
        if i!= 0:
            # Store the current element to be inserted
            iIntValue = a_rvecIntValue[i]
            j = i - 1 # Start comparing with the previous element
            
            # Move elements of a_rvecIntValue[0..i-1], that are greater than iIntValue,
            # to one position ahead of their current position
            while (j >= 0) and (a_rvecIntValue[j] > iIntValue):
                a_rvecIntValue[j + 1] = a_rvecIntValue[j] # Shift element to the right
                j -= 1 # Move to the previous element
            # Place the current element at its correct position
            a_rvecIntValue[j + 1] = iIntValue
        # Print the current state of the sorted portion of the list
        for k in range(len(a_rvecIntValue)):
            print(a_rvecIntValue[k], end=" ") # Output the element
        print() # New line after printing the current state

# Main function to read the number of integers and sort them
def main():
    # Variable to hold the number of integers to be sorted
    iNum = 0
    # Read the number of integers from standard input
    iNum = int(input())
    
    # List to store the integers
    vecIntValue = []
    
    # Loop to read integers from input and store them in the list
    for i in range(iNum):
        iIntValue = int(input()) # Read an integer
        vecIntValue.append(iIntValue) # Add the integer to the list
    
    # Call the sort function to sort the list of integers
    sort(vecIntValue)

# Call the main function to start the program
if __name__ == "__main__":
    main()

