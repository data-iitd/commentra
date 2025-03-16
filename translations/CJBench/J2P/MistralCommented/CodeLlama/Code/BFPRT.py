
# The Main class contains the main method that initializes the scanner, reads input, and prints output.
class Main:
    # The main method is the entry point of the application. It initializes the scanner, reads input, and prints output.
    def main(self):
        scanner = Scanner(System.in) # Initialize the scanner to read input from the standard input stream.
        n = scanner.nextInt() # Read the number of elements in the array from the input.
        arr = [0] * n # Create an integer array of size n to store the input elements.
        for i in range(n): # Iterate through the array to read and store each input element.
            arr[i] = scanner.nextInt()
        k = scanner.nextInt() # Read the number of smallest elements to be returned from the array.
        result = self.getMinKNumsByMain(arr, k) # Call the getMinKNumsByMain method to get the smallest k elements from the array.
        for num in result: # Iterate through the result array and print each element.
            print(num, end=" ")
        print() # Print a newline character after printing all the elements.
        scanner.close() # Close the scanner to release the system resources.

    # The getMinKNumsByMain method returns the smallest k elements from the input array.
    def getMinKNumsByMain(self, arr, k):
        if k < 1 or k > len(arr): # Check if the number of elements to be returned is valid.
            return None
        minKth = self.getMinKthByMain(arr, k) # Find the kth smallest element in the array.
        res = [0] * k # Create an integer array of size k to store the smallest k elements.
        index = 0 # Initialize an index variable to keep track of the position in the result array.
        for value in arr: # Iterate through the input array and add the elements smaller than the kth smallest element to the result array.
            if value < minKth:
                res[index] = value
                index += 1
        for i in range(index, len(res)): # Add the kth smallest element to the result array multiple times if needed.
            res[i] = minKth
        return res

    # The getMinKthByMain method finds the kth smallest element in the input array using the Quickselect algorithm.
    def getMinKthByMain(self, arr, k):
        if len(arr) == 1: # Base case: when the array contains only one element, it is the kth smallest element.
            return arr[0]
        pivot = self.medianOfMedians(arr, 0, len(arr) - 1) # Choose the pivot element as the median of medians of subarrays of size 5.
        pivotRange = self.partition(arr, 0, len(arr) - 1, pivot) # Partition the array into two parts: elements smaller than and larger than the pivot.
        if k >= pivotRange[0] and k <= pivotRange[1]: # If the index of the element to be found is within the pivot range, return it.
            return arr[k]
        elif k < pivotRange[0]: # If the index is before the pivot range, recursively search in the left subarray.
            return self.getMinKthByMain(arr, k)
        else: # If the index is after the pivot range, recursively search in the right subarray.
            return self.getMinKthByMain(arr, k - pivotRange[0] + pivotRange[1] + 1)

    # The medianOfMedians method finds the median of medians of subarrays of size 5 in the input array.
    def medianOfMedians(self, arr, begin, end):
        num = end - begin + 1 # Get the number of elements in the array.
        offset = num % 5 == 0 # Determine the number of additional subarrays needed to have exactly 5 elements each.
        mArr = [0] * (num // 5 + offset) # Create an array to store the medians of subarrays of size 5.
        for i in range(len(mArr)): # Find the median of each subarray of size 5 and store it in the mArr array.
            mArr[i] = self.getMedian(arr, begin + i * 5, min(end, begin + i * 5 + 4))
        return self.getMinKthByMain(mArr, len(mArr) // 2) # Find the median of medians of the medians of subarrays of size 5.

    # The partition method partitions the input array into two parts: elements smaller than and larger than the pivot element.
    def partition(self, arr, begin, end, num):
        small = begin - 1 # Initialize an index for the beginning of the subarray containing elements smaller than the pivot.
        cur = begin # Initialize an index for the current position in the array.
        big = end + 1 # Initialize an index for the beginning of the subarray containing elements larger than the pivot.
        while cur != big: # While there are still elements to be processed.
            if arr[cur] < num: # If the current element is smaller than the pivot, swap it with the element at the index next to the small index.
                self.swap(arr, small + 1, cur)
                small += 1
                cur += 1
            elif arr[cur] > num: # If the current element is larger than the pivot, swap it with the element at the index previous to the big index.
                self.swap(arr, big - 1, cur)
                big -= 1
            else: # If the current element is equal to the pivot, move to the next element.
                cur += 1
        return [small + 1, big - 1] # Return an array containing the indices of the beginning and end of the subarray containing elements smaller than the pivot.

    # The getMedian method finds the median of a subarray of the input array.
    def getMedian(self, arr, begin, end):
        self.insertionSort(arr, begin, end) # Sort the subarray to find the median.
        sum = begin + end # Calculate the total number of elements in the subarray.
        mid = sum // 2 + (sum % 2) # Determine the index of the median based on the parity of the number of elements.
        return arr[mid] # Return the median.

    # The insertionSort method sorts a subarray of the input array using the insertion sort algorithm.
    def insertionSort(self, arr, begin, end):
        if len(arr) < 2: # Base case: when the subarray is empty or contains only one element, it is already sorted.
            return
        for i in range(begin + 1, end + 1): # Iterate through the subarray to find the position of each element.
            for j in range(i, begin, -1):
                if arr[j - 1] > arr[j]: # If the current element is smaller than the previous element, swap them.
                    self.swap(arr, j - 1, j)
                else:
                    break # If the current element is larger than or equal to the previous element, move to the next element.

    # The swap method swaps two elements in the input array.
    def swap(self, arr, i, j):
        temp = arr[i] # Store the value of the first element.
        arr[i] = arr[j] # Assign the value of the second element to the first element.
        arr[j] = temp # Assign the value of the first element to the second element.


# The Main class contains the main method that initializes the scanner, reads input, and prints output.
class Main:
    # The main method is the entry point of the application. It initializes the scanner, reads input, and prints output.
    def main(self):
        scanner = Scanner(System.in) # Initialize the scanner to read input from the standard input stream.
        n = scanner.nextInt() # Read the number of elements in the array from the input.
        arr = [0] * n # Create an integer array of size n to store the input elements.
        for i in range(n): # Iterate through the array to read and store each input element.
            arr[i] = scanner.nextInt()
        k = scanner.nextInt() # Read the number of smallest elements to be returned from the array.
        result = self.getMinKNumsByMain(arr, k) # Call the getMinKNumsByMain method to get the smallest k elements from the array.
        for num in result: # Iterate through the result array and print each element.
            print(num, end=" ")
        print() # Print a newline character after printing all the elements.
        scanner.close() # Close the scanner to release the system resources.

    # The getMinKNumsByMain method returns the smallest k elements from the input array.
    def getMinKNumsByMain(self, arr, k):
        if k < 1 or k > len(arr): # Check if the number of elements to be returned is valid.
            return None
        minKth = self.getMinKthByMain(arr, k) # Find the kth smallest element in the array.
        res = [0] * k # Create an integer array of size k to store the smallest k elements.
        index = 0 # Initialize an index variable to keep track of the position in the result array.
        for value in arr: # Iterate through the input array and add the elements smaller than the kth smallest element to the result array.
            if value < minKth:
                res[index] = value
                index += 1
        for i in range(index, len(res)): # Add the kth smallest element to the result array multiple times if needed.
            res[i] = minKth
        return res

    # The getMinKthByMain method finds the kth smallest element in the input array using the Quickselect algorithm.
    def getMinKthByMain(self, arr, k):
        if len(arr) == 1: # Base case: when the array contains only one element, it is the kth smallest element.
            return arr[0]
        pivot = self.medianOfMedians(arr, 0, len(arr) - 1) # Choose the pivot element as the median of medians of subarrays of size 5.
        pivotRange = self.partition(arr, 0, len(arr) - 1, pivot) # Partition the array into two parts: elements smaller than and larger than the pivot.
        if k >= pivotRange[0] and k <= pivotRange[1]: # If the index of the element to be found is within the pivot range, return it.
            return arr[k]
        elif k < pivotRange[0]: # If the index is before the pivot range, recursively search in the left subarray.
            return self.getMinKthByMain(arr, k)
        else: # If the index is after the pivot range, recursively search in the right subarray.
            return self.getMinKthByMain(arr, k - pivotRange[0] + pivotRange[1