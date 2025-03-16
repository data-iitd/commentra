import sys
import array

def main():
    input_stream = sys.stdin
    output_stream = sys.stdout
    in_reader = InputReader(input_stream)
    out_writer = PrintWriter(output_stream)
    solution = Solution()
    solution.solve(in_reader, out_writer)
    out_writer.close()

class Solution:
    def solve(self, in_reader, out_writer):
        n = in_reader.ni()
        k = in_reader.ni()
        a = array.array('i', [in_reader.ni() for _ in range(n)])
        a.sort()
        ans = sum(a[:k])
        out_writer.write(str(ans) + '\n')

class InputReader:
    def __init__(self, stream):
        self.reader = stream
        self.tokenizer = None

    def n(self):
        while self.tokenizer is None or not self.tokenizer.has_more_tokens():
            try:
                self.tokenizer = self.reader.readline().split()
            except Exception as e:
                raise RuntimeError(e)
        return self.tokenizer[0]

    def ni(self):
        return int(self.n())

class PrintWriter:
    def __init__(self, stream):
        self.writer = stream

    def write(self, data):
        self.writer.write(data)

    def close(self):
        self.writer.close()

if __name__ == "__main__":
    main()
