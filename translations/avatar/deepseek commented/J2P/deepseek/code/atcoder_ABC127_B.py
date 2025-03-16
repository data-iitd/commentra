import sys

class SimpleScanner:
    def __init__(self, input_stream):
        self.input_stream = input_stream
        self.buffer = bytearray(10240)
        self.position = 0
        self.limit = 0
        self.eof = False

    def read(self):
        if self.position >= self.limit:
            self.position = 0
            self.limit = self.input_stream.read(self.buffer)
            if self.limit == 0:
                self.eof = True
                return '\0'
        char = chr(self.buffer[self.position])
        self.position += 1
        return char

    def check_eof(self):
        if self.eof:
            raise EOFError

    def next_char(self):
        self.check_eof()
        char = self.read()
        self.check_eof()
        return char

    def next(self):
        char = None
        while char is None or char.isspace():
            char = self.read()
            self.check_eof()
        result = []
        while not self.eof and not char.isspace():
            result.append(char)
            char = self.read()
            self.check_eof()
        return ''.join(result)

    def next_int(self):
        return int(self.next())

    def next_long(self):
        return int(self.next())  # Python's int can handle large numbers

    def next_double(self):
        return float(self.next())

def main():
    scanner = SimpleScanner(sys.stdin)
    writer = sys.stdout.write

    r = scanner.next_int()
    d = scanner.next_int()
    x = scanner.next_long()

    for _ in range(10):
        x = r * x - d
        writer(f"{x}\n")

if __name__ == "__main__":
    main()
