
import sys

# Constant for the base used in radix sort
BASE = 10

# Private function to check if the array contains negative integers
def check_for_negative_input(array):
    for number in array:
        # Throw an exception if a negative integer is found
        if number < 0:
            raise ValueError("Array contains negative integers.")

# Private function to perform radix sort on the array
def radix_sort(array):
    # Find the maximum number to determine the number of digits
    max = max(array)
    
    # Perform counting sort for each digit, starting from the least significant digit
    for exp in range(1, int(max / BASE) + 1):
        counting_sort_by_digit(array, exp)

# Private function to perform counting sort based on the digit represented by exp
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
    array[:] = output

# Main function to sort the array using radix sort
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

# Main function to read input from the user
def main():
    # Read the number of elements in the array
    n = int(input())
    
    # Initialize the array with the specified size
    array = [0] * n
    
    # Read the elements of the array from user input
    for i in range(n):
        array[i] = int(input())
    
    # Sort the array using the sort method
    array = sort(array)
    
    # Print the sorted array
    for num in array:
        print(num, end=" ")
    print()

# Main function to run the program
if __name__ == "__main__":
    main()

# END-OF-CODE
