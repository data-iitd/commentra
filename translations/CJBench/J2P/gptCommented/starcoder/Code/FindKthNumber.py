import random
import sys

# Private class to prevent instantiation of the class
class Main:
    # Random instance for selecting pivot in quick select algorithm
    RANDOM = random.Random()

    # Method to find the k-th largest element in the array
    def findKthMax(self, array, k):
        # Validate the value of k
        if k <= 0 or k > len(array):
            raise Exception("k must be between 1 and the size of the array")
        # Call quickSelect to find the k-th largest element
        return self.quickSelect(array, 0, len(array) - 1, len(array) - k)

    # QuickSelect algorithm to find the k-th smallest element
    def quickSelect(self, array, left, right, kSmallest):
        # Base case: if the list contains only one element
        if left == right:
            return array[left]
        # Randomly select a pivot index
        pivotIndex = left + self.RANDOM.randint(0, right - left)
        # Partition the array around the pivot
        pivotIndex = self.partition(array, left, right, pivotIndex)
        
        # Check if the pivot is the k-th smallest element
        if kSmallest == pivotIndex:
            return array[kSmallest]
        # If kSmallest is less than pivotIndex, search in the left subarray
        elif kSmallest < pivotIndex:
            return self.quickSelect(array, left, pivotIndex - 1, kSmallest)
        # If kSmallest is greater than pivotIndex, search in the right subarray
        else:
            return self.quickSelect(array, pivotIndex + 1, right, kSmallest)

    # Partition the array around a pivot
    def partition(self, array, left, right, pivotIndex):
        # Store the pivot value
        pivotValue = array[pivotIndex]
        # Move the pivot to the end of the array
        self.swap(array, pivotIndex, right)
        storeIndex = left
        
        # Rearrange the array elements based on the pivot value
        for i in range(left, right):
            if array[i] < pivotValue:
                self.swap(array, storeIndex, i)
                storeIndex += 1
        # Move the pivot to its final place
        self.swap(array, storeIndex, right)
        return storeIndex # Return the final index of the pivot

    # Helper method to swap two elements in the array
    def swap(self, array, i, j):
        temp = array[i]
        array[i] = array[j]
        array[j] = temp

    # Main method to execute the program
    def main(self):
        # Read the size of the array
        n = int(input())
        # Validate the size of the array
        if n <= 0:
            print("Array size must be positive.")
            return
        # Initialize the array and read its elements
        array = [0] * n
        for i in range(n):
            array[i] = int(input())
        # Read the value of k
        k = int(input())
        # Validate the value of k
        if k <= 0 or k > n:
            print("Error: k must be between 1 and the size of the array.")
            return
        # Find the k-th largest element and print the result
        result = self.findKthMax(array, k)
        print("The " + str(k) + "-th largest element is: " + str(result))

# Main method to execute the program
if __name__ == "__main__":
    Main().main()

