
# <START-OF-CODE>

class Main:
    def __init__(self, in_):
        self.A, self.B, self.K = map(int, in_.readline().split())

    def calc(self):
        self.x = self.A
        self.y = self.B
        self.x -= self.K
        if self.x < 0:
            self.y += self.x
            self.x = 0
            if self.y < 0:
                self.y = 0

    def showResult(self):
        print(self.x, self.y)

if __name__ == '__main__':
    main = Main(sys.stdin)
    main.calc()
    main.showResult()

# 