import sys

class SimpleScanner:
    def __init__(self, in_stream):
        self.in_stream = in_stream
        self.buffer = ""
        self.eof = False

    def read(self):
        if not self.buffer:
            try:
                self.buffer = self.in_stream.read().decode('utf-8')
            except:
                self.buffer = ""
                self.eof = True
                return '\0'
            if not self.buffer:
                self.eof = True
                return '\0'
        return self.buffer[0]

    def check_eof(self):
        if self.eof:
            raise Exception("No such element")

    def next_char(self):
        self.check_eof()
        b = self.read()
        self.check_eof()
        return b

    def next(self):
        result = []
        b = None
        while True:
            b = self.read()
            self.check_eof()
            if b == ' ' or b == '\n' or b == '\t' or b == '\r':
                continue
            else:
                break
        while True:
            result.append(b)
            b = self.read()
            self.check_eof()
            if b == ' ' or b == '\n' or b == '\t' or b == '\r':
                break
        return ''.join(result)

    def next_int(self):
        return int(self.next())

    def next_long(self):
        return int(self.next())  # Python's int can handle large numbers

    def next_double(self):
        return float(self.next())


def main():
    scanner = SimpleScanner(sys.stdin.buffer)
    writer = sys.stdout

    r = scanner.next_int()
    d = scanner.next_int()
    x = scanner.next_long()

    for i in range(10):
        x = r * x - d
        writer.write(f"{x}\n".encode('utf-8'))


if __name__ == "__main__":
    main()

