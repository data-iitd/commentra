import random

# This class provides a method to select the n-th smallest element from a list of comparable elements.
class Main:
    @staticmethod
    def select(list, n):
        if list is None:
            raise ValueError("The list of elements must not be null.")
        if len(list) == 0:
            raise ValueError("The list of elements must not be empty.")
        if n < 0 or n >= len(list):
            raise IndexError("The index must be between 0 and the size of the list - 1.")
        # Find the index of the n-th smallest element using the selectIndex method.
        index = Main.selectIndex(list, n)
        # Return the n-th smallest element.
        return list[index]

    # Recursive helper method to find the index of the n-th smallest element.
    @staticmethod
    def selectIndex(list, n):
        return Main.selectIndex(list, 0, len(list) - 1, n)

    # Recursive helper method to find the index of the n-th smallest element using partitioning.
    @staticmethod
    def selectIndex(list, left, right, n):
        while True:
            pivotIndex = Main.pivot(list, left, right) # Find the pivot index.
            pivotIndexPartitioned = Main.partition(list, left, right, pivotIndex, n) # Partition the list around the pivot.
            if n == pivotIndexPartitioned: # If n is the pivot index, return it.
                return n
            elif n < pivotIndexPartitioned: # If n is to the left of the pivot index, search in the left subarray.
                right = pivotIndexPartitioned - 1
            else: # If n is to the right of the pivot index, search in the right subarray.
                left = pivotIndexPartitioned + 1

    # Helper method to partition the list around a randomly chosen pivot.
    @staticmethod
    def partition(list, left, right, pivotIndex, n):
        pivotValue = list[pivotIndex] # Get the value of the pivot element.
        list[pivotIndex], list[right] = list[right], list[pivotIndex] # Swap the pivot element with the last element.
        storeIndex = left # Initialize the index of the first element in the sorted subarray.
        for i in range(left, right): # Iterate through the elements in the subarray.
            if list[i] < pivotValue: # If the element is smaller than the pivot, swap it with the first element in the sorted subarray and increment the index.
                list[storeIndex], list[i] = list[i], list[storeIndex]
                storeIndex += 1
        storeIndexEq = storeIndex # Initialize the index of the first equal element in the sorted subarray.
        for i in range(storeIndex, right): # Iterate through the equal elements in the subarray.
            if list[i] == pivotValue: # If the element is equal to the pivot, swap it with the last equal element in the sorted subarray and increment the index.
                list[storeIndexEq], list[i] = list[i], list[storeIndexEq]
                storeIndexEq += 1
        list[right], list[storeIndexEq] = list[storeIndexEq], list[right] # Swap the last equal element with the last element in the subarray.
        return (n < storeIndex) and storeIndex or min(n, storeIndexEq) # Return the index of n in the sorted subarray.

    # Helper method to find a good pivot index using the median of five elements.
    @staticmethod
    def pivot(list, left, right):
        if right - left < 5: # If the subarray has fewer than five elements, use the simple partitioning method.
            return Main.partition5(list, left, right)
        for i in range(left, right, 5): # Iterate through the subarray in steps of five elements.
            subRight = min(i + 4, right) # Determine the index of the last element in the current subarray of five elements.
            median5 = Main.partition5(list, i, subRight) # Find the median of the current subarray of five elements.
            list[median5], list[left + (i - left) // 5] = list[left + (i - left) // 5], list[median5] # Swap the median with the pivot position.
        mid = left + (right - left) // 10 + 1 # Determine the middle index of the subarray.
        rightIndex = left + (right - left) // 5 # Determine the index of the fifth element from the left in the subarray.
        return Main.selectIndex(list, left, rightIndex, mid) # Find the index of the pivot using the selectIndex method.

    # Helper method to partition the list around a simple pivot (the middle element).
    @staticmethod
    def partition5(list, left, right):
        sublist = list[left:right + 1] # Create a sublist of the current subarray.
        sublist.sort() # Sort the sublist.
        return left + (right - left) // 2 # Return the index of the middle element in the sorted sublist.

# Main method to read input and test the select method.
if __name__ == "__main__":
    n = int(input()) # Read the number of elements in the list.
    list = [] # Create an empty list to store the elements.
    for i in range(n): # Iterate through the input and add each element to the list.
        list.append(int(input()))
    index = int(input()) # Read the index of the desired element.
    try: # Begin a try block to handle exceptions.
        result = Main.select(list, index) # Call the select method to find the desired element.
        print("The " + str(index) + "-th smallest element is: " + str(result)) # Print the result if successful.
    except Exception as e: # Catch any exceptions thrown by the select method.
        print(e) # Print the error message if an exception occurs.

