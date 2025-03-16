
import sys

class TaskD:
    def solve(self, testNumber, in, out):
        S = in.next()
        score = 0
        for i in range(len(S)):
            my = 'g' if i % 2 == 0 else 'p'
            his = S[i]
            if my!= his:
                score += 1 if my == 'p' else -1
        out.println(score)

class InputReader:
    def __init__(self, stream):
        self.reader = sys.stdin
        self.tokenizer = None

    def next(self):
        while self.tokenizer == None or not self.tokenizer.hasMoreTokens():
            self.tokenizer = StringTokenizer(self.reader.readLine())
        return self.tokenizer.nextToken()

if __name__ == '__main__':
    t = TaskD()
    i = InputReader(sys.stdin)
    t.solve(1, i, sys.stdout)

