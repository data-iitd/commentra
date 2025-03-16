
import sys

class Main:
    def __init__(self):
        self.sc = sys.stdin
        self.MOD = 1000000007
        self.MAX = int(1e6)
        self.LMAX = long(1e18)
        self.len = int(1e6) + 1

    def doIt(self):
        N = int(self.sc.readline())
        K = long(self.sc.readline())
        A = [0] * self.len
        for i in range(N):
            A[i] = int(self.sc.readline()) - 1
        used = set()
        idx = [0] * self.len
        pos = [0] * self.len
        next = 0
        cur = 0
        while not used.__contains__(next):
            used.add(next)
            idx[next] = cur
            pos[cur] = next
            next = A[next]
            cur += 1
        a = long(cur) - idx[next]
        b = long(idx[next])
        ans = (10000 * a + K - b) % a + b
        if b > K:
            ans = K
        print(pos[ans] + 1)

if __name__ == '__main__':
    obj = Main()
    obj.doIt()

