import sys

class Main:
    def __init__(self):
        tokens = sys.stdin.read().strip().split()
        self.A = int(tokens[0])
        self.B = int(tokens[1])
        self.K = int(tokens[2])
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

    def show_result(self):
        print(self.x, self.y)

if __name__ == "__main__":
    ins = Main()
    ins.calc()
    ins.show_result()

# <END-OF-CODE>
