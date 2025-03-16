import sys
import io
import os
import bisect

class FastReader:
    def __init__(self):
        self.buffer = io.BytesIO(os.read(0, os.fstat(0).st_size))
        self.tokens = []
        self.current_token = 0

    def next(self):
        while self.tokens == [] or self.current_token == len(self.tokens):
            self.tokens = self.buffer.readline().split()
            self.current_token = 0
        self.current_token += 1
        return self.tokens[self.current_token - 1]

    def next_int(self):
        return int(self.next())

    def next_long(self):
        return int(self.next())

    def next_double(self):
        return float(self.next())

    def next_line(self):
        return self.buffer.readline()

def main():
    inp = FastReader()
    n = inp.next_int()
    left = []
    answer = [0] * n
    for i in range(n):
        bisect.insort(left, i)
    q = inp.next_int()
    while q > 0:
        q -= 1
        l = inp.next_int() - 1
        r = inp.next_int() - 1
        win = inp.next_int() - 1
        while left and left[0] >= l and left[0] <= r:
            curr = left.pop(0)
            answer[curr] = win + 1
        answer[win] = 0
        bisect.insort(left, win)
    ans = ""
    for i in range(n):
        ans += str(answer[i]) + " "
    print(ans.strip())

if __name__ == "__main__":
    main()
