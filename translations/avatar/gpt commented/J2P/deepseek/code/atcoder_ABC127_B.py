import sys

class SimpleScanner:
    def __init__(self, input_stream):
        self.input_stream = input_stream
        self.buffer = ""
        self.eof = False

    def read(self):
        if not self.buffer:
            try:
                self.buffer = self.input_stream.read()
            except IOError:
                self.buffer = ""
                self.eof = True
                return '\0'
            if not self.buffer:
                self.eof = True
                return '\0'
        return self.buffer[0]

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
        return int(self.next())  # Python's int can handle large integers

    def next_double(self):
        return float(self.next())

def main():
    scanner = SimpleScanner(sys.stdin.readline)
    writer = sys.stdout.write

    r = scanner.next_int()
    d = scanner.next_int()
    x = scanner.next_long()

    for _ in range(10):
        x = r * x - d
        writer(f"{x}\n")

if __name__ == "__main__":
    main()
