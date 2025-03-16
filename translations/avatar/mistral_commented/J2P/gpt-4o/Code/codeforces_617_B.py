# Importing the necessary library for input
from typing import List

def main():
    n = int(input())  # Reading the first integer from the input as the size of the array

    arr = []  # Creating an empty list to store the indices of the 1's in the input

    for i in range(n):  # Loop through the input to find the indices of the 1's
        if int(input()) == 1:
            arr.append(i)  # If the current input is 1, add its index to the list

    if not arr:  # Check if the list is empty
        print(0)  # If it is, print 0 as the output
    else:
        result = 1  # Initialize the result variable to 1

        for i in range(1, len(arr)):  # Loop through the list to calculate the result
            result *= arr[i] - arr[i - 1]  # Multiply the difference between two consecutive indices to the result

        print(result)  # Print the result as the output

if __name__ == "__main__":
    main()

# <END-OF-CODE>
