# Step 1: Include necessary headers
# The code includes <iostream> and <vector> which are necessary for input and vector operations.

def sort(a_rvecIntValue):

    # Step 4: Sort function implementation
    # The sort function uses the insertion sort algorithm.
    # It iterates through the vector, inserting each element in the correct position.
    # It prints the vector after each insertion to show the progress of the sorting process.

    for i in range(0, len(a_rvecIntValue)):

        # If it's not the first element, insert it in the correct position
        if (i!= 0):
            iIntValue = a_rvecIntValue[i]
            j = i - 1
            while ((j >= 0) and (a_rvecIntValue[j] > iIntValue)):
                a_rvecIntValue[j+1] = a_rvecIntValue[j]
                j = j - 1
            a_rvecIntValue[j+1] = iIntValue

        # Print the vector after each insertion
        for k in range(0, len(a_rvecIntValue)):
            print(a_rvecIntValue[k], end = " ")
        print()

# Step 5: Output
# The program outputs the sorted vector after each insertion.

