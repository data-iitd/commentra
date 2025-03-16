import sys

class SimpleScanner:
    def __init__(self, in_):
        self.in_ = in_
        self.buffer = ''
        self.eof = False

    def read(self):
        if not self.buffer:
            self.buffer = self.in_.read(10240)
            if not self.buffer:
                self.eof = True
                return '\0'
        return self.buffer[0]

    def checkEof(self):
        if self.eof:
            raise NoSuchElementException()

    def nextChar(self):
        self.checkEof()
        c = self.read()
        self.checkEof()
        return c

    def next(self):
        self.checkEof()
        c = self.read()
        self.checkEof()
        while c.isspace():
            c = self.read()
            self.checkEof()
        s = c
        while not self.eof and not c.isspace():
            c = self.read()
            self.checkEof()
            s += c
        return s

    def nextInt(self):
        return int(self.next())

    def nextLong(self):
        return long(self.next())

    def nextDouble(self):
        return float(self.next())

scanner = SimpleScanner(sys.stdin)
writer = sys.stdout
r = scanner.nextInt()
d = scanner.nextInt()
x = scanner.nextLong()
for i in range(10):
    x = r * x - d
    writer.write(str(x) + '\n')
writer.close()
#