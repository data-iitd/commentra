import math

class SegmentTree:
    def __init__(self, n, arr):
        self.n = n
        x = math.ceil(math.log(n, 2))
        seg_size = 2 * (2 ** x) - 1
        self.seg_tree = [0] * seg_size
        self.arr = arr
        self.construct_tree(arr, 0, n - 1, 0)

    def construct_tree(self, arr, start, end, index):
        if start == end:
            self.seg_tree[index] = arr[start]
            return arr[start]
        mid = start + (end - start) // 2
        self.seg_tree[index] = self.construct_tree(arr, start, mid, index * 2 + 1) + \
                               self.construct_tree(arr, mid + 1, end, index * 2 + 2)
        return self.seg_tree[index]

    def update_tree(self, start, end, index, diff, seg_index):
        if index < start or index > end:
            return
        self.seg_tree[seg_index] += diff
        if start != end:
            mid = start + (end - start) // 2
            self.update_tree(start, mid, index, diff, seg_index * 2 + 1)
            self.update_tree(mid + 1, end, index, diff, seg_index * 2 + 2)

    def update(self, index, value):
        if index < 0 or index >= self.n:
            return
        diff = value - self.arr[index]
        self.arr[index] = value
        self.update_tree(0, self.n - 1, index, diff, 0)

    def get_sum_tree(self, start, end, q_start, q_end, seg_index):
        if q_start <= start and q_end >= end:
            return self.seg_tree[seg_index]
        if q_start > end or q_end < start:
            return 0
        mid = start + (end - start) // 2
        return (self.get_sum_tree(start, mid, q_start, q_end, seg_index * 2 + 1) +
                self.get_sum_tree(mid + 1, end, q_start, q_end, seg_index * 2 + 2))

    def get_sum(self, start, end):
        if start < 0 or end >= self.n or start > end:
            return 0
        return self.get_sum_tree(0, self.n - 1, start, end, 0)

# Main function to read input, create segment tree, and process queries
def main():
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

if __name__ == "__main__":
    main()
