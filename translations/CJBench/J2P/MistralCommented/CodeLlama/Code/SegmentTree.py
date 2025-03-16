
# Import the Scanner class from the java.util package
from java.util import Scanner

# Class definition for Main with a constructor, instance variables, and methods
class Main:
    # Constructor for initializing the segment tree
    def __init__(self, n, arr):
        self.n = n
        x = int(n.bit_length() - 1) # Calculate the log base 2 of the array size
        segSize = 2 * (2 ** x) - 1 # Calculate the size of the segment tree
        self.segTree = [0] * segSize # Initialize the segment tree array
        self.arr = arr # Assign the input array
        self.constructTree(arr, 0, n - 1, 0) # Construct the segment tree

    # Method to construct the segment tree recursively
    def constructTree(self, arr, start, end, index):
        # Base case: leaf node
        if start == end:
            self.segTree[index] = arr[start] # Set the value of the current node to the value of the leaf node
            return arr[start] # Return the value of the leaf node

        # Recursive case: internal node
        mid = start + (end - start) // 2 # Calculate the middle index
        self.segTree[index] = self.constructTree(arr, start, mid, index * 2 + 1) # Construct the left subtree
        self.segTree[index] += self.constructTree(arr, mid + 1, end, index * 2 + 2) # Construct the right subtree
        return self.segTree[index] # Return the sum of the left and right subtrees

    # Method to update a value in the array and the segment tree
    def updateTree(self, start, end, index, diff, segIndex):
        # Base case: leaf node
        if index < start or index > end:
            return # Exit the method if the index is out of range

        # Update the value in the array
        self.arr[index] += diff

        # Recursive case: internal node
        self.segTree[segIndex] += diff # Update the value of the current node
        if start != end: # If the current node is not a leaf node
            mid = start + (end - start) // 2
            self.updateTree(start, mid, index, diff, segIndex * 2 + 1) # Update the left subtree
            self.updateTree(mid + 1, end, index, diff, segIndex * 2 + 2) # Update the right subtree

    # Method to update a value in the array
    def update(self, index, value):
        # Check if the index is valid
        if index < 0 or index >= self.n:
            return

        # Update the value in the array and call the updateTree method to update the segment tree
        diff = value - self.arr[index]
        self.arr[index] = value
        self.updateTree(0, self.n - 1, index, diff, 0)

    # Method to calculate the sum of a range in the segment tree
    def getSumTree(self, start, end, qStart, qEnd, segIndex):
        # Base case: leaf node
        if qStart <= start and qEnd >= end:
            return self.segTree[segIndex] # Return the sum of the current node

        # Recursive case: internal node
        mid = start + (end - start) // 2
        return (self.getSumTree(start, mid, qStart, qEnd, segIndex * 2 + 1) # Sum of the left subtree
                + self.getSumTree(mid + 1, end, qStart, qEnd, segIndex * 2 + 2)) # Sum of the right subtree

    # Method to calculate the sum of a range in the array
    def getSum(self, start, end):
        # Check if the start and end indices are valid
        if start < 0 or end >= self.n or start > end:
            return 0

        # Calculate the sum of the range in the segment tree
        return self.getSumTree(0, self.n - 1, start, end, 0)

    # Main method for reading input and calling the methods
    def main(self):
        scanner = Scanner(System.in) # Initialize the scanner for reading input

        # Read the size of the array and initialize the array
        n = scanner.nextInt()
        arr = [0] * n
        for i in range(n):
            arr[i] = scanner.nextInt() # Read each element of the array

        # Create an instance of the Main class and pass the array as an argument
        segmentTree = Main(n, arr)

        # Read the number of queries and call the appropriate methods for each query
        q = scanner.nextInt()
        for i in range(q):
            choice = scanner.nextInt() # Read the type of query (1 for sum, 2 for update)
            if choice == 1: # Sum query
                start = scanner.nextInt()
                end = scanner.nextInt()
                print("Sum of range [" + str(start) + ", " + str(end) + "] is: " + str(segmentTree.getSum(start, end)))
            elif choice == 2: # Update query
                index = scanner.nextInt()
                value = scanner.nextInt()
                segmentTree.update(index, value)
                print("Value updated.")
            else: # Invalid query
                print("Invalid operation.")

        scanner.close() # Close the scanner

# Main method for running the program
if __name__ == "__main__":
    Main().main()

