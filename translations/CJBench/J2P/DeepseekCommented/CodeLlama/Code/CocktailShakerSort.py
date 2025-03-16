import sys

def main():
    # Read the number of elements in the array
    n = int(sys.stdin.readline())
    # Create an array of size n to store the elements
    array = [0] * n
    # Read n elements into the array
    for i in range(n):
        array[i] = int(sys.stdin.readline())
    # Create an instance of the Main class to use its sorting method
    sorter = Main()
    # Call the sort method on the array
    sorter.sort(array)
    # Print the sorted array
    for num in array:
        print(num, end=" ")

class Main:
    # Generic sort method that takes an array of type T which extends Comparable
    def sort(self, array):
        # If the array is empty, return immediately
        if len(array) == 0:
            return
        # Initialize pointers for the forward and backward passes
        left = 0
        right = len(array) - 1
        # Continue sorting until the left pointer meets the right pointer
        while left < right:
            # Perform the forward pass and update the right pointer
            right = self.performForwardPass(array, left, right)
            # Perform the backward pass and update the left pointer
            left = self.performBackwardPass(array, left, right)

    # Forward pass to bubble the largest element to the right
    def performForwardPass(self, array, left, right):
        # Track the last swapped index in the forward pass
        lastSwappedIndex = left
        # Iterate through the array from left to right-1
        for i in range(left, right):
            # Swap if the current element is greater than the next element
            if array[i] > array[i + 1]:
                self.swap(array, i, i + 1)
                lastSwappedIndex = i
        # Return the last swapped index for the next pass
        return lastSwappedIndex

    # Backward pass to bubble the smallest element to the left
    def performBackwardPass(self, array, left, right):
        # Track the last swapped index in the backward pass
        lastSwappedIndex = right
        # Iterate through the array from right to left+1
        for i in range(right, left, -1):
            # Swap if the current element is less than the previous element
            if array[i] < array[i - 1]:
                self.swap(array, i - 1, i)
                lastSwappedIndex = i
        # Return the last swapped index for the next pass
        return lastSwappedIndex

    # Generic swap method to swap two elements in the array
    def swap(self, array, i, j):
        temp = array[i]
        array[i] = array[j]
        array[j] = temp

if __name__ == "__main__":
    main()

