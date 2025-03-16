
import sys
import bisect

class Task:
    def __init__(self):
        self.n = 0
        self.arr = []
        self.sorted = []
        self.total = 0

    def solve(self, arr):
        self.n = len(arr)
        self.arr = arr
        self.sorted = sorted(arr)
        self.total = (self.n * (self.n + 1)) / 2

        l = 0
        r = self.n - 1

        while l < r:
            mid = (l + r) / 2
            target = self.sorted[mid]

            cur = 0
            cnt = 0
            bit = [0] * (2 * self.n + 2)

            for x in range(self.n + 1, len(bit)):
                bit[x] += 1

            for i in range(self.n):
                cur += arr[i] <= target and 1 or -1
                for x in range(cur + self.n + 1, len(bit)):
                    bit[x] += 1
                for x in range(cur + self.n, 0, -1):
                    cnt += bit[x]

            if cnt >= self.total / 2 + 1:
                r = mid
            else:
                l = mid + 1

        return self.sorted[l]

def main():
    # Read the number of elements in the array
    tsk = Task()
    tsk.n = int(sys.stdin.readline())

    # Read the elements of the array
    for i in range(tsk.n):
        tsk.arr.append(int(sys.stdin.readline()))

    # Create an instance of the Task class and call its solve method
    print tsk.solve(tsk.arr)

if __name__ == "__main__":
    main()

# 