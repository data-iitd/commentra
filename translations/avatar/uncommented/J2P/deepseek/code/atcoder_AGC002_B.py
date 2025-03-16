class Box:
    def __init__(self, n, r):
        self.num = n
        self.red = r

    def moveTo(self, other):
        if self.num == 0:
            return
        elif self.num == 1:
            self.num = 0
            other.num += 1
            if self.red:
                other.red = True
            self.red = False
        else:
            self.num -= 1
            other.num += 1
            if self.red:
                other.red = True

def main():
    sc = Scanner()
    N = sc.nextInt()
    M = sc.nextInt()
    B = [Box(1, True) if i == 0 else Box(1, False) for i in range(N)]
    for _ in range(M):
        x = sc.nextInt() - 1
        y = sc.nextInt() - 1
        B[x].moveTo(B[y])
    counter = sum(1 for b in B if b.red)
    print(counter)

class Scanner:
    def __init__(self):
        self.data = []
        self.index = 0

    def nextInt(self):
        # Simulate reading an integer from input
        value = int(self.data[self.index])
        self.index += 1
        return value

    def readInput(self):
        # Simulate reading the entire input
        self.data = input().split()

# Simulate reading the input
sc = Scanner()
sc.readInput()
main()
