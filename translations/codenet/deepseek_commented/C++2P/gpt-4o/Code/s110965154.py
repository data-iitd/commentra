# InsertionSort.py

def sort(a_rvecIntValue):
    # Step 4: Sort function implementation
    # The sort function uses the insertion sort algorithm.
    # It iterates through the list, inserting each element in the correct position.
    # It prints the list after each insertion to show the progress of the sorting process.

    for i in range(len(a_rvecIntValue)):
        # If it's not the first element, insert it in the correct position
        if i != 0:
            iIntValue = a_rvecIntValue[i]
            j = i - 1
            while j >= 0 and a_rvecIntValue[j] > iIntValue:
                a_rvecIntValue[j + 1] = a_rvecIntValue[j]
                j -= 1
            a_rvecIntValue[j + 1] = iIntValue

        # Print the list after each insertion
        print(" ".join(map(str, a_rvecIntValue)))

def main():
    # Step 3: Main function
    # The main function reads the number of integers to be sorted.
    # It then reads each integer and stores them in a list.
    # It calls the `sort` function with the list.

    iNum = int(input())
    vecIntValue = []
    while iNum:
        iIntValue = int(input())
        vecIntValue.append(iIntValue)
        iNum -= 1

    sort(vecIntValue)

if __name__ == "__main__":
    main()

# Step 5: Output
# The program outputs the sorted list after each insertion.

# <END-OF-CODE>
