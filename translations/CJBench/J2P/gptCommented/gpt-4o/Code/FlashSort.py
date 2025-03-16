class Main:
    # Default classification ratio for the sorting algorithm
    classification_ratio = 0.45

    # Default constructor
    def __init__(self, classification_ratio=None):
        if classification_ratio is not None:
            self.set_classification_ratio(classification_ratio)

    # Method to set the classification ratio with validation
    def set_classification_ratio(self, classification_ratio):
        if classification_ratio <= 0 or classification_ratio >= 1:
            raise ValueError("Classification ratio must be between 0 and 1 (exclusive).")
        self.classification_ratio = classification_ratio

    # Public method to sort an array using the flash sort algorithm
    def sort(self, array):
        self.flash_sort(array)  # Call the flash sort method
        return array  # Return the sorted array

    # Private method implementing the flash sort algorithm
    def flash_sort(self, arr):
        # Return if the array is empty
        if len(arr) == 0:
            return
        
        # Find the minimum value in the array
        min_val = self.find_min(arr)
        # Find the index of the maximum value in the array
        max_index = self.find_max_index(arr)
        
        # If the maximum value is equal to the minimum, no sorting is needed
        if arr[max_index] == min_val:
            return 

        # Calculate the size of the classification array based on the classification ratio
        m = int(self.classification_ratio * len(arr))
        classification_array = [0] * m  # Create the classification array
        c1 = (m - 1) / (arr[max_index] - min_val)  # Calculate the scaling factor

        # Classify the elements of the array into the classification array
        self.classify(arr, classification_array, c1, min_val)
        # Transform the classification array to cumulative counts
        self.transform(classification_array)
        # Permute the original array based on the classification array
        self.permute(arr, classification_array, c1, min_val, len(arr), m)
        # Finally, sort any remaining elements using insertion sort
        self.insertion_sort(arr)

    # Method to find the minimum element in the array
    def find_min(self, arr):
        return min(arr)  # Return the minimum element

    # Method to find the index of the maximum element in the array
    def find_max_index(self, arr):
        return arr.index(max(arr))  # Return the index of the maximum element

    # Method to classify elements into the classification array
    def classify(self, arr, classification_array, c1, min_val):
        for t in arr:
            # Calculate the index for classification based on the element's value
            k = int(c1 * (t - min_val))
            classification_array[k] += 1  # Increment the count in the classification array

    # Method to transform the classification array into cumulative counts
    def transform(self, classification_array):
        for i in range(1, len(classification_array)):
            classification_array[i] += classification_array[i - 1]  # Cumulative sum

    # Method to permute the original array based on the classification array
    def permute(self, arr, classification_array, c1, min_val, n, m):
        move = 0  # Counter for the number of moves
        j = 0  # Current index in the original array
        k = m - 1  # Current index in the classification array

        while move < n - 1:
            # Find the correct position for the current element
            while j > classification_array[k] - 1:
                j += 1
                k = int(c1 * (arr[j] - min_val))  # Update k based on the current element
            
            flash = arr[j]  # Store the current element
            # Swap elements until the current element is in the correct position
            while j != classification_array[k]:
                k = int(c1 * (flash - min_val))  # Find the new position for flash
                temp = arr[classification_array[k] - 1]  # Get the element at the new position
                arr[classification_array[k] - 1] = flash  # Place flash in the new position
                flash = temp  # Update flash to the element that was swapped out
                classification_array[k] -= 1  # Decrement the count in the classification array
                move += 1  # Increment the move counter

    # Method to perform insertion sort on the array
    def insertion_sort(self, arr):
        for i in range(1, len(arr)):
            key = arr[i]  # Element to be inserted
            j = i - 1  # Index of the last sorted element
            # Move elements that are greater than key to one position ahead
            while j >= 0 and arr[j] > key:
                arr[j + 1] = arr[j]
                j -= 1
            arr[j + 1] = key  # Insert the key in its correct position

# Main method to execute the program
if __name__ == "__main__":
    n = int(input())  # Read the number of elements
    array = list(map(int, input().split()))  # Read the elements into the array
    flash_sort = Main()  # Create an instance of Main
    flash_sort.sort(array)  # Sort the array using flash sort
    # Print the sorted array
    print(" ".join(map(str, array)))  # Print the sorted array
