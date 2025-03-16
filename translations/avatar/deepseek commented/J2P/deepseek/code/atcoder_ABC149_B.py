import sys

class Main:
    def __init__(self, inp):
        tokens = inp.readline().split()
        self.A = int(tokens[0])
        self.B = int(tokens[1])
        self.K = int(tokens[2])
        self.x, self.y = self.A, self.B

    def calc(self):
        self.x = self.A - self.K
        if self.x < 0:
            self.y = self.B + self.x
            self.x = 0 if self.x < 0 else self.x
            if self.y < 0:
                self.y = 0

    def showResult(self):
        print(f"{self.x} {self.y}")

# Read from stdin
inp = sys.stdin.readline

# Create an instance of Main and perform the calculation
ins = Main(inp)
ins.calc()
ins.showResult()
