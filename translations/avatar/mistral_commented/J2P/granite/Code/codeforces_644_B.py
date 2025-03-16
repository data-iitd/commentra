
import sys
from collections import deque

def main():
    n, b = map(int, input().split())
    ans = []
    q = deque()

    for _ in range(n):
        t, d = map(int, input().split())

        while q and q[0] <= t:
            q.popleft()

        if len(q) <= b:
            ans.append(q[-1] + d if q else t)
            q.append(ans[-1])
        else:
            ans.append(-1)

    print(*ans)

if __name__ == "__main__":
    main()

