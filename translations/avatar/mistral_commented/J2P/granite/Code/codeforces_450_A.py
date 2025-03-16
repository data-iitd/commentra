

import sys
from collections import deque

def main():
    n, m = map(int, sys.stdin.readline().split())
    q1 = deque()
    q2 = deque()
    for i in range(1, n + 1):
        q1.append(int(sys.stdin.readline()))
        q2.append(i)
    ans = 0
    while q1:
        if q1[0] <= m:
            q1.popleft()
            ans = q2.popleft()
        else:
            x = q1.popleft()
            val = x - m
            q1.append(val)
            val2 = q2.popleft()
            q2.append(val2)
    print(ans)

if __name__ == "__main__":
    main()

These comments should provide a clear understanding of the code logic for each block.