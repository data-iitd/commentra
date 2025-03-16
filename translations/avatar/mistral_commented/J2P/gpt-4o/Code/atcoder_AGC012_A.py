# Importing the necessary modules
import sys

def main():
    # Reading the number of elements in the array from the standard input
    n = int(input())
    # Creating a list of size 3 times the number of elements
    array = [0] * (3 * n)

    # Initializing the array with input values
    for i in range(len(array)):
        array[i] = int(input())

    # Sorting the array in ascending order
    array.sort()

    head = len(array) - 2  # Index of the last element to be considered in the current iteration
    res = 0  # Result variable to store the sum of the last two elements in each subarray

    # Calculating the sum of the last two elements in each subarray of size n and adding it to the result
    for i in range(n):
        res += array[head]  # Adding the last element of the current subarray to the result
        head -= 2  # Decreasing the index of the last element by 2 to consider the next subarray

    # Printing the result
    print(res)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
