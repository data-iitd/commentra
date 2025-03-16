
# <START-OF-CODE>

import sys

class BUnhappyHackingABCEdit:
    def solve(self, testNumber, in, out):
        s = in.string()
        d = []
        for c in s:
            if c == '0':
                d.append('0')
            elif c == '1':
                d.append('1')
            elif c == 'B':
                if len(d) > 0:
                    d.pop()
        out.println(''.join(d))

class LightScanner:
    def __init__(self, in):
        self.reader = in
        self.tokenizer = None

    def string(self):
        if self.tokenizer == None or not self.tokenizer.hasMoreTokens():
            self.tokenizer = StringTokenizer(self.reader.readLine())
        return self.tokenizer.nextToken()

class Main:
    def main(self, args):
        inputStream = sys.stdin
        outputStream = sys.stdout
        in = LightScanner(inputStream)
        out = PrintWriter(outputStream)
        solver = BUnhappyHackingABCEdit()
        solver.solve(1, in, out)
        out.close()

if __name__ == '__main__':
    Main().main(sys.argv)

# 