import sys
import bisect

class Task:
    def solve(self, arr):
        n = len(arr)
        sorted_arr = sorted(arr)
        total = n * (n + 1) // 2
        l, r = 0, n - 1
        while l < r:
            mid = l + (r - l) // 2
            target = sorted_arr[mid]
            cur = 0
            cnt = 0
            bit = [0] * (2 * n + 2)
            for x in range(n + 1, len(bit)):
                bit[x] += 1
            for i in range(n):
                cur += 1 if arr[i] <= target else -1
                for x in range(cur + n + 1, len(bit)):
                    bit[x] += 1
                for x in range(cur + n, 0, -1):
                    cnt += bit[x]
            if cnt >= (total // 2) + 1:
                r = mid
            else:
                l = mid + 1
        return sorted_arr[l]

def main():
    input_stream = sys.stdin.buffer
    scan = Scanner(input_stream)
    N = scan.nextInt()
    arr = [scan.nextInt() for _ in range(N)]
    tsk = Task()
    print(tsk.solve(arr))

class Scanner:
    def __init__(self, input_stream):
        self.input_stream = input_stream
        self.buf = input_stream.read()
        self.index = 0

    def nextInt(self):
        num = 0
        while self.index < len(self.buf) and not ('0' <= self.buf[self.index] <= '9'):
            self.index += 1
        if self.index >= len(self.buf):
            raise StopIteration
        while self.index < len(self.buf) and '0' <= self.buf[self.index] <= '9':
            num = num * 10 + int(self.buf[self.index])
            self.index += 1
        return num

if __name__ == "__main__":
    main()
