import sys

class SimpleScanner:
    def __init__(self, in_stream):
        self.in = in_stream
        self.buffer = ""
        self.eof = False

    def read(self):
        if self.eof:
            return None
        if len(self.buffer) == 0:
            try:
                self.buffer = self.in.read(10240)
            except:
                self.eof = True
                return None
            if len(self.buffer) == 0:
                self.eof = True
                return None
        c = self.buffer[0]
        self.buffer = self.buffer[1:]
        return c

    def next_char(self):
        c = self.read()
        if c is None:
            raise NoSuchElementException()
        return c

    def next(self):
        c = self.next_char()
        while c.isspace():
            c = self.next_char()
        s = c
        while True:
            c = self.read()
            if c is None or c.isspace():
                break
            s += c
        return s

    def next_int(self):
        return int(self.next())

    def next_long(self):
        return long(self.next())

    def next_double(self):
        return float(self.next())

class Main:
    def __init__(self):
        self.scanner = SimpleScanner(sys.stdin)
        self.writer = sys.stdout

    def run(self):
        r = self.scanner.next_int()
        d = self.scanner.next_int()
        x = self.scanner.next_long()
        for i in range(10):
            x = r * x - d
            self.writer.write(str(x) + "\n")

if __name__ == "__main__":
    main = Main()
    main.run()

# 