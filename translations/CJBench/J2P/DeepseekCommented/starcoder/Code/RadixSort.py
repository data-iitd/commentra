import java.util.Arrays; // Importing Arrays utility for array operations
import java.util.Scanner; // Importing Scanner for reading input

def sort(array):
    if (array.length == 0):
        return array; # Return array if it's empty
    checkForNegativeInput(array); # Check for negative integers
    radixSort(array); # Perform radix sort
    return array; # Return sorted array

def checkForNegativeInput(array):
    for number in array:
        if (number < 0):
            raise Exception("Array contains negative integers."); # Throw exception if negative integer found

def radixSort(array):
    max = max(array) # Find maximum value in the array
    for exp in range(1, max / exp + 1): # Loop through each digit place
        countingSortByDigit(array, exp) # Perform counting sort for the current digit place

def countingSortByDigit(array, exp):
    count = [0] * BASE # Array to store count of each digit
    output = [0] * array.length # Array to store sorted output
    for i in range(array.length):
        count[(array[i] / exp) % BASE] += 1 # Count occurrences of each digit
    for i in range(1, BASE):
        count[i] += count[i - 1] # Calculate cumulative count
    for i in range(array.length - 1, -1, -1):
        digit = (array[i] / exp) % BASE
        output[count[digit] - 1] = array[i] # Place elements in output array
        count[digit] -= 1 # Decrement count for the digit
    array = output

def max(array):
    return max(array)

def main():
    scanner = Scanner(System.in) # Initialize scanner for input
    n = scanner.nextInt() # Read number of elements
    array = [0] * n # Initialize array of size n
    for i in range(n):
        array[i] = scanner.nextInt() # Read elements into array
    array = sort(array) # Sort the array
    for num in array:
        print(num, end=" ") # Print sorted array
    print()
    scanner.close() # Close the scanner

if __name__ == "__main__":
    main()

