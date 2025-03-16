
# <START-OF-CODE>

import sys

class Main:
    def __init__(self):
        self.t = int(sys.stdin.readline())
        self.arr = []
        self.prevWinner = 0
        for i in range(self.t):
            self.arr.append(int(sys.stdin.readline()))

    def solve(self):
        for i in range(self.t):
            if self.arr[i] == 1:
                if self.prevWinner == 0:
                    self.prevWinner = 2
                else:
                    if (self.arr[i] - 1) % 2 == 0:
                        print(2)
                        self.prevWinner = 2
                    else:
                        print(1)
                        self.prevWinner = 1
            else:
                if self.prevWinner == 2:
                    if (self.arr[i] - 1) % 2 == 0:
                        print(2)
                        self.prevWinner = 2
                    else:
                        print(1)
                        self.prevWinner = 1
                else:
                    if (self.arr[i] - 1) % 2 == 0:
                        print(1)
                        self.prevWinner = 1
                    else:
                        print(2)
                        self.prevWinner = 2

if __name__ == "__main__":
    obj = Main()
    obj.solve()

# 