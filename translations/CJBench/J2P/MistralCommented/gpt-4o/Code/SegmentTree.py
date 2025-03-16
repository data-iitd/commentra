import math

# Class definition for SegmentTree with a constructor, instance variables, and methods
class SegmentTree:
    def __init__(self, arr):
        self.n = len(arr)  # Size of the array
        x = math.ceil(math.log(self.n, 2))  # Calculate the log base 2 of the array size
        seg_size = 2 * (2 ** x) - 1  # Calculate the size of the segment tree
        self.seg_tree = [0] * seg_size  # Initialize the segment tree array
        self.arr = arr  # Assign the input array
        self.construct_tree(arr, 0, self.n - 1, 0)  # Construct the segment tree

    # Method to construct the segment tree recursively
    def construct_tree(self, arr, start, end, index):
        # Base case: leaf node
        if start == end:
            self.seg_tree[index] = arr[start]  # Set the value of the current node to the value of the leaf node
            return arr[start]  # Return the value of the leaf node

        # Recursive case: internal node
        mid = start + (end - start) // 2  # Calculate the middle index
        self.seg_tree[index] = (self.construct_tree(arr, start, mid, index * 2 + 1) +  # Construct the left subtree
                                self.construct_tree(arr, mid + 1, end, index * 2 + 2))  # Construct the right subtree
        return self.seg_tree[index]  # Return the sum of the left and right subtrees

    # Method to update a value in the array and the segment tree
    def update_tree(self, start, end, index, diff, seg_index):
        # Base case: leaf node
        if index < start or index > end:
            return  # Exit the method if the index is out of range

        # Update the value in the array
        self.arr[index] += diff

        # Recursive case: internal node
        self.seg_tree[seg_index] += diff  # Update the value of the current node
        if start != end:  # If the current node is not a leaf node
            mid = start + (end - start) // 2
            self.update_tree(start, mid, index, diff, seg_index * 2 + 1)  # Update the left subtree
            self.update_tree(mid + 1, end, index, diff, seg_index * 2 + 2)  # Update the right subtree

    # Method to update a value in the array
    def update(self, index, value):
        # Check if the index is valid
        if index < 0 or index >= self.n:
            return

        # Update the value in the array and call the update_tree method to update the segment tree
        diff = value - self.arr[index]
        self.arr[index] = value
        self.update_tree(0, self.n - 1, index, diff, 0)

    # Method to calculate the sum of a range in the segment tree
    def get_sum_tree(self, start, end, q_start, q_end, seg_index):
        # Base case: leaf node
        if q_start <= start and q_end >= end:
            return self.seg_tree[seg_index]  # Return the sum of the current node

        # Recursive case: internal node
        mid = start + (end - start) // 2
        return (self.get_sum_tree(start, mid, q_start, q_end, seg_index * 2 + 1) +  # Sum of the left subtree
                self.get_sum_tree(mid + 1, end, q_start, q_end, seg_index * 2 + 2))  # Sum of the right subtree

    # Method to calculate the sum of a range in the array
    def get_sum(self, start, end):
        # Check if the start and end indices are valid
        if start < 0 or end >= self.n or start > end:
            return 0

        # Calculate the sum of the range in the segment tree
        return self.get_sum_tree(0, self.n - 1, start, end, 0)

# Main function for reading input and calling the methods
if __name__ == "__main__":
    n = int(input())  # Read the size of the array
    arr = list(map(int, input().split()))  # Read each element of the array

    # Create an instance of the SegmentTree class and pass the array as an argument
    segment_tree = SegmentTree(arr)

    # Read the number of queries and call the appropriate methods for each query
    q = int(input())
    for _ in range(q):
        choice = int(input())  # Read the type of query (1 for sum, 2 for update)
        if choice == 1:  # Sum query
            start, end = map(int, input().split())
            print(f"Sum of range [{start}, {end}] is: {segment_tree.get_sum(start, end)}")
        elif choice == 2:  # Update query
            index, value = map(int, input().split())
            segment_tree.update(index, value)
            print("Value updated.")
        else:  # Invalid query
            print("Invalid operation.")

# <END-OF-CODE>
