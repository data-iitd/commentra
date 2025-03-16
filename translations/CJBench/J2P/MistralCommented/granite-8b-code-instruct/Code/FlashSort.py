
import sys

# Class definition for the Main class
class Main:
    # Class variable for the classification ratio
    classificationRatio = 0.45

    # Constructor with no arguments
    def __init__(self):
        pass

    # Constructor with a classification ratio argument
    def __init__(self, classificationRatio):
        # Initialize the classification ratio with the given value
        # If the classification ratio is not between 0 and 1, throw an exception
        if classificationRatio <= 0 or classificationRatio >= 1:
            raise ValueError("Classification ratio must be between 0 and 1 (exclusive).")
        self.classificationRatio = classificationRatio

    # Setter method for the classification ratio
    def setClassificationRatio(self, classificationRatio):
        # Initialize the classification ratio with the given value
        # If the classification ratio is not between 0 and 1, throw an exception
        if classificationRatio <= 0 or classificationRatio >= 1:
            raise ValueError("Classification ratio must be between 0 and 1 (exclusive).")
        self.classificationRatio = classificationRatio

    # Method to sort an array using the flash sort algorithm
    def sort(self, array):
        self.flashSort(array)
        return array

    # Private method to perform the flash sort algorithm on an array
    def flashSort(self, arr):
        # Base case: if the array is empty, return
        if len(arr) == 0:
            return

        # Find the minimum and maximum elements in the array
        min_val = min(arr)
        max_index = arr.index(max(arr))

        # If the minimum and maximum elements are the same, return
        if min_val == max(arr):
            return

        # Calculate the number of elements to classify based on the classification ratio
        m = int(self.classificationRatio * len(arr))

        # Create an array to store the classification results
        classification_array = [0] * m

        # Calculate the constant c1 for the flash sort algorithm
        c1 = (m - 1) / (max(arr) - min_val)

        # Perform the classify step of the flash sort algorithm
        self.classify(arr, classification_array, c1, min_val)

        # Perform the transform step of the flash sort algorithm
        self.transform(classification_array)

        # Perform the permute step of the flash sort algorithm
        self.permute(arr, classification_array, c1, min_val, len(arr), m)

        # Perform the insertion sort step of the flash sort algorithm
        self.insertionSort(arr)

    # Method to find the minimum element in an array
    def findMin(self, arr):
        # Initialize the minimum element to the first element in the array
        min_val = arr[0]

        # Iterate through the array to find the minimum element
        for num in arr:
            # If the current element is smaller than the minimum element, update the minimum element
            if num < min_val:
                min_val = num

        # Return the minimum element
        return min_val

    # Method to find the index of the maximum element in an array
    def findMaxIndex(self, arr):
        # Initialize the maximum index to the first index in the array
        max_index = 0

        # Iterate through the array to find the index of the maximum element
        for i in range(1, len(arr)):
            # If the current element is greater than the maximum element, update the maximum index
            if arr[i] > arr[max_index]:
                max_index = i

        # Return the index of the maximum element
        return max_index

    # Method to perform the classify step of the flash sort algorithm
    def classify(self, arr, classification_array, c1, min_val):
        # Iterate through the array to classify each element
        for num in arr:
            # Calculate the index in the classification array based on the comparison of the element and the minimum element
            k = int(c1 * (num - min_val))

            # Increment the corresponding index in the classification array
            classification_array[k] += 1

    # Method to perform the transform step of the flash sort algorithm
    def transform(self, classification_array):
        # Iterate through the classification array to calculate the cumulative sum of each index
        for i in range(1, len(classification_array)):
            classification_array[i] += classification_array[i - 1]

    # Method to perform the permute step of the flash sort algorithm
    def permute(self, arr, classification_array, c1, min_val, n, m):
        # Initialize variables for the move index, the index j, and the index k
        move = 0
        j = 0
        k = m - 1

        # Initialize a variable to store the flashed element
        flash = 0

        # Iterate through the array to perform the permute step
        while move < n - 1:
            # Iterate through the classification array to find the next element to swap
            while j > classification_array[k] - 1:
                j += 1
                k = int(c1 * (arr[j] - min_val))
            # Swap the current element with the element found in the classification array
            flash = arr[j]
            while j!= classification_array[k]:
                k = int(c1 * (flash - min_val))
                # Swap the elements at the indices found in the classification array
                arr[classification_array[k] - 1], flash = flash, arr[classification_array[k] - 1]
                # Decrement the index k in the classification array
                classification_array[k] -= 1
                # Increment the move index
                move += 1

    # Method to perform the insertion sort step of the flash sort algorithm
    def insertionSort(self, arr):
        # Iterate through the array to perform the insertion sort
        for i in range(1, len(arr)):
            key = arr[i]
            j = i - 1

            # Iterate through the array to find the position of the key element
            while j >= 0 and arr[j] > key:
                arr[j + 1] = arr[j]
                j -= 1

            # Insert the key element at its correct position
            arr[j + 1] = key

    # Main method to read input and call the sort method
    @staticmethod
    def main():
        # Initialize a Scanner object to read input from the standard input
        scanner = sys.stdin

        # Read the number of elements in the array from the standard input
        n = int(scanner.readline())

        # Create an array of integers with the given size
        array = [0] * n

        # Read each element of the array from the standard input
        for i in range(n):
            array[i] = int(scanner.readline())

        # Create a Main object and call the sort method to sort the array
        flash_sort = Main()
        flash_sort.sort(array)

        # Print the sorted array to the standard output
        for num in array:
            print(num, end=" ")

        # Close the Scanner object
        scanner.close()

# Call the main method to start the program
Main.main()

