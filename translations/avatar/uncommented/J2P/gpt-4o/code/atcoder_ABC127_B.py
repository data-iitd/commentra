import sys

class SimpleScanner:
    def __init__(self, input_stream):
        self.input_stream = input_stream
        self.buffer = []
        self.eof = False

    def read(self):
        if not self.buffer:
            self.buffer = list(self.input_stream.readline())
            if not self.buffer:
                self.eof = True
                return ''
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
        while char.isspace():
            char = self.read()
        sb = [char]
        while not self.eof and not char.isspace():
            char = self.read()
            sb.append(char)
        return ''.join(sb).strip()

    def next_int(self):
        return int(self.next())

    def next_long(self):
        return int(self.next())

    def next_double(self):
        return float(self.next())

class NoSuchElementException(Exception):
    pass

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
