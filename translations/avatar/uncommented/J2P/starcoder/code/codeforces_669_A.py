
# <START-OF-CODE>

import sys

def solve(n):
    print((n//3)*2 + (n%3==0))

if __name__ == '__main__':
    n = int(sys.stdin.readline())
    solve(n)

# 