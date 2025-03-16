#!/usr/bin/python

# Step 1: Include necessary headers
# The code includes <iostream> and <vector> which are necessary for input and vector operations.

def sort(a_rvecIntValue):

    # Step 4: Sort function implementation
    # The sort function uses the insertion sort algorithm.
    # It iterates through the vector, inserting each element in the correct position.
    # It prints the vector after each insertion to show the progress of the sorting process.

    for i in range(len(a_rvecIntValue)):

        # If it's not the first element, insert it in the correct position
        if i != 0:
            iIntValue = a_rvecIntValue[i]
            j = i - 1
            while (j >= 0) and (a_rvecIntValue[j] > iIntValue):
                a_rvecIntValue[j+1] = a_rvecIntValue[j]
                j -= 1
            a_rvecIntValue[j+1] = iIntValue

        # Print the vector after each insertion
        for k in range(len(a_rvecIntValue)):
            print a_rvecIntValue[k],
        print

# Step 2: Define the sort function
# The `sort` function is defined to take a reference to a vector of integers.

def main():

    # Step 3: Main function
    # The main function reads the number of integers to be sorted.
    # It then reads each integer and stores them in a vector.
    # It calls the `sort` function with the vector.

    iNum = int(raw_input())
    vecIntValue = []
    while iNum:
        iIntValue = int(raw_input())
        vecIntValue.append(iIntValue)
        iNum -= 1

    sort(vecIntValue)

if __name__ == "__main__":
    main()

# Step 5: Output
# The program outputs the sorted vector after each insertion.


