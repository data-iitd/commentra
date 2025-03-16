import random

class Main:
    # Private constructor to prevent instantiation of the class
    def __init__(self):
        pass

    # Random instance for selecting pivot in quick select algorithm
    RANDOM = random.Random()

    # Method to find the k-th largest element in the array
    @staticmethod
    def findKthMax(array, k):
        # Validate the value of k
        if k <= 0 or k > len(array):
            raise ValueError("k must be between 1 and the size of the array")
        # Call quickSelect to find the k-th largest element
        return Main.quickSelect(array, 0, len(array) - 1, len(array) - k)

    # QuickSelect algorithm to find the k-th smallest element
    @staticmethod
    def quickSelect(array, left, right, kSmallest):
        # Base case: if the list contains only one element
        if left == right:
            return array[left]
        # Randomly select a pivot index
        pivotIndex = left + Main.RANDOM.randint(0, right - left)
        # Partition the array around the pivot
        pivotIndex = Main.partition(array, left, right, pivotIndex)
        
        # Check if the pivot is the k-th smallest element
        if kSmallest == pivotIndex:
            return array[kSmallest]
        # If kSmallest is less than pivotIndex, search in the left subarray
        elif kSmallest < pivotIndex:
            return Main.quickSelect(array, left, pivotIndex - 1, kSmallest)
        # If kSmallest is greater than pivotIndex, search in the right subarray
        else:
            return Main.quickSelect(array, pivotIndex + 1, right, kSmallest)

    # Partition the array around a pivot
    @staticmethod
    def partition(array, left, right, pivotIndex):
        # Store the pivot value
        pivotValue = array[pivotIndex]
        # Move the pivot to the end of the array
        array[pivotIndex], array[right] = array[right], array[pivotIndex]
        storeIndex = left
        
        # Rearrange the array elements based on the pivot value
        for i in range(left, right):
            if array[i] < pivotValue:
                array[storeIndex], array[i] = array[i], array[storeIndex]
                storeIndex += 1
        # Move the pivot to its final place
        array[storeIndex], array[right] = array[right], array[storeIndex]
        return storeIndex # Return the final index of the pivot

    # Helper method to swap two elements in the array
    @staticmethod
    def swap(array, i, j):
        array[i], array[j] = array[j], array[i]

    # Main method to execute the program
    @staticmethod
    def main():
        import sys
        input = sys.stdin.read
        data = input().split()
        
        # Read the size of the array
        n = int(data[0])
        # Validate the size of the array
        if n <= 0:
            print("Array size must be positive.")
            return
        # Initialize the array and read its elements
        array = [int(data[i + 1]) for i in range(n)]
        # Read the value of k
        k = int(data[n + 1])
        # Validate the value of k
        if k <= 0 or k > n:
            print("Error: k must be between 1 and the size of the array.")
            return
        # Find the k-th largest element and print the result
        result = Main.findKthMax(array, k)
        print(f"The {k}-th largest element is: {result}")

if __name__ == "__main__":
    Main.main()
