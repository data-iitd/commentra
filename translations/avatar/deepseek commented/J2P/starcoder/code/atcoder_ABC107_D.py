
import sys
import bisect

class Task:
    def __init__(self):
        self.bit = [0]
        self.n = 0

    def solve(self, arr):
        self.n = len(arr)
        sorted = arr[:]
        sorted.sort()
        total = (self.n * (self.n + 1)) / 2
        l = 0
        r = self.n - 1
        while l < r:
            mid = (l + r) / 2
            target = sorted[mid]
            cur = 0
            cnt = 0
            bit = [0] * (2 * self.n + 2)
            for x in range(self.n + 1, len(bit)):
                bit[x] += 1
            for i in range(self.n):
                cur += arr[i] <= target
                for x in range(cur + self.n + 1, len(bit)):
                    bit[x] += 1
                for x in range(cur + self.n, 0, -1):
                    cnt += bit[x]
            if cnt >= total / 2 + 1:
                r = mid
            else:
                l = mid + 1
        return sorted[l]

def main():
    t = Task()
    n = int(sys.stdin.readline())
    arr = [int(x) for x in sys.stdin.readline().split()]
    print t.solve(arr)

if __name__ == '__main__':
    main()

