
import sys

class Main:
    def __init__(self, in_):
        self.in_ = in_
        self.A, self.B, self.K = map(int, self.in_.readline().split())
        self.x, self.y = 0, 0

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

