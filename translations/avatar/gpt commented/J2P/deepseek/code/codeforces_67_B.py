import sys

class Main:
    def __init__(self):
        self.out = sys.stdout
        self.out.flush()
    
    def main(self):
        sc = Scanner()
        n = sc.nextInt()
        k = sc.nextInt()
        
        bb = [0] * n
        for i in range(n):
            bb[i] = sc.nextInt()
        
        aa = [0] * n
        m = 0
        
        for a in range(n - 1, -1, -1):
            j = 0
            while bb[a] > 0:
                if aa[j] >= a + k:
                    bb[a] -= 1
                j += 1
            for j_ in range(m, j):
                aa[j_] = aa[j_ - 1]
            aa[j] = a
            m += 1
        
        for i in range(n):
            self.out.write(str(aa[i] + 1) + " ")
        self.out.write("\n")
        self.out.flush()

class Scanner:
    def __init__(self):
        self.tokens = []
    
    def nextInt(self):
        while not self.tokens:
            self.tokens = input().split()
        return int(self.tokens.pop(0))

if __name__ == "__main__":
    main = Main()
    main.main()
