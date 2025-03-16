
import math
class SegmentTree:
    def __init__(self, n, arr):
        self.n = n
        self.arr = arr
        self.segTree = [0] * (2 * (2 ** int(math.ceil(math.log(n) / math.log(2)))))
        self.constructTree(arr, 0, n - 1, 0)
    def constructTree(self, arr, start, end, index):
        if start == end:
            self.segTree[index] = arr[start]
            return arr[start]
        mid = start + (end - start) // 2
        self.segTree[index] = self.constructTree(arr, start, mid, index * 2 + 1) + self.constructTree(arr, mid + 1, end, index * 2 + 2)
        return self.segTree[index]
    def updateTree(self, start, end, index, diff, segIndex):
        if index < start or index > end:
            return
        self.segTree[segIndex] += diff
        if start != end:
            mid = start + (end - start) // 2
            self.updateTree(start, mid, index, diff, segIndex * 2 + 1)
            self.updateTree(mid + 1, end, index, diff, segIndex * 2 + 2)
    def update(self, index, value):
        if index < 0 or index >= self.n:
            return
        diff = value - self.arr[index]
        self.arr[index] = value
        self.updateTree(0, self.n - 1, index, diff, 0)
    def getSumTree(self, start, end, qStart, qEnd, segIndex):
        if qStart <= start and qEnd >= end:
            return self.segTree[segIndex]
        if qStart > end or qEnd < start:
            return 0
        mid = start + (end - start) // 2
        return (self.getSumTree(start, mid, qStart, qEnd, segIndex * 2 + 1) +
                self.getSumTree(mid + 1, end, qStart, qEnd, segIndex * 2 + 2))
    def getSum(self, start, end):
        if start < 0 or end >= self.n or start > end:
            return 0
        return self.getSumTree(0, self.n - 1, start, end, 0)
    def main():
        n = int(input())
        arr = list(map(int, input().split()))
        segmentTree = SegmentTree(n, arr)
        q = int(input())
        for i in range(q):
            choice = int(input())
            if choice == 1:
                start = int(input())
                end = int(input())
                print("Sum of range [" + str(start) + ", " + str(end) + "] is: " + str(segmentTree.getSum(start, end)))
            elif choice == 2:
                index = int(input())
                value = int(input())
                segmentTree.update(index, value)
                print("Value updated.")
            else:
                print("Invalid operation.")
    if __name__ == "__main__":
        main()
        # 