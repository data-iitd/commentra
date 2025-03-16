
# <START-OF-CODE>
import sys

class Solution:
    def solve(self, input, output):
        # read case number
        T = input.nextInt()

        # iterate on all cases
        for t in range(T):
            # read input
            n = input.nextInt()
            k = input.nextInt()
            logsLength = input.readArray(n)

            # solve
            min = 1
            max = 1000000000
            while min < max:
                mid = (min + max) / 2
                if self.nei(mid, logsLength, k):
                    max = mid
                else:
                    min = mid + 1

            # output case result
            output.print(min)
            output.print("\n")

    def nei(self, mid, logsLength, k):
        for log in logsLength:
            k -= (log + mid - 1) / mid - 1
        return k >= 0

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
        a = [0] * n
        for i in range(n):
            a[i] = self.nextInt()
        return a

if __name__ == '__main__':
    input = InputReader(sys.stdin)
    output = PrintWriter(sys.stdout)
    solution = Solution()
    solution.solve(input, output)
    output.close()
# 