import sys
from io import StringIO

class MyScanner:
    def __init__(self, input_stream):
        self.input_stream = input_stream
        self.lines = self.input_stream.split('\n')
        self.index = 0

    def next(self):
        if self.index < len(self.lines):
            line = self.lines[self.index]
            self.index += 1
            return line.strip()
        else:
            return None

    def next_int(self):
        return int(self.next())

    def next_long(self):
        return int(self.next())

    def next_double(self):
        return float(self.next())

def cal(s, c):
    n = len(s)
    m = n - 1
    ans = 0
    for i in range(n):
        if s[i] == c and (m & i) == i:
            ans ^= 1
    return ans

def solve():
    n = sc.next_int()
    for test_case in range(1, n + 1):
        num = sc.next_int()
        s = sc.next()
        sb = []
        for i in range(1, num):
            sb.append(str(abs(ord(s[i]) - ord(s[i - 1]))))
        if num == 2:
            print(sb[0])
            continue
        s = ''.join(sb)
        if '1' in s:
            print(cal(s, '1'))
        else:
            print(cal(s, '2') * 2)

# Redirect stdin for testing
input_stream = """
"""
sc = MyScanner(input_stream)
solve()
