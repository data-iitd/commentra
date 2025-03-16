import sys

# Class definition for Main with a constructor, instance variables, and methods
class Main:
    def __init__(self, n, arr):
        self.n = n
        self.arr = arr
        self.segTree = [0] * (2 * (int) (2 ** (int) (math.ceil(math.log(n, 2))) - 1))
        self.constructTree(arr, 0, n - 1, 0)

    def constructTree(self, arr, start, end, index):
        # Base case: leaf node
        if start == end:
            self.segTree[index] = arr[start]
            return arr[start]

        # Recursive case: internal node
        mid = start + (end - start) // 2
        self.segTree[index] = self.constructTree(arr, start, mid, index * 2 + 1) + self.constructTree(arr, mid + 1, end, index * 2 + 2)
        return self.segTree[index]

    def updateTree(self, start, end, index, diff, segIndex):
        # Base case: leaf node
        if index < start or index > end:
            return

        # Update the value in the array
        self.arr[index] += diff

        # Recursive case: internal node
        self.segTree[segIndex] += diff
        if start!= end:
            mid = start + (end - start) // 2
            self.updateTree(start, mid, index, diff, segIndex * 2 + 1)
            self.updateTree(mid + 1, end, index, diff, segIndex * 2 + 2)

    def update(self, index, value):
        # Check if the index is valid
        if index < 0 or index >= self.n:
            return

        # Update the value in the array and call the updateTree method to update the segment tree
        diff = value - self.arr[index]
        self.arr[index] = value
        self.updateTree(0, self.n - 1, index, diff, 0)

    def getSumTree(self, start, end, qStart, qEnd, segIndex):
        # Base case: leaf node
        if qStart <= start and qEnd >= end:
            return self.segTree[segIndex]

        # Recursive case: internal node
        mid = start + (end - start) // 2
        return self.getSumTree(start, mid, qStart, qEnd, segIndex * 2 + 1) + self.getSumTree(mid + 1, end, qStart, qEnd, segIndex * 2 + 2)

    def getSum(self, start, end):
        # Check if the start and end indices are valid
        if start < 0 or end >= self.n or start > end:
            return 0

        # Calculate the sum of the range in the segment tree
        return self.getSumTree(0, self.n - 1, start, end, 0)

# Main method for reading input and calling the methods
if __name__ == "__main__":
    # Read the size of the array and initialize the array
    n = int(input())
    arr = [0] * n
    for i in range(n):
        arr[i] = int(input())

    # Create an instance of the Main class and pass the array as an argument
    segmentTree = Main(n, arr)

    # Read the number of queries and call the appropriate methods for each query
    q = int(input())
    for i in range(q):
        choice = int(input()) # Read the type of query (1 for sum, 2 for update)
        if choice == 1: # Sum query
            start = int(input())
            end = int(input())
            print("Sum of range [" + str(start) + ", " + str(end) + "] is: " + str(segmentTree.getSum(start, end)))
        elif choice == 2: # Update query
            index = int(input())
            value = int(input())
            segmentTree.update(index, value)
            print("Value updated.")
        else: # Invalid query
            print("Invalid operation.")

