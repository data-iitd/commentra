import sys
import bisect

class Task:
    def __init__(self):
        self.bit = [0] * (2 * len(arr) + 2)
        self.sorted = sorted(arr)

    def solve(self, arr):
        n = len(arr)
        total = n * (n + 1) / 2

        l = 0
        r = n - 1
        while l < r:
            mid = l + (r - l) / 2
            target = self.sorted[mid]

            cur = 0
            cnt = 0
            for i in range(n):
                cur += arr[i] <= target
                for x in range(cur + n + 1, len(self.bit)):
                    self.bit[x] += 1
                for x in range(cur + n, 0, -1):
                    cnt += self.bit[x]

            if cnt >= total / 2 + 1:
                r = mid
            else:
                l = mid + 1

        return self.sorted[l]

def main():
    # Create a Task object to perform the calculation
    tsk = Task()

    # Read the number of elements in the array
    n = int(sys.stdin.readline())

    # Read the input array
    arr = [int(x) for x in sys.stdin.readline().split()]

    # Solve the task and print the result
    print(tsk.solve(arr))

if __name__ == "__main__":
    main()

