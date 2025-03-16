import sys

class SimpleScanner:
    def __init__(self, in_stream):
        self.in_stream = in_stream
        self.buffer = ""
        self.eof = False

    def read(self):
        if not self.buffer:
            try:
                self.buffer = self.in_stream.read(10240).decode('utf-8')
            except:
                self.eof = True
                return '\0'
        return self.buffer[0]

    def check_eof(self):
        if self.eof:
            raise EOFError

    def next_char(self):
        self.check_eof()
        b = self.read()
        self.check_eof()
        return b

    def next(self):
        b = None
        while b is None or b.isspace():
            b = self.read()
            self.check_eof()
        sb = []
        while not self.eof and not b.isspace():
            sb.append(b)
            b = self.read()
            self.check_eof()
        return ''.join(sb)

    def next_int(self):
        return int(self.next())

    def next_long(self):
        return int(self.next())  # Python's int can handle large integers

    def next_double(self):
        return float(self.next())

def main():
    scanner = SimpleScanner(sys.stdin)
    writer = sys.stdout
    r = scanner.next_int()
    d = scanner.next_int()
    x = scanner.next_long()
    for _ in range(10):
        x = r * x - d
        writer.write(f"{x}\n")

if __name__ == "__main__":
    main()
