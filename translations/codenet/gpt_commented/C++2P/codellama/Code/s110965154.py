#!/usr/bin/python

# InsertionSort.py
#
# Created on: 2014/07/25
#      Author: WanWan1985

# Function prototype for the sorting function
def sort(a_rvecIntValue):
    # Iterate through each element in the vector
    for i in range(len(a_rvecIntValue)):
        # Check if we are not at the first element
        if i != 0:
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

        # Print the current state of the sorted portion of the vector
        for k in range(len(a_rvecIntValue)):
            print a_rvecIntValue[k], # Output the element
        print # New line after printing the current state

# Main function
def main():
    # Variable to hold the number of integers to be sorted
    iNum = 0
    # Read the number of integers from standard input
    iNum = int(raw_input())
    
    # Vector to store the integers
    vecIntValue = []
    
    # Loop to read integers from input and store them in the vector
    while iNum:
        # Read an integer
        iIntValue = int(raw_input())
        vecIntValue.append(iIntValue) # Add the integer to the vector
        iNum -= 1 # Decrement the count of integers to read

    # Call the sort function to sort the vector of integers
    sort(vecIntValue)

    return 0 # Exit the program

# Call the main function
main()

# 