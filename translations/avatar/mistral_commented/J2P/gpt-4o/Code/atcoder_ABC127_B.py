import sys

class SimpleScanner:
    def __init__(self, input_stream):
        self.in_stream = input_stream
        self.buffer = ""
        self.eof = False

    def read(self):
        if not self.buffer:
            self.buffer = self.in_stream.read(1)
            if not self.buffer:
                self.eof = True
                return ''
        char = self.buffer[0]
        self.buffer = self.buffer[1:]
        return char

    def check_eof(self):
        if self.eof:
            raise Exception("No more elements")

    def next_char(self):
        self.check_eof()
        char = self.read()
        self.check_eof()
        return char

    def next(self):
        sb = []
        while True:
            b = self.read()
            self.check_eof()
            if b.isspace() and sb:
                break
            if not b.isspace():
                sb.append(b)
        return ''.join(sb)

    def next_int(self):
        return int(self.next())

    def next_long(self):
        return int(self.next())  # Python's int can handle long integers

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

# <END-OF-CODE>
