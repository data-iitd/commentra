

import sys

def cal(s, c):
    n = len(s)
    m = n - 1
    ans = 0
    for i in range(n):
        if s[i] == c and (m & i) == i:
            ans ^= 1
    return ans

def solve():
    n = int(input())
    for testCase in range(1, n + 1):
        num = int(input())
        s = input()
        sb = []
        for i in range(1, num):
            sb.append(abs(ord(s[i]) - ord(s[i - 1])))
        if num == 2:
            print(s[0])
            continue
        s = ''.join(map(str, sb))
        if '1' in s:
            print(cal(s, '1'))
        else:
            print(cal(s, '2') * 2)

if __name__ == "__main__":
    sys.setrecursionlimit(10**6)
    solve()

