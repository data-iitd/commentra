import sys # Importing sys for reading input from stdin and writing output to stdout

class Solution:
    def solve(self, in_, out):
        n = in_.nextInt()
        k = in_.nextInt()
        logs_length = in_.readArray(n)
        min = 1
        max = 1000000000 + 1000
        while min < max:
            mid = (min + max) // 2
            if self.nei(mid, logs_length, k):
                max = mid
            else:
                min = mid + 1
        out.println(min)

    def nei(self, mid, logs_length, k):
        for log in logs_length:
            k -= (log + mid - 1) // mid - 1
            if k < 0:
                return False
        return True

class InputReader:
    def __init__(self, stream):
        self.reader = sys.stdin
        self.tokenizer = None

    def next(self):
        while self.tokenizer == None or not self.tokenizer.hasMoreTokens():
            self.tokenizer = StringTokenizer(self.reader.readLine())
        return self.tokenizer.nextToken()

    def nextInt(self):
        return int(self.next())

    def readArray(self, n):
        a = [None] * n
        for i in range(n):
            a[i] = self.nextInt()
        return a

if __name__ == '__main__':
    in_ = InputReader(sys.stdin)
    out = PrintWriter(sys.stdout)
    solution = Solution()
    solution.solve(in_, out)
    out.close()

