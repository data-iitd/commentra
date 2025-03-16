
import sys

def main():
    n = int(sys.stdin.readline())
    b = int(sys.stdin.readline())
    ans = []
    q = []
    for i in range(n):
        t = int(sys.stdin.readline())
        d = int(sys.stdin.readline())
        while q and q[0] <= t:
            q.pop(0)
        if len(q) <= b:
            ans.append((q[0] if q else t) + d)
            q.append(ans[-1])
        else:
            ans.append(-1)
    for a in ans:
        print(a, end=' ')

if __name__ == '__main__':
    main()

