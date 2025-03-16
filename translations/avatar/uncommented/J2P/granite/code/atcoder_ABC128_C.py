
import sys

def main():
    main = Main()
    main.run()

class Main:
    def run(self):
        sc = Scanner(sys.stdin)
        N = sc.nextInt()
        M = sc.nextInt()
        a = [0] * N
        for i in range(M):
            k = sc.nextInt()
            for j in range(k):
                s = sc.nextInt()
                s -= 1
                a[s] |= (1 << i)
        p = 0
        for i in range(M):
            x = sc.nextInt()
            p |= (x << i)
        ans = 0
        for s in range(1 << N):
            t = 0
            for i in range(N):
                if (s >> i) & 1 == 1:
                    t ^= a[i]
            if p == t:
                ans += 1
        print(ans)
        sc.close()

class Scanner:
    def __init__(self, file):
        self.file = file
        self.line = 0

    def nextInt(self):
        line = self.file.readline()
        self.line += 1
        return int(line)

    def close(self):
        self.file.close()

if __name__ == "__main__":
    main()

