
import sys

# The Main class contains the main method that initializes the scanner, reads input, and prints output.
class Main:
    def __init__(self):
        pass

    # The main method is the entry point of the application. It initializes the scanner, reads input, and prints output.
    @staticmethod
    def main():
        scanner = Scanner(sys.stdin) # Initialize the scanner to read input from the standard input stream.
        n = scanner.nextInt() # Read the number of elements in the array from the input.
        arr = [0] * n # Create an integer array of size n to store the input elements.
        for i in range(n): # Iterate through the array to read and store each input element.
            arr[i] = scanner.nextInt()
        k = scanner.nextInt() # Read the number of smallest elements to be returned from the array.
        result = Main.getMinKNumsByMain(arr, k) # Call the getMinKNumsByMain method to get the smallest k elements from the array.
        for num in result: # Iterate through the result array and print each element.
            print(num, end=" ")
        print() # Print a newline character after printing all the elements.
        scanner.close() # Close the scanner to release the system resources.

    # The getMinKNumsByMain method returns the smallest k elements from the input array.
    @staticmethod
    def getMinKNumsByMain(arr, k):
        if k < 1 or k > len(arr): # Check if the number of elements to be returned is valid.
            return None
        minKth = Main.getMinKthByMain(arr, k) # Find the kth smallest element in the array.
        res = [0] * k # Create an integer array of size k to store the smallest k elements.
        index = 0 # Initialize an index variable to keep track of the position in the result array.
        for value in arr: # Iterate through the input array and add the elements smaller than the kth smallest element to the result array.
            if value < minKth:
                res[index] = value
                index += 1
        for i in range(index, k): # Add the kth smallest element to the result array multiple times if needed.
            res[i] = minKth
        return res

    # The getMinKthByMain method finds the kth smallest element in the input array using the Quickselect algorithm.
    @staticmethod
    def getMinKthByMain(arr, k):
        copyArr = Main.copyArray(arr) # Create a copy of the input array to avoid modifying the original array during the algorithm.
        return Main.bfprt(copyArr, 0, len(copyArr) - 1, k - 1) # Call the bfprt method to find the kth smallest element in the copy of the array.

    # The copyArray method creates a copy of the input array.
    @staticmethod
    def copyArray(arr):
        copyArr = arr[:] # Create a copy of the input array using the slice operator.
        return copyArr

    # The bfprt method is a recursive implementation of the Quickselect algorithm to find the kth smallest element in an array.
    @staticmethod
    def bfprt(arr, begin, end, i):
        if begin == end: # Base case: when the array contains only one element, it is the kth smallest element.
            return arr[begin]
        pivot = Main.medianOfMedians(arr, begin, end) # Choose the pivot element as the median of medians of subarrays of size 5.
        pivotRange = Main.partition(arr, begin, end, pivot) # Partition the array into two parts: elements smaller than and larger than the pivot.
        if i >= pivotRange[0] and i <= pivotRange[1]: # If the index of the element to be found is within the pivot range, return it.
            return arr[i]
        elif i < pivotRange[0]: # If the index is before the pivot range, recursively search in the left subarray.
            return Main.bfprt(arr, begin, pivotRange[0] - 1, i)
        else: # If the index is after the pivot range, recursively search in the right subarray.
            return Main.bfprt(arr, pivotRange[1] + 1, end, i)

    # The medianOfMedians method finds the median of medians of subarrays of size 5 in the input array.
    @staticmethod
    def medianOfMedians(arr, begin, end):
        num = end - begin + 1 # Get the number of elements in the array.
        offset = num % 5 == 0? 0 : 1 # Determine the number of additional subarrays needed to have exactly 5 elements each.
        mArr = [0] * (num // 5 + offset) # Create an array to store the medians of subarrays of size 5.
        for i in range(len(mArr)): # Find the median of each subarray of size 5 and store it in the mArr array.
            mArr[i] = Main.getMedian(arr, begin + i * 5, min(end, begin + i * 5 + 4))
        return Main.bfprt(mArr, 0, len(mArr) - 1, len(mArr) // 2) # Find the median of medians of the medians of subarrays of size 5.

    # The partition method partitions the input array into two parts: elements smaller than and larger than the pivot element.
    @staticmethod
    def partition(arr, begin, end, num):
        small = begin - 1 # Initialize an index for the beginning of the subarray containing elements smaller than the pivot.
        cur = begin # Initialize an index for the current position in the array.
        big = end + 1 # Initialize an index for the beginning of the subarray containing elements larger than the pivot.
        while cur!= big: # While there are still elements to be processed.
            if arr[cur] < num: # If the current element is smaller than the pivot, swap it with the element at the index next to the small index.
                Main.swap(arr, cur, small = small + 1)
                cur += 1
            elif arr[cur] > num: # If the current element is larger than the pivot, swap it with the element at the index previous to the big index.
                Main.swap(arr, cur, big = big - 1)
            else: # If the current element is equal to the pivot, move to the next element.
                cur += 1
        return [small + 1, big - 1] # Return an array containing the indices of the beginning and end of the subarray containing elements smaller than the pivot.

    # The getMedian method finds the median of a subarray of the input array.
    @staticmethod
    def getMedian(arr, begin, end):
        Main.insertionSort(arr, begin, end) # Sort the subarray to find the median.
        sum = begin + end # Calculate the total number of elements in the subarray.
        mid = sum // 2 + (sum % 2) # Determine the index of the median based on the parity of the number of elements.
        return arr[mid] # Return the median.

    # The insertionSort method sorts a subarray of the input array using the insertion sort algorithm.
    @staticmethod
    def insertionSort(arr, begin, end):
        if arr == None or len(arr) < 2: # Base case: when the subarray is empty or contains only one element, it is already sorted.
            return
        for i in range(begin + 1, end + 1): # Iterate through the subarray to find the position of each element.
            for j in range(i, begin, -1):
                if arr[j - 1] > arr[j]: # If the current element is smaller than the previous element, swap them.
                    Main.swap(arr, j - 1, j)
                else:
                    break # If the current element is larger than or equal to the previous element, move to the next element.

    # The swap method swaps two elements in the input array.
    @staticmethod
    def swap(arr, i, j):
        temp = arr[i] # Store the value of the first element.
        arr[i] = arr[j] # Assign the value of the second element to the first element.
        arr[j] = temp # Assign the value of the first element to the second element.

# The Main class contains the main method that initializes the scanner, reads input, and prints output.
if __name__ == "__main__":
    Main.main() # Call the main method to start the program.

