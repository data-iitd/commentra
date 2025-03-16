

# InsertionSort.py

# Function to sort the list in ascending order using insertion sort algorithm
def sort(a_rlistIntValue):

    # Iterate through each element in the list starting from the second element
    for i in range(1, len(a_rlistIntValue)):
        if i!= 0: # Check if we are not at the first element
            int_value = a_rlistIntValue[i] # Get the value of the current element
            j = i - 1 # Initialize a variable to store the index of the previous element
            while (j >= 0) and (a_rlistIntValue[j] > int_value): # While the previous element is greater than the current element
                a_rlistIntValue[j+1] = a_rlistIntValue[j] # Swap the previous and next elements
                j -= 1 # Decrement the index of the previous element
            a_rlistIntValue[j+1] = int_value # Place the current element at its correct position

        # Print the sorted list after each insertion
        for k in range(len(a_rlistIntValue)):
            print(a_rlistIntValue[k], end=" ") # Print the value of the current element
        print() # Print a newline after each pass

if __name__ == "__main__":

    int_num = int(input("Enter the number of elements: ")) # Read the number of elements from the standard input

    list_int_value = [] # Create an empty list to store the integers
    for i in range(int_num):
        int_value = int(input("Enter the next integer: ")) # Read the next integer from the standard input
        list_int_value.append(int_value) # Add the integer to the list

    # Call the sorting function to sort the list
    sort(list_int_value)

