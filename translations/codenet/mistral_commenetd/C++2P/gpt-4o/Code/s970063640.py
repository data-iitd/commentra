# Import the necessary library for sorting
from typing import List

def main():
    # Declare and initialize variables
    n = int(input())  # Read the number of elements from the user
    a = int(input())  # Read the size of the subarray from the user
    sum = 0  # Initialize the sum variable to zero
    s = []  # Declare a list to store the input elements

    # Read the elements of the array from the user
    for _ in range(n):
        s.append(int(input()))  # Read the element and append to the list

    # Sort the array in ascending order
    s.sort()  # Sort the list using the sort method

    # Calculate the sum of the last 'a' elements of the sorted array
    for i in range(n - 1, n - a - 1, -1):
        sum += s[i]  # Add the current element to the sum

    # Print the result
    print(sum)  # Print the sum of the last 'a' elements

if __name__ == "__main__":
    main()  # Call the main function

# <END-OF-CODE>
