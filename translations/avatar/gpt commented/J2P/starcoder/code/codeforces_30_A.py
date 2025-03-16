import sys

class Main:
    def __init__(self):
        self.sc = sys.stdin

    def solve(self):
        A = int(self.sc.readline())
        B = int(self.sc.readline())
        n = int(self.sc.readline())

        if A == 0:
            if B == 0:
                print(1)
            else:
                print("No solution")
            return

        if B % A!= 0:
            print("No solution")
            return

        B /= A

        neg = B < 0
        if neg and n % 2 == 0:
            print("No solution")
            return

        if neg:
            B = -B

        for x in range(0, B + 1):
            if x ** n == B:
                print(neg * -x)
                return

        print("No solution")

if __name__ == "__main__":
    Main().solve()

