
# InsertionSort.py

# <START-OF-CODE>

# Function to sort the vector in ascending order using insertion sort algorithm
def sort(a_rvecIntValue):

    # Iterate through each element in the vector starting from the second element
    for i in range(0, len(a_rvecIntValue)):
        if i!= 0: # Check if we are not at the first element

            iIntValue = a_rvecIntValue[i] # Get the value of the current element
            j = i - 1 # Initialize a variable to store the index of the previous element
            while ((j >= 0) and (a_rvecIntValue[j] > iIntValue)): # While the previous element is greater than the current element
                a_rvecIntValue[j+1] = a_rvecIntValue[j] # Swap the previous and next elements
                j = j - 1 # Decrement the index of the previous element
            a_rvecIntValue[j+1] = iIntValue # Place the current element at its correct position

        # Print the sorted vector after each insertion
        for k in range(0, len(a_rvecIntValue)):
            print(a_rvecIntValue[k], end = " ") # Print the value of the current element
            if k!= len(a_rvecIntValue) - 1: # Check if we are not at the last element
                print(" ", end = "") # Print a space if not
            else:
                print("") # Print a newline after each pass

# Main function
if __name__ == "__main__":

    iNum = int(input()) # Read the number of elements from the standard input

    vecIntValue = [] # Create an empty vector to store the integers
    while iNum:
        iIntValue = int(input()) # Read the next integer from the standard input
        vecIntValue.append(iIntValue) # Add the integer to the vector
        iNum = iNum - 1 # Decrement the counter

    # Call the sorting function to sort the vector
    sort(vecIntValue)

# 