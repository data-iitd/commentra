# Import necessary modules
from typing import List

# Define the main function
def main():
    # Initialize input
    n = int(input())  # Read the number of test cases
    a = int(input())  # Read the number of elements in the first list
    b = int(input())  # Read the number of elements in the second list

    # Create lists to store the elements
    list1 = []
    list2 = []

    # Read and store the elements of the first and second lists
    for _ in range(a):
        list1.append(int(input()))  # Read and add an element to list1
    for _ in range(b):
        list2.append(int(input()))  # Read and add an element to list2

    # Iterate through the input range and print the corresponding number based on the presence of the element in list1
    for i in range(n):
        if (i + 1) in list1:  # Check if the current input element is present in list1
            print(1, end=" ")  # If present, print 1
        else:
            print(2, end=" ")  # If not present, print 2

# Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
