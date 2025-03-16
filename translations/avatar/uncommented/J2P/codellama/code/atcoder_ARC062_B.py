
import sys

def main():
    inputStream = sys.stdin
    outputStream = sys.stdout
    in = InputReader(inputStream)
    out = PrintWriter(outputStream)
    solver = TaskD()
    solver.solve(1, in, out)
    out.close()

class TaskD:
    def solve(self, testNumber, in, out):
        S = in.next()
        score = 0
        for i in range(len(S)):
            my = i % 2 == 0 and 'g' or 'p'
            his = S[i]
            if my != his:
                score += my == 'p' and 1 or -1
        out.println(score)

class InputReader:
    def __init__(self, stream):
        self.reader = BufferedReader(InputStreamReader(stream))
        self.tokenizer = None

    def next(self):
        while self.tokenizer is None or not self.tokenizer.hasMoreTokens():
            try:
                self.tokenizer = StringTokenizer(self.reader.readLine())
            except IOException as e:
                raise RuntimeException(e)
        return self.tokenizer.nextToken()

class PrintWriter:
    def __init__(self, stream):
        self.writer = BufferedWriter(OutputStreamWriter(stream))

    def println(self, s):
        self.writer.write(s + '\n')

if __name__ == '__main__':
    main()

