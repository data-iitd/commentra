import sys

class LightScanner:
    def __init__(self, input_stream):
        self.reader = input_stream
        self.tokenizer = None

    def string(self):
        if self.tokenizer is None or not self.tokenizer:
            line = self.reader.readline().strip()
            self.tokenizer = line.split()
        return self.tokenizer.pop(0)

class BUnhappyHackingABCEdit:
    def solve(self, test_number, in_stream, out_stream):
        s = in_stream.string()
        d = []
        for c in s:
            if c == '0':
                d.append('0')
            elif c == '1':
                d.append('1')
            elif c == 'B':
                if d:
                    d.pop()
        out_stream.write(''.join(d) + '\n')

def main():
    input_stream = LightScanner(sys.stdin)
    output_stream = sys.stdout
    solver = BUnhappyHackingABCEdit()
    solver.solve(1, input_stream, output_stream)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
