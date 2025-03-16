import sys

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

            if cnt >= total // 2 + 1:
                r = mid
            else:
                l = mid + 1

        return sorted_arr[l]

def main():
    input_stream = sys.stdin.buffer
    scan = Scanner(BufferedInputStream(input_stream))
    N = scan.nextInt()
    arr = [scan.nextInt() for _ in range(N)]

    tsk = Task()
    print(tsk.solve(arr))

class Scanner:
    def __init__(self, input_stream):
        self.input_stream = input_stream
        self.buffer = self.input_stream.read()
        self.length = len(self.buffer)
        self.index = 0

    def nextInt(self):
        num = 0
        while self.index < self.length and self.buffer[self.index] == ord(' '):
            self.index += 1
        sign = 1
        if self.index < self.length and self.buffer[self.index] == ord('-'):
            sign = -1
            self.index += 1
        while self.index < self.length and ord('0') <= self.buffer[self.index] <= ord('9'):
            num = num * 10 + (self.buffer[self.index] - ord('0'))
            self.index += 1
        return num * sign

if __name__ == "__main__":
    main()
