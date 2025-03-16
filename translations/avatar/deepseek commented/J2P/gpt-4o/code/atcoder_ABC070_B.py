import sys

class InputReader:
    def __init__(self, stream):
        self.reader = stream
        self.tokenizer = None

    def next(self):
        if self.tokenizer is None or len(self.tokenizer) == 0:
            self.tokenizer = self.reader.readline().strip().split()
        return self.tokenizer.pop(0)

    def next_int(self):
        return int(self.next())

def main():
    input_reader = InputReader(sys.stdin)

    a = input_reader.next_int()
    b = input_reader.next_int()
    c = input_reader.next_int()
    d = input_reader.next_int()

    if c > b:
        print(0)
    elif a > d:
        print(0)
    elif a < c:
        print(min(b, d) - c)
    else:
        l = [a, b, c, d]
        l.sort()
        print(l[2] - l[1])

if __name__ == "__main__":
    main()

# <END-OF-CODE>
