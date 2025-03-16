
#!/usr/bin/python
# -*- coding: utf-8 -*-

# InsertionSort.py
#
# Created on: 2014/07/25
#     Author: WanWan1985

# Function to sort the vector in ascending order using insertion sort algorithm
def sort(vecIntValue):

    # Iterate through each element in the vector starting from the second element
    for i in range(len(vecIntValue)):
        if i != 0: # Check if we are not at the first element

            iIntValue = vecIntValue[i] # Get the value of the current element
            j = i - 1 # Initialize a variable to store the index of the previous element
            while (j >= 0) and (vecIntValue[j] > iIntValue): # While the previous element is greater than the current element
                vecIntValue[j+1] = vecIntValue[j] # Swap the previous and next elements
                j -= 1 # Decrement the index of the previous element
            vecIntValue[j+1] = iIntValue # Place the current element at its correct position

        # Print the sorted vector after each insertion
        for k in range(len(vecIntValue)):
            print vecIntValue[k], # Print the value of the current element
        print # Print a newline after each pass

# Main function
if __name__ == "__main__":

    iNum = 0 # Initialize a variable to store the number of elements in the vector
    iNum = int(raw_input()) # Read the number of elements from the standard input

    vecIntValue = [] # Create an empty vector to store the integers
    while iNum: # While the number of elements is not zero
        iIntValue = 0 # Initialize a variable to store the next integer to be added to the vector
        iIntValue = int(raw_input()) # Read the next integer from the standard input
        vecIntValue.append(iIntValue) # Add the integer to the vector
        iNum -= 1 # Decrement the counter

    # Call the sorting function to sort the vector
    sort(vecIntValue)

# END-OF-CODE
