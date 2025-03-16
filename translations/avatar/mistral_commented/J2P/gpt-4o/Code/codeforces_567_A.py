# Importing necessary modules
import sys

def main():
    # Asking user for the size of the array and initializing it
    a = int(input("Enter the size of the array: "))
    ar = [0] * a  # Initializing the array

    # Reading array elements from user input
    for i in range(a):
        ar[i] = int(input("Enter element {}: ".format(i + 1)))

    # Initializing variables for storing maximum and minimum differences
    max_diff = 0
    min_diff = 0

    # Finding maximum and minimum differences between consecutive elements in the array
    for i in range(a):
        # Finding maximum difference between current element and first element
        max_diff = max(ar[i] - ar[0], ar[-1] - ar[i])

        # Finding minimum difference between current element and previous element
        if i == 0:
            min_diff = ar[i + 1] - ar[i]  # For the first element
        elif i == a - 1:
            min_diff = ar[i] - ar[i - 1]  # For the last element
        else:
            min_diff = min(ar[i] - ar[i - 1], ar[i + 1] - ar[i])  # For other elements

        # Printing minimum and maximum differences for each pair of consecutive elements
        print(min_diff, max_diff)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
