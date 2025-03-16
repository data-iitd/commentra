import math

class SegmentTree:
    def __init__(self, n, arr):
        self.n = n
        # Calculate the height of the segment tree
        x = math.ceil(math.log(n) / math.log(2))
        # Maximum size of the segment tree
        seg_size = 2 * (2 ** x) - 1
        self.seg_tree = [0] * seg_size
        self.arr = arr
        # Construct the segment tree from the input array
        self.construct_tree(arr, 0, n - 1, 0)

    def construct_tree(self, arr, start, end, index):
        # If the range represents a single element, store it in the segment tree
        if start == end:
            self.seg_tree[index] = arr[start]
            return arr[start]
        # Calculate the mid-point of the current range
        mid = start + (end - start) // 2
        # Recursively construct the left and right subtrees and store their sums
        self.seg_tree[index] = (self.construct_tree(arr, start, mid, index * 2 + 1) +
                                self.construct_tree(arr, mid + 1, end, index * 2 + 2))
        return self.seg_tree[index]

    def update_tree(self, start, end, index, diff, seg_index):
        # If the index to update is outside the current range, return
        if index < start or index > end:
            return
        # Update the current segment tree node
        self.seg_tree[seg_index] += diff
        # If the range has more than one element, continue updating the children
        if start != end:
            mid = start + (end - start) // 2
            self.update_tree(start, mid, index, diff, seg_index * 2 + 1)
            self.update_tree(mid + 1, end, index, diff, seg_index * 2 + 2)

    def update(self, index, value):
        # Check for valid index
        if index < 0 or index >= self.n:
            return
        # Calculate the difference between the new and old value
        diff = value - self.arr[index]
        # Update the original array
        self.arr[index] = value
        # Update the segment tree with the difference
        self.update_tree(0, self.n - 1, index, diff, 0)

    def get_sum_tree(self, start, end, q_start, q_end, seg_index):
        # If the current range is completely within the query range, return the sum
        if q_start <= start and q_end >= end:
            return self.seg_tree[seg_index]
        # If the current range is completely outside the query range, return 0
        if q_start > end or q_end < start:
            return 0
        # Calculate the mid-point of the current range
        mid = start + (end - start) // 2
        # Return the sum of the left and right children
        return (self.get_sum_tree(start, mid, q_start, q_end, seg_index * 2 + 1) +
                self.get_sum_tree(mid + 1, end, q_start, q_end, seg_index * 2 + 2))

    def get_sum(self, start, end):
        # Check for valid range
        if start < 0 or end >= self.n or start > end:
            return 0
        # Call the recursive function to get the sum
        return self.get_sum_tree(0, self.n - 1, start, end, 0)

# Main execution
if __name__ == "__main__":
    n = int(input())
    arr = list(map(int, input().split()))
    segment_tree = SegmentTree(n, arr)
    q = int(input())
    for _ in range(q):
        choice = int(input())
        if choice == 1:
            start, end = map(int, input().split())
            print(f"Sum of range [{start}, {end}] is: {segment_tree.get_sum(start, end)}")
        elif choice == 2:
            index, value = map(int, input().split())
            segment_tree.update(index, value)
            print("Value updated.")
        else:
            print("Invalid operation.")

# <END-OF-CODE>
