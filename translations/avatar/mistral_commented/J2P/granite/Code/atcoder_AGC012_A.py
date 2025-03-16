

import sys
import math

# Main method is the entry point of the Python application
def main():
    n = int(input())  # Reading the number of elements in the array from the standard input
    array = list(map(int, input().split()))  # Reading the array elements from the standard input and converting them to integers

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

These comments should provide a clear understanding of what each part of the code does. Let me know if you need any further assistance!