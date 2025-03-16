import java.util.Scanner;
import java.util.Arrays;

class Main:
    # Default classification ratio for the sorting algorithm
    classificationRatio = 0.45

    # Default constructor
    def __init__(self):
        pass

    # Constructor that allows setting a custom classification ratio
    def __init__(self, classificationRatio):
        # Validate the classification ratio to ensure it's between 0 and 1
        if (classificationRatio <= 0 or classificationRatio >= 1):
            raise Exception("Classification ratio must be between 0 and 1 (exclusive).")
        self.classificationRatio = classificationRatio

    # Method to set the classification ratio with validation
    def setClassificationRatio(self, classificationRatio):
        if (classificationRatio <= 0 or classificationRatio >= 1):
            raise Exception("Classification ratio must be between 0 and 1 (exclusive).")
        self.classificationRatio = classificationRatio

    # Public method to sort an array using the flash sort algorithm
    def sort(self, array):
        self.flashSort(array) # Call the flash sort method
        return array # Return the sorted array

    # Private method implementing the flash sort algorithm
    def flashSort(self, arr):
        # Return if the array is empty
        if (arr.length == 0):
            return;

        # Find the minimum value in the array
        min = self.findMin(arr)
        # Find the index of the maximum value in the array
        maxIndex = self.findMaxIndex(arr)

        # If the maximum value is equal to the minimum, no sorting is needed
        if (arr[maxIndex].compareTo(min) == 0):
            return;

        # Calculate the size of the classification array based on the classification ratio
        m = (int) (self.classificationRatio * arr.length)
        classificationArray = [0] * m # Create the classification array
        c1 = (double) (m - 1) / arr[maxIndex].compareTo(min) # Calculate the scaling factor

        # Classify the elements of the array into the classification array
        self.classify(arr, classificationArray, c1, min)
        # Transform the classification array to cumulative counts
        self.transform(classificationArray)
        # Permute the original array based on the classification array
        self.permute(arr, classificationArray, c1, min, arr.length, m)
        # Finally, sort any remaining elements using insertion sort
        self.insertionSort(arr)

    # Method to find the minimum element in the array
    def findMin(self, arr):
        min = arr[0] # Assume the first element is the minimum
        for t in arr:
            # Update min if a smaller element is found
            if (t.compareTo(min) < 0):
                min = t
        return min # Return the minimum element

    # Method to find the index of the maximum element in the array
    def findMaxIndex(self, arr):
        maxIndex = 0 # Start with the first index as the maximum
        for i in range(1, arr.length):
            # Update maxIndex if a larger element is found
            if (arr[i].compareTo(arr[maxIndex]) > 0):
                maxIndex = i
        return maxIndex # Return the index of the maximum element

    # Method to classify elements into the classification array
    def classify(self, arr, classificationArray, c1, min):
        for t in arr:
            # Calculate the index for classification based on the element's value
            k = (int) (c1 * t.compareTo(min))
            classificationArray[k] += 1 # Increment the count in the classification array

    # Method to transform the classification array into cumulative counts
    def transform(self, classificationArray):
        for i in range(1, classificationArray.length):
            classificationArray[i] += classificationArray[i - 1] # Cumulative sum

    # Method to permute the original array based on the classification array
    def permute(self, arr, classificationArray, c1, min, n, m):
        move = 0 # Counter for the number of moves
        j = 0 # Current index in the original array
        k = m - 1 # Current index in the classification array
        flash = None # Temporary variable for swapping

        # Loop until all elements have been moved
        while (move < n - 1):
            # Find the correct position for the current element
            while (j > classificationArray[k] - 1):
                j += 1
                k = (int) (c1 * arr[j].compareTo(min)) # Update k based on the current element
            flash = arr[j] # Store the current element
            # Swap elements until the current element is in the correct position
            while (j!= classificationArray[k]):
                k = (int) (c1 * flash.compareTo(min)) # Find the new position for flash
                temp = arr[classificationArray[k] - 1] # Get the element at the new position
                arr[classificationArray[k] - 1] = flash # Place flash in the new position
                flash = temp # Update flash to the element that was swapped out
                classificationArray[k] -= 1 # Decrement the count in the classification array
                move += 1 # Increment the move counter

    # Method to perform insertion sort on the array
    def insertionSort(self, arr):
        for i in range(1, arr.length):
            key = arr[i] # Element to be inserted
            j = i - 1 # Index of the last sorted element
            # Move elements that are greater than key to one position ahead
            while (j >= 0 and arr[j].compareTo(key) > 0):
                arr[j + 1] = arr[j]
                j -= 1
            arr[j + 1] = key # Insert the key in its correct position

# Main method to execute the program
if __name__ == "__main__":
    scanner = Scanner(System.in) # Create a scanner for input
    n = scanner.nextInt() # Read the number of elements
    array = [0] * n # Create an array of integers
    # Read the elements into the array
    for i in range(0, n):
        array[i] = scanner.nextInt()
    flashSort = Main() # Create an instance of Main
    flashSort.sort(array) # Sort the array using flash sort
    # Print the sorted array
    for num in array:
        print(num, end=" ")
    scanner.close() # Close the scanner

