

import sys

BASE = 10  # Base for radix sort

def sort(array):
    if len(array) == 0:  # Check if the array is empty and return it if true
        return array
    check_for_negative_input(array)  # Check for negative integers in the array and throw an exception if found
    radix_sort(array)  # Call the radix sorting method to sort the array
    return array  # Return the sorted array

def check_for_negative_input(array):
    for number in array:  # Iterate through the array to check for negative integers
        if number < 0:
            raise ValueError("Array contains negative integers.")  # Throw an exception if a negative integer is found

def radix_sort(array):
    max_ = max(array)  # Find the maximum integer in the array
    for exp in range(1, max_ // BASE + 1):  # Iterate through each digit in the integers
        counting_sort_by_digit(array, exp)  # Call the counting sort method to sort the array based on the current digit

def counting_sort_by_digit(array, exp):
    count = [0] * BASE  # Initialize a count array to store the frequency of each digit
    output = [0] * len(array)  # Initialize an output array to store the sorted elements

    for i in range(len(array)):  # Iterate through the array to count the frequency of each digit
        count[(array[i] // exp) % BASE] += 1  # Increment the count of the digit at the current index

    for i in range(1, BASE):  # Iterate through the count array to calculate the total frequency of each digit
        count[i] += count[i - 1]  # Add the frequency of the current digit to the frequency of the previous digit

    for i in range(len(array) - 1, -1, -1):  # Iterate through the array in reverse order to place the elements in their correct positions
        digit = (array[i] // exp) % BASE  # Extract the digit at the current index
        output[count[digit] - 1] = array[i]  # Place the element at the correct position in the output array
        count[digit] -= 1  # Decrement the count of the current digit to place the next element

    array[:] = output  # Copy the sorted elements from the output array to the original array

if __name__ == "__main__":
    n = int(input())  # Read the number of elements in the array from user input
    array = [int(input()) for _ in range(n)]  # Create an integer array with the given size and read user input
    sort(array)  # Call the sorting method to sort the array
    print(*array)  # Print all elements of the sorted array separated by a space

Translate the above Python code to C++ and end with comment "