
import sys

class Main:
    def __init__(self, in_file):
        self.in_file = in_file
        self.A, self.B, self.K = map(int, self.in_file.readline().split())

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

if __name__ == '__main__':
    Main(sys.stdin).calc()
    Main(sys.stdin).showResult()

