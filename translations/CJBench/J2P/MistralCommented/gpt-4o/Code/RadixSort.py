def radix_sort(array):
    if len(array) == 0:  # Check if the array is empty
        return array
    check_for_negative_input(array)  # Check for negative integers in the array
    max_value = max(array)  # Find the maximum integer in the array
    exp = 1
    while max_value // exp > 0:  # Iterate through each digit in the integers
        counting_sort_by_digit(array, exp)  # Sort the array based on the current digit
        exp *= 10  # Move to the next digit

def check_for_negative_input(array):
    for number in array:  # Check for negative integers
        if number < 0:
            raise ValueError("Array contains negative integers.")  # Raise an exception if a negative integer is found

def counting_sort_by_digit(array, exp):
    count = [0] * 10  # Initialize a count array for digits 0-9
    output = [0] * len(array)  # Initialize an output array to store the sorted elements

    for i in range(len(array)):  # Count the frequency of each digit
        count[(array[i] // exp) % 10] += 1

    for i in range(1, 10):  # Calculate the cumulative frequency
        count[i] += count[i - 1]

    for i in range(len(array) - 1, -1, -1):  # Place the elements in their correct positions
        digit = (array[i] // exp) % 10
        output[count[digit] - 1] = array[i]
        count[digit] -= 1

    for i in range(len(array)):  # Copy the sorted elements back to the original array
        array[i] = output[i]

def main():
    n = int(input("Enter the number of elements: "))  # Read the number of elements
    array = list(map(int, input("Enter the elements: ").split()))  # Read the elements into an array

    radix_sort(array)  # Call the sorting method

    print("Sorted array:", ' '.join(map(str, array)))  # Print the sorted array

if __name__ == "__main__":
    main()  # Execute the main function

# <END-OF-CODE>
