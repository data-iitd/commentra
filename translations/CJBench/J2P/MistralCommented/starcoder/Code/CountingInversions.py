
# Main class with a private constructor to prevent instantiation from outside
class Main:
    def __init__(self):
        pass

    # Method to count the number of inversions in an array using merge sort algorithm
    def countInversions(self, arr):
        return self.mergeSortAndCount(arr, 0, len(arr) - 1)

    # Recursive helper method for merge sort and counting inversions
    def mergeSortAndCount(self, arr, left, right):
        if left >= right: # Base case: when the subarray has only one element or is empty
            return 0

        mid = left + (right - left) // 2 # Calculate the middle index of the subarray

        # Recursively merge sort and count inversions in left and right halves
        inversions = 0
        inversions += self.mergeSortAndCount(arr, left, mid)
        inversions += self.mergeSortAndCount(arr, mid + 1, right)

        # Merge the sorted halves and count inversions
        inversions += self.mergeAndCount(arr, left, mid, right)

        return inversions

    # Merge and count inversions in two sorted halves
    def mergeAndCount(self, arr, left, mid, right):
        leftArr = [0] * (mid - left + 1) # Create temporary arrays for merging
        rightArr = [0] * (right - mid)

        # Copy elements from the original array to temporary arrays
        for i in range(mid - left + 1):
            leftArr[i] = arr[left + i]
        for j in range(right - mid):
            rightArr[j] = arr[mid + 1 + j]

        i = 0 # Index for left array
        j = 0 # Index for right array
        k = left # Index for the merged array
        inversions = 0 # Initialize inversions counter

        # Merge the sorted halves and count inversions
        while i < len(leftArr) and j < len(rightArr):
            if leftArr[i] <= rightArr[j]: # If current elements are in non-decreasing order
                arr[k] = leftArr[i] # Copy the smaller element to the merged array
                i += 1
            else: # If current elements are in non-increasing order
                arr[k] = rightArr[j] # Copy the larger element to the merged array
                inversions += mid + 1 - left - i # Count the number of inversions caused by this swap
                j += 1
            k += 1

        # Copy remaining elements from left and right arrays to the merged array
        while i < len(leftArr):
            arr[k] = leftArr[i]
            i += 1
            k += 1
        while j < len(rightArr):
            arr[k] = rightArr[j]
            j += 1
            k += 1

        return inversions

    # Main method to read input and print the result
    def main(self):
        scanner = Scanner(System.in) # Create a Scanner object to read input

        n = scanner.nextInt() # Read the number of elements in the array
        arr = [0] * n # Create an integer array of size n

        for i in range(n): # Read elements of the array and store them in the array
            arr[i] = scanner.nextInt()

        result = self.countInversions(arr) # Call the countInversions method to find the number of inversions
        print("Number of inversions: " + str(result)) # Print the result

        scanner.close() # Close the Scanner object

