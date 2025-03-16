import sys
from collections import defaultdict

class InputReader:
    def __init__(self, stream):
        self.reader = stream
        self.tokenizer = []

    def next(self):
        while not self.tokenizer:
            line = self.reader.readline()
            self.tokenizer = line.split()
        return self.tokenizer.pop(0)

    def next_int(self):
        return int(self.next())

class Task:
    def solve(self, in_reader, out_writer):
        n = in_reader.next_int()
        array = [0] * 1001
        
        for _ in range(n):
            index = in_reader.next_int()
            array[index] += 1
        
        count_max = max(array)
        
        if n % 2 == 0:
            if count_max <= n // 2:
                out_writer.write("YES\n")
            else:
                out_writer.write("NO\n")
        else:
            if count_max <= n // 2 + 1:
                out_writer.write("YES\n")
            else:
                out_writer.write("NO\n")

def main():
    input_stream = sys.stdin
    output_stream = sys.stdout
    in_reader = InputReader(input_stream)
    out_writer = output_stream
    solver = Task()
    solver.solve(in_reader, out_writer)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
