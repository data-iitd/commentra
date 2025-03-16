
import sys

class Main:
    def __init__(self):
        self.t = 1
        self.arr = []
        self.prevWinner = 0

    def solve(self):
        while self.t > 0:
            self.arr.append(int(input()))
            if self.arr[self.t - 1] == 1:
                if self.prevWinner == 0:
                    self.prevWinner = 2
                if (self.t - 1) % 2 == 0:
                    print(self.prevWinner == 0 and 2 or 1)
                    self.prevWinner = self.prevWinner == 0 and 2 or 1
            self.t -= 1

if __name__ == '__main__':
    obj = Main()
    obj.solve()

