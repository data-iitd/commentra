import sys

# Private constructor to prevent instantiation of the utility class
class Main:
    def __init__(self):
        pass

    # Method to select the n-th smallest element from the list
    def select(self, list, n):
        # Ensure the list is not null
        if list is None:
            raise Exception("The list of elements must not be null.")
        
        # Check if the list is empty
        if len(list) == 0:
            raise Exception("The list of elements must not be empty.")
        
        # Validate the index n
        if n < 0 or n >= len(list):
            raise Exception("The index must be between 0 and the size of the list - 1.")
        
        # Get the index of the n-th smallest element
        index = self.selectIndex(list, n)
        return list[index] # Return the n-th smallest element

    # Helper method to initiate the selection process
    def selectIndex(self, list, n):
        return self.selectIndex(list, 0, len(list) - 1, n)

    # Recursive method to find the index of the n-th smallest element
    def selectIndex(self, list, left, right, n):
        while True:
            # If the left and right pointers converge, return the left index
            if left == right:
                return left
            
            # Choose a pivot index for partitioning
            pivotIndex = self.pivot(list, left, right)
            # Partition the list around the pivot and get the new pivot index
            pivotIndex = self.partition(list, left, right, pivotIndex, n)
            
            # Check if the pivot index is the desired index
            if n == pivotIndex:
                return n # Found the n-th smallest element
            elif n < pivotIndex:
                right = pivotIndex - 1 # Search in the left part
            else:
                left = pivotIndex + 1 # Search in the right part

    # Method to partition the list around a pivot
    def partition(self, list, left, right, pivotIndex, n):
        pivotValue = list[pivotIndex] # Get the pivot value
        list[pivotIndex], list[right] = list[right], list[pivotIndex] # Move pivot to the end
        storeIndex = left # Pointer for the next position to swap
        
        # Partition the list into elements less than the pivot
        for i in range(left, right):
            if list[i] < pivotValue:
                list[storeIndex], list[i] = list[i], list[storeIndex]
                storeIndex += 1
        
        # Handle elements equal to the pivot
        storeIndexEq = storeIndex
        for i in range(storeIndex, right):
            if list[i] == pivotValue:
                list[storeIndexEq], list[i] = list[i], list[storeIndexEq]
                storeIndexEq += 1
        
        # Move the pivot to its final place
        list[right], list[storeIndexEq] = list[storeIndexEq], list[right]
        # Return the appropriate index based on the n value
        return (n < storeIndex) and storeIndex or min(n, storeIndexEq)

    # Method to select a pivot for partitioning
    def pivot(self, list, left, right):
        # If the range is small, use a simple partitioning method
        if right - left < 5:
            return self.partition5(list, left, right)
        
        # Group elements into sublists of 5 and find their medians
        for i in range(left, right, 5):
            subRight = min(i + 4, right)
            median5 = self.partition5(list, i, subRight)
            list[median5], list[left + (i - left) / 5] = list[left + (i - left) / 5], list[median5] # Move median to the front
        
        # Recursively select the median of the medians
        mid = left + (right - left) / 10 + 1
        rightIndex = left + (right - left) / 5
        return self.selectIndex(list, left, rightIndex, mid)

    # Method to partition a small sublist of 5 elements and return the median
    def partition5(self, list, left, right):
        sublist = list[left:right + 1] # Create a sublist
        sublist.sort() # Sort the sublist
        return left + (right - left) / 2 # Return the median index

# Main method to execute the program
if __name__ == "__main__":
    # Read the number of elements
    n = int(raw_input())
    list = []
    
    # Read the elements into the list
    for i in range(n):
        list.append(int(raw_input()))
    
    index = int(raw_input()) # Read the index of the desired smallest element
    try:
        # Attempt to select the n-th smallest element
        result = Main().select(list, index)
        print "The " + str(index) + "-th smallest element is: " + str(result)
    except Exception as e:
        # Print any exceptions that occur
        print e.message

