
import sys

class Main:
    def __init__(self):
        self.input = sys.stdin
        self.output = sys.stdout

    def solve(self):
        n = int(self.input.readline())
        array = [0] * 1001
        for i in range(n):
            index = int(self.input.readline())
            array[index] += 1
        countMax = -1
        for i in range(1, len(array)):
            if countMax < array[i]:
                countMax = array[i]
        if n % 2 == 0:
            if countMax <= n / 2:
                self.output.write("YES\n")
            else:
                self.output.write("NO\n")
        else:
            if countMax <= n / 2 + 1:
                self.output.write("YES\n")
            else:
                self.output.write("NO\n")

if __name__ == "__main__":
    obj = Main()
    obj.solve()

