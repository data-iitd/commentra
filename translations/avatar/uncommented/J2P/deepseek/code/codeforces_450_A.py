from collections import deque
import sys

def main():
    n, m = map(int, sys.stdin.readline().split())
    q1 = deque(map(int, sys.stdin.readline().split()))
    q2 = deque(range(1, n + 1))
    ans = 0

    while q1:
        if q1[0] <= m:
            ans = q2.popleft()
            q1.popleft()
        else:
            x = q1.popleft()
            val = x - m
            q1.append(val)
            q2.append(q2.popleft())

    print(ans)

if __name__ == "__main__":
    main()
