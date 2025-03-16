
import sys

BASE = 10  # Constant for radix sort base

def sort(array):
    if len(array) == 0:
        return array  # Return array if it's empty
    check_for_negative_input(array)  # Check for negative integers
    radix_sort(array)  # Perform radix sort
    return array  # Return sorted array

def check_for_negative_input(array):
    for number in array:
        if number < 0:
            raise ValueError("Array contains negative integers.")  # Throw exception if negative integer found

def radix_sort(array):
    max_value = max(array)  # Find maximum value in the array
    for exp in range(1, max_value // BASE + 1):  # Loop through each digit place
        counting_sort_by_digit(array, exp)  # Perform counting sort for the current digit place

def counting_sort_by_digit(array, exp):
    count = [0] * BASE  # Array to store count of each digit
    output = [0] * len(array)  # Array to store sorted output
    for i in range(len(array)):
        count[(array[i] // exp) % BASE] += 1  # Count occurrences of each digit
    for i in range(1, BASE):
        count[i] += count[i - 1]  # Calculate cumulative count
    for i in range(len(array) - 1, -1, -1):
        digit = (array[i] // exp) % BASE
        output[count[digit] - 1] = array[i]  # Place elements in output array
        count[digit] -= 1  # Decrement count for the digit
    array[:] = output  # Copy output array back to original array

if __name__ == "__main__":
    n = int(input())  # Read number of elements
    array = [int(x) for x in input().split()]  # Read elements into array
    sort(array)  # Sort the array
    print(*array)  # Print sorted array

