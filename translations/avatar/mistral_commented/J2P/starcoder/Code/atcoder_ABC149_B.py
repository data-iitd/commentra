
import sys

class Main:
    def __init__(self, in):
        self.in = in
        self.A = 0
        self.B = 0
        self.K = 0
        self.x = 0
        self.y = 0

    def calc(self):
        self.x = self.A
        self.y = self.B

        self.x = self.A - self.K

        if self.x < 0:
            self.y = self.B + self.x
            self.x = 0

        if self.y < 0:
            self.y = 0

    def showResult(self):
        print(self.x, self.y)

if __name__ == "__main__":
    ins = Main(sys.stdin)
    ins.calc()
    ins.showResult()

