import array // Importing array for array operations
import sys // Importing sys for reading input

def main():
    n = int(sys.stdin.readline()) // Read number of elements
    array = array.array("i", [int(i) for i in sys.stdin.readline().split()]) // Read elements into array
    sort(array) // Sort the array
    for num in array:
        print(num, end=" ") // Print sorted array
    print()

def sort(array):
    if len(array) == 0:
        return array // Return array if it's empty
    checkForNegativeInput(array) // Check for negative integers
    radixSort(array) // Perform radix sort
    return array // Return sorted array

def checkForNegativeInput(array):
    for number in array:
        if number < 0:
            raise ValueError("Array contains negative integers.") // Throw exception if negative integer found

def radixSort(array):
    max = max(array) // Find maximum value in the array
    for exp in range(1, int(max / 10) + 1): // Loop through each digit place
        countingSortByDigit(array, exp) // Perform counting sort for the current digit place

def countingSortByDigit(array, exp):
    count = [0] * 10 // Array to store count of each digit
    output = [0] * len(array) // Array to store sorted output
    for i in range(len(array)):
        count[(array[i] // exp) % 10] += 1 // Count occurrences of each digit
    for i in range(1, 10):
        count[i] += count[i - 1] // Calculate cumulative count
    for i in range(len(array) - 1, -1, -1):
        digit = (array[i] // exp) % 10
        output[count[digit] - 1] = array[i] // Place elements in output array
        count[digit] -= 1 // Decrement count for the digit
    array[:] = output // Copy output array back to original array

if __name__ == "__main__":
    main()

