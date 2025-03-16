import sys

class SimpleScanner:
    def __init__(self, input_stream):
        self.input_stream = input_stream
        self.buffer = []
        self.eof = False

    def read(self):
        if not self.buffer:
            line = self.input_stream.readline()
            if not line:
                self.eof = True
                return ''
            self.buffer = list(line)
        return self.buffer.pop(0)

    def check_eof(self):
        if self.eof:
            raise NoSuchElementException()

    def next_char(self):
        self.check_eof()
        char = self.read()
        self.check_eof()
        return char

    def next(self):
        char = self.read()
        self.check_eof()
        while char.isspace():
            char = self.read()
            self.check_eof()
        
        token = []
        while char and not char.isspace():
            token.append(char)
            char = self.read()
        return ''.join(token)

    def next_int(self):
        return int(self.next())

    def next_long(self):
        return int(self.next())  # Python's int can handle long values

    def next_double(self):
        return float(self.next())

class NoSuchElementException(Exception):
    pass

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
