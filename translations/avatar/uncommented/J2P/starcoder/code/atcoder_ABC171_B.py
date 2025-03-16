
# <START-OF-CODE>
import sys
import threading
import time

class InputReader:
    def __init__(self, stream):
        self.reader = stream
        self.tokenizer = None
        self.lock = threading.Lock()

    def n(self):
        with self.lock:
            if self.tokenizer == None or not self.tokenizer.hasMoreTokens():
                self.tokenizer = StringTokenizer(self.reader.readline())
        return self.tokenizer.nextToken()

    def ni(self):
        return int(self.n())

class Solution:
    def __init__(self):
        pass

    def solve(self, in_, out_):
        n = in_.ni()
        k = in_.ni()
        a = [0] * n
        for i in range(n):
            a[i] = in_.ni()
        a.sort()
        ans = 0
        for i in range(k):
            ans += a[i]
        out_.println(ans)

def main():
    in_ = InputReader(sys.stdin)
    out_ = PrintWriter(sys.stdout)
    sol = Solution()
    sol.solve(in_, out_)
    out_.close()

if __name__ == '__main__':
    main()
# 