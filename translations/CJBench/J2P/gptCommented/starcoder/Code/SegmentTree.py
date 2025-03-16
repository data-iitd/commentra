import sys

# Segment tree array to store the sums
segTree = []
# Number of elements in the input array
n = 0
# Original input array
arr = []

# Constructor to initialize the segment tree
def __init__(self, n, arr):
    self.n = n
    # Calculate the height of the segment tree
    x = int(math.ceil(math.log(n) / math.log(2)))
    # Maximum size of the segment tree
    segSize = 2 * (int) math.pow(2, x) - 1
    self.segTree = [0] * segSize
    self.arr = arr
    # Construct the segment tree from the input array
    self.constructTree(arr, 0, n - 1, 0)

# Recursive function to construct the segment tree
def constructTree(self, arr, start, end, index):
    # If the range represents a single element, store it in the segment tree
    if start == end:
        self.segTree[index] = arr[start]
        return arr[start]
    # Calculate the mid-point of the current range
    mid = start + (end - start) / 2
    # Recursively construct the left and right subtrees and store their sums
    self.segTree[index] = self.constructTree(arr, start, mid, index * 2 + 1) +
            self.constructTree(arr, mid + 1, end, index * 2 + 2)
    return self.segTree[index]

# Recursive function to update the segment tree when an element is changed
def updateTree(self, start, end, index, diff, segIndex):
    # If the index to update is outside the current range, return
    if index < start or index > end:
        return
    # Update the current segment tree node
    self.segTree[segIndex] += diff
    # If the range has more than one element, continue updating the children
    if start!= end:
        mid = start + (end - start) / 2
        self.updateTree(start, mid, index, diff, segIndex * 2 + 1)
        self.updateTree(mid + 1, end, index, diff, segIndex * 2 + 2)

# Public method to update the value at a specific index
def update(self, index, value):
    # Check for valid index
    if index < 0 or index >= n:
        return
    # Calculate the difference between the new and old value
    diff = value - self.arr[index]
    # Update the original array
    self.arr[index] = value
    # Update the segment tree with the difference
    self.updateTree(0, n - 1, index, diff, 0)

# Recursive function to get the sum of a given range
def getSumTree(self, start, end, qStart, qEnd, segIndex):
    # If the current range is completely within the query range, return the sum
    if qStart <= start and qEnd >= end:
        return self.segTree[segIndex]
    # If the current range is completely outside the query range, return 0
    if qStart > end or qEnd < start:
        return 0
    # Calculate the mid-point of the current range
    mid = start + (end - start) / 2
    # Return the sum of the left and right children
    return (self.getSumTree(start, mid, qStart, qEnd, segIndex * 2 + 1) +
            self.getSumTree(mid + 1, end, qStart, qEnd, segIndex * 2 + 2))

# Public method to get the sum of elements in a given range
def getSum(self, start, end):
    # Check for valid range
    if start < 0 or end >= n or start > end:
        return 0
    # Call the recursive function to get the sum
    return self.getSumTree(0, n - 1, start, end, 0)

# Main method to execute the program
def main():
    # Read the number of elements
    n = int(raw_input())
    arr = [0] * n
    # Read the elements into the array
    for i in range(n):
        arr[i] = int(raw_input())
    # Initialize the segment tree with the input array
    segmentTree = Main(n, arr)
    # Read the number of queries
    q = int(raw_input())
    # Process each query
    for i in range(q):
        choice = int(raw_input())
        if choice == 1:
            # Query for the sum of a range
            start = int(raw_input())
            end = int(raw_input())
            print "Sum of range [" + str(start) + ", " + str(end) + "] is: " + str(segmentTree.getSum(start, end))
        elif choice == 2:
            # Update the value at a specific index
            index = int(raw_input())
            value = int(raw_input())
            segmentTree.update(index, value)
            print "Value updated."
        else:
            # Handle invalid operation
            print "Invalid operation."

# Entry point of the program
if __name__ == "__main__":
    main()

