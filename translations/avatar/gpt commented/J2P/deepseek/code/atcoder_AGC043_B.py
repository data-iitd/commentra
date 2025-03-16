import sys
from io import StringIO

class MyScanner:
    def __init__(self, input_str):
        self.data = input_str.splitlines()
        self.index = 0

    def readline(self):
        line = self.data[self.index]
        self.index += 1
        return line

    def read_int(self):
        return int(self.readline())

    def read_str(self):
        return self.readline().strip()

def cal(s, c):
    n = len(s)
    m = n - 1
    ans = 0
    for i in range(n):
        if s[i] == c and (m & i) == i:
            ans ^= 1
    return ans

def solve():
    n = sc.read_int()
    s = sc.read_str()
    sb = []
    
    for i in range(1, n):
        sb.append(abs(ord(s[i]) - ord(s[i - 1])))
    
    if n == 2:
        print(sb[0])
        return
    
    s = ''.join(map(str, sb))
    
    if '1' in s:
        print(cal(s, '1'))
    else:
        print(cal(s, '2') * 2)

# Mock input for testing
input_str = """
4
abba
"""
sc = MyScanner(input_str)
solve()
