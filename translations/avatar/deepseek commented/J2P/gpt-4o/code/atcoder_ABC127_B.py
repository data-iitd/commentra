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
            raise StopIteration

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
        sb = [char]
        char = self.read()
        while not self.eof and not char.isspace():
            sb.append(char)
            char = self.read()
        return ''.join(sb)

    def next_int(self):
        return int(self.next())

    def next_long(self):
        return int(self.next())  # Python's int can handle long integers

    def next_double(self):
        return float(self.next())

def main():
    scanner = SimpleScanner(sys.stdin)
    r = scanner.next_int()
    d = scanner.next_int()
    x = scanner.next_long()

    for _ in range(10):
        x = r * x - d
        print(x)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
