class Node:
    def __init__(self, start, end, value):
        self.start = start  # Start index of the segment
        self.end = end      # End index of the segment
        self.value = value  # Value of the segment
        self.lazy = 0       # Lazy value for deferred updates
        self.left = None    # Left child node
        self.right = None   # Right child node

    def apply_update(self, diff):
        self.lazy += diff  # Update lazy value
        self.value += (self.end - self.start) * diff  # Update the segment value

    def shift(self):
        if self.lazy == 0:
            return  # No updates to propagate
        if self.left is None and self.right is None:
            return  # No children to propagate to
        self.value += self.lazy  # Apply lazy value to the current node's value
        if self.left is not None:
            self.left.apply_update(self.lazy)  # Propagate to left child
        if self.right is not None:
            self.right.apply_update(self.lazy)  # Propagate to right child
        self.lazy = 0  # Reset lazy value after propagation

    @staticmethod
    def merge(left, right):
        if left is None:
            return right  # If left is null, return right
        if right is None:
            return left  # If right is null, return left
        # Create a new node that combines the values of left and right
        result = Node(left.start, right.end, left.value + right.value)
        result.left = left  # Set left child
        result.right = right  # Set right child
        return result  # Return the merged node

    def get_value(self):
        return self.value

    def get_left(self):
        return self.left

    def get_right(self):
        return self.right


class SegmentTree:
    def __init__(self, array):
        self.root = self.build_tree(array, 0, len(array))  # Build the tree

    def build_tree(self, array, start, end):
        if end - start < 2:
            return Node(start, end, array[start])  # Leaf node
        mid = (start + end) // 2  # Find the midpoint
        left = self.build_tree(array, start, mid)  # Build left subtree
        right = self.build_tree(array, mid, end)  # Build right subtree
        return Node.merge(left, right)  # Merge left and right nodes

    def update_range(self, left, right, diff, curr):
        if left <= curr.start and curr.end <= right:
            curr.apply_update(diff)  # Apply update if current segment is fully within range
            return
        if left >= curr.end or right <= curr.start:
            return  # No overlap
        curr.shift()  # Shift any pending updates
        # Recursively update left and right children
        self.update_range(left, right, diff, curr.left)
        self.update_range(left, right, diff, curr.right)
        # Merge the updated children back into the current node
        merge = Node.merge(curr.left, curr.right)
        curr.value = merge.value  # Update current node's value

    def get_range(self, left, right, curr):
        if left <= curr.start and curr.end <= right:
            return curr  # Current segment is fully within range
        if left >= curr.end or right <= curr.start:
            return None  # No overlap
        curr.shift()  # Shift any pending updates
        # Merge the results from left and right children
        return Node.merge(self.get_range(left, right, curr.left), self.get_range(left, right, curr.right))

    def public_get_range(self, left, right):
        result = self.get_range(left, right, self.root)  # Get the range from the root
        return 0 if result is None else result.get_value()  # Return the value or 0 if null

    def public_update_range(self, left, right, diff):
        self.update_range(left, right, diff, self.root)  # Update the range starting from the root


def main():
    import sys
    input = sys.stdin.read
    data = input().splitlines()
    
    n = int(data[0])  # Read the size of the array
    array = list(map(int, data[1].split()))  # Read array elements
    tree = SegmentTree(array)  # Create the segment tree
    q = int(data[2])  # Read the number of queries
    
    results = []
    for i in range(3, 3 + q):
        op, *args = data[i].split()
        if op == "update":
            left, right, diff = map(int, args)
            tree.public_update_range(left, right, diff)  # Perform the update
        elif op == "query":
            left, right = map(int, args)
            results.append(tree.public_get_range(left, right))  # Output the result of the query

    print("\n".join(map(str, results)))  # Print all results for queries


if __name__ == "__main__":
    main()

# <END-OF-CODE>
