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
            raise Exception("Classification ratio must be between 0 and 1 (exclusive).")
        self.classificationRatio = classificationRatio

    # Setter method for the classification ratio
    def setClassificationRatio(self, classificationRatio):
        # Initialize the classification ratio with the given value
        # If the classification ratio is not between 0 and 1, throw an exception
        if classificationRatio <= 0 or classificationRatio >= 1:
            raise Exception("Classification ratio must be between 0 and 1 (exclusive).")
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
        min = self.findMin(arr)
        maxIndex = self.findMaxIndex(arr)

        # If the minimum and maximum elements are the same, return
        if arr[maxIndex] == min:
            return

        # Calculate the number of elements to classify based on the classification ratio
        m = int(self.classificationRatio * len(arr))

        # Create an array to store the classification results
        classificationArray = [0] * m

        # Calculate the constant c1 for the flash sort algorithm
        c1 = (m - 1) / arr[maxIndex] - min

        # Perform the classify step of the flash sort algorithm
        self.classify(arr, classificationArray, c1, min)

        # Perform the transform step of the flash sort algorithm
        self.transform(classificationArray)

        # Perform the permute step of the flash sort algorithm
        self.permute(arr, classificationArray, c1, min, len(arr), m)

        # Perform the insertion sort step of the flash sort algorithm
        self.insertionSort(arr)

    # Method to find the minimum element in an array
    def findMin(self, arr):
        # Initialize the minimum element to the first element in the array
        min = arr[0]

        # Iterate through the array to find the minimum element
        for t in arr:
            # If the current element is smaller than the minimum element, update the minimum element
            if t < min:
                min = t

        # Return the minimum element
        return min

    # Method to find the index of the maximum element in an array
    def findMaxIndex(self, arr):
        # Initialize the maximum index to the first index in the array
        maxIndex = 0

        # Iterate through the array to find the index of the maximum element
        for i in range(1, len(arr)):
            # If the current element is greater than the maximum element, update the maximum index
            if arr[i] > arr[maxIndex]:
                maxIndex = i

        # Return the index of the maximum element
        return maxIndex

    # Method to perform the classify step of the flash sort algorithm
    def classify(self, arr, classificationArray, c1, min):
        # Iterate through the array to classify each element
        for t in arr:
            # Calculate the index in the classification array based on the comparison of the element and the minimum element
            k = int(c1 * (t - min))

            # Increment the corresponding index in the classification array
            classificationArray[k] += 1

    # Method to perform the transform step of the flash sort algorithm
    def transform(self, classificationArray):
        # Iterate through the classification array to calculate the cumulative sum of each index
        for i in range(1, len(classificationArray)):
            classificationArray[i] += classificationArray[i - 1]

    # Method to perform the permute step of the flash sort algorithm
    def permute(self, arr, classificationArray, c1, min, n, m):
        # Initialize variables for the move index, the index j, and the index k
        move = 0
        j = 0
        k = m - 1

        # Initialize a variable to store the flashed element
        flash = None

        # Iterate through the array to perform the permute step
        while move < n - 1:
            # Iterate through the classification array to find the next element to swap
            while j > classificationArray[k] - 1:
                j += 1
                k = int(c1 * (arr[j] - min))

            # Swap the current element with the element found in the classification array
            while j!= classificationArray[k]:
                k = int(c1 * (flash - min))
                # Swap the elements at the indices found in the classification array
                temp = arr[classificationArray[k] - 1]
                arr[classificationArray[k] - 1] = flash
                flash = temp
                # Decrement the index k in the classification array
                classificationArray[k] -= 1
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
if __name__ == "__main__":
    # Initialize a Scanner object to read input from the standard input
    scanner = Scanner(sys.stdin)

    # Read the number of elements in the array from the standard input
    n = scanner.nextInt()

    # Create an array of integers with the given size
    array = [0] * n

    # Read each element of the array from the standard input
    for i in range(0, n):
        array[i] = scanner.nextInt()

    # Create a Main object and call the sort method to sort the array
    flashSort = Main()
    flashSort.sort(array)

    # Print the sorted array to the standard output
    for num in array:
        print(num, end=" ")

    # Close the Scanner object
    scanner.close()

