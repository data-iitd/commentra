
import sys

class Main:
    def __init__(self):
        self.input = FastScanner()
        self.n = self.input.nextInt()
        self.map = {}
        for i in range(self.n):
            val = self.input.nextInt()
            self.map[val] = self.map.get(val, 0) + 1
        self.max = -sys.maxsize
        for val in self.map.values():
            self.max = max(self.max, val)
        print(self.max, len(self.map))

class FastScanner:
    def __init__(self):
        self.br = sys.stdin
        self.st = " "

    def next(self):
        while self.st == " ":
            self.st = self.br.readline()
        token = self.st.split()[0]
        self.st = self.st[len(token):]
        return token

    def nextInt(self):
        return int(self.next())

    def nextLong(self):
        return long(self.next())

    def nextDouble(self):
        return float(self.next())

    def nextLine(self):
        return str(self.br.readline())

if __name__ == '__main__':
    obj = Main()

