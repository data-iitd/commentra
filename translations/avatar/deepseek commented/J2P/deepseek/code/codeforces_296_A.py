import sys
from collections import Counter

def main():
    input_stream = sys.stdin
    output_stream = sys.stdout
    inp = InputReader(input_stream)
    out = PrintWriter(output_stream)
    solver = Task()
    solver.solve(inp, out)
    out.close()

class Task:
    def solve(self, inp, out):
        n = inp.nextInt()
        array = [0] * 1001
        for i in range(n):
            index = inp.nextInt()
            array[index] += 1
        count_max = -1
        for i in range(1, len(array)):
            if count_max < array[i]:
                count_max = array[i]
        if n % 2 == 0:
            if count_max <= n // 2:
                out.println("YES")
            else:
                out.println("NO")
        else:
            if count_max <= n // 2 + 1:
                out.println("YES")
            else:
                out.println("NO")

class InputReader:
    def __init__(self, stream):
        self.stream = stream
        self.reader = sys.stdin
        self.tokenizer = None

    def next(self):
        while self.tokenizer is None or not self.tokenizer.has_more_tokens():
            try:
                self.tokenizer = self.reader.readline().split()
            except Exception as e:
                raise RuntimeException(e)
        return self.tokenizer.next()

    def nextInt(self):
        return int(self.next())

    def nextLong(self):
        return long(self.next())

    def nextDouble(self):
        return float(self.next())

    def nextLine(self):
        try:
            return self.reader.readline().strip()
        except Exception as e:
            raise RuntimeException(e)

class PrintWriter:
    def __init__(self, stream):
        self.output = stream

    def println(self, s):
        self.output.write(s + '\n')

    def close(self):
        pass

if __name__ == "__main__":
    main()
