
import sys

# Class definition for Main with a constructor, instance variables, and methods
class Main:
    def __init__(self, n, arr):
        self.n = n
        x = int(math.ceil(math.log(n) / math.log(2)))
        segSize = 2 * (2 ** x) - 1
        self.segTree = [0] * segSize
        self.arr = arr
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
        self.arr[index] += diff
        self.segTree[segIndex] += diff
        if start!= end:
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
        mid = start + (end - start) // 2
        return self.getSumTree(start, mid, qStart, qEnd, segIndex * 2 + 1) + self.getSumTree(mid + 1, end, qStart, qEnd, segIndex * 2 + 2)

    def getSum(self, start, end):
        if start < 0 or end >= self.n or start > end:
            return 0
        return self.getSumTree(0, self.n - 1, start, end, 0)

# Main method for reading input and calling the methods
if __name__ == "__main__":
    n = int(input())
    arr = list(map(int, input().split()))
    segmentTree = Main(n, arr)
    q = int(input())
    for _ in range(q):
        choice = int(input())
        if choice == 1:
            start = int(input())
            end = int(input())
            print("Sum of range [{}, {}] is: {}".format(start, end, segmentTree.getSum(start, end)))
        elif choice == 2:
            index = int(input())
            value = int(input())
            segmentTree.update(index, value)
            print("Value updated.")
        else:
            print("Invalid operation.")