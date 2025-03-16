
import sys

class Main:
    # Method to search for a given key in a sorted array using binary search algorithm
    def find(self, array, key):
        # Check if the array is empty
        if len(array) == 0:
            raise Exception("Input array must not be empty.")

        # Check if the array is sorted
        if not self.isSorted(array):
            raise Exception("Input array must be sorted.")

        # Check if the key is null
        if key == None:
            raise Exception("Key must not be null.")

        # Initialize variables for Fibonacci sequence calculation
        fibMinus1 = 1
        fibMinus2 = 0
        fibNumber = fibMinus1 + fibMinus2

        # Get the length of the array
        n = len(array)

        # Use Fibonacci sequence to find the optimal search interval
        while fibNumber < n:
            fibMinus2 = fibMinus1
            fibMinus1 = fibNumber
            fibNumber = fibMinus1 + fibMinus2

        # Initialize an offset variable to keep track of the current position in the array
        offset = -1

        # Use Fibonacci sequence to find the position of the key in the array
        while fibNumber > 1:
            i = min(offset + fibMinus2, n - 1)

            # Compare the current element with the key and adjust the search interval accordingly
            if array[i].compareTo(key) < 0:
                fibNumber = fibMinus1
                fibMinus1 = fibMinus2
                fibMinus2 = fibNumber - fibMinus1
                offset = i
            elif array[i].compareTo(key) > 0:
                fibNumber = fibMinus2
                fibMinus1 = fibMinus1 - fibMinus2
                fibMinus2 = fibNumber - fibMinus1
            else:
                return i

        # Check if the key is located at the last position of the search interval
        if fibMinus1 == 1 and offset + 1 < n and array[offset + 1].compareTo(key) == 0:
            return offset + 1

        # Return -1 if the key is not found in the array
        return -1

    # Helper method to check if an array is sorted or not
    def isSorted(self, array):
        # Iterate through the array to check if it is sorted
        for i in range(1, len(array)):
            # Compare adjacent elements and return false if they are not in the correct order
            if array[i - 1].compareTo(array[i]) > 0:
                return False

        # Return true if the array is sorted
        return True

# Main method
if __name__ == "__main__":
    # Read the size of the array from the user input
    n = int(input())

    # Allocate memory for an array of Integer type with the given size
    array = [0] * n

    # Read the elements of the array from the user input
    for i in range(n):
        array[i] = int(input())

    # Read the key to be searched from the user input
    key = int(input())

    # Create an instance of the Main class to call the find() method
    searcher = Main()

    # Call the find() method to search for the key in the array
    index = searcher.find(array, key)

    # Print the index of the key in the array
    print(index)

