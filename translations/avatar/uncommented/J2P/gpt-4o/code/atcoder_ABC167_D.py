class Main:
    def __init__(self):
        self.MOD = 1000000007
        self.MAX = float('inf')
        self.LMAX = float('inf')
        self.len = int(1e6) + 1

    def doIt(self):
        import sys
        input = sys.stdin.read
        data = input().split()
        
        N = int(data[0])
        K = int(data[1])
        A = [int(data[i + 2]) - 1 for i in range(N)]
        
        used = set()
        idx = [0] * N
        pos = [0] * N
        next = 0
        cur = 0
        
        while next not in used:
            used.add(next)
            idx[next] = cur
            pos[cur] = next
            next = A[next]
            cur += 1
        
        a = cur - idx[next]
        b = idx[next]
        ans = (10000 * a + K - b) % a + b
        
        if b > K:
            ans = K
        
        print(pos[ans] + 1)

if __name__ == "__main__":
    Main().doIt()
# <END-OF-CODE>
