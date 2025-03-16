import sys

# Constant for the base used in radix sort
BASE = 10

def main():
    # Read the number of elements in the array
    n = int(input())
    
    # Initialize the array with the specified size
    array = list(map(int, input().split()))
    
    # Sort the array using the sort method
    sorted_array = sort(array)
    
    # Print the sorted array
    print(" ".join(map(str, sorted_array)))

def sort(array):
    # Return the array immediately if it is empty
    if len(array) == 0:
        return array
    
    # Check for negative integers in the array
    check_for_negative_input(array)
    
    # Perform radix sort on the array
    radix_sort(array)
    
    # Return the sorted array
    return array

def check_for_negative_input(array):
    for number in array:
        # Raise an exception if a negative integer is found
        if number < 0:
            raise ValueError("Array contains negative integers.")

def radix_sort(array):
    # Find the maximum number to determine the number of digits
    max_num = max(array)
    
    # Perform counting sort for each digit, starting from the least significant digit
    exp = 1
    while max_num // exp > 0:
        counting_sort_by_digit(array, exp)
        exp *= BASE

def counting_sort_by_digit(array, exp):
    # Create a count array to store the count of occurrences of each digit
    count = [0] * BASE
    # Create an output array to hold the sorted elements
    output = [0] * len(array)
    
    # Count occurrences of each digit in the specified place value
    for i in range(len(array)):
        count[(array[i] // exp) % BASE] += 1
    
    # Update the count array to contain the actual positions of digits
    for i in range(1, BASE):
        count[i] += count[i - 1]
    
    # Build the output array by placing elements in the correct order
    for i in range(len(array) - 1, -1, -1):
        digit = (array[i] // exp) % BASE
        output[count[digit] - 1] = array[i]
        count[digit] -= 1
    
    # Copy the sorted output array back to the original array
    for i in range(len(array)):
        array[i] = output[i]

if __name__ == "__main__":
    main()

# <END-OF-CODE>
