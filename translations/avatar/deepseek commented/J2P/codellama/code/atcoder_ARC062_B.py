import sys

# The main method initializes input and output streams, creates an instance of TaskD, and calls its solve method
def main():
    inputStream = sys.stdin
    outputStream = sys.stdout
    in = InputReader(inputStream)
    out = PrintWriter(outputStream)
    solver = TaskD()
    solver.solve(1, in, out)
    out.close()

# The TaskD class contains the solve method which calculates a score based on the input string
class TaskD:
    # The solve method takes a test number, an InputReader instance, and a PrintWriter instance
    def solve(self, testNumber, in, out):
        S = in.next()
        score = 0
        for i in range(len(S)):
            my = 'g' if i % 2 == 0 else 'p'
            his = S[i]
            if my != his:
                score += 1 if my == 'p' else -1
        out.println(score)

# The InputReader class is used to read input efficiently
class InputReader:
    def __init__(self, stream):
        self.reader = stream
        self.tokenizer = None

    # Method to read the next token from the input stream
    def next(self):
        while self.tokenizer is None or not self.tokenizer.hasMoreTokens():
            try:
                self.tokenizer = self.reader.readline()
            except Exception as e:
                raise RuntimeError(e)
        return self.tokenizer.nextToken()

# The PrintWriter class is used to write output efficiently
class PrintWriter:
    def __init__(self, stream):
        self.writer = stream

    # Method to write a string to the output stream
    def println(self, string):
        self.writer.write(string + '\n')

# The StringTokenizer class is used to tokenize input strings
class StringTokenizer:
    def __init__(self, string):
        self.string = string
        self.index = 0

    # Method to check if there are more tokens
    def hasMoreTokens(self):
        return self.index < len(self.string)

    # Method to get the next token
    def nextToken(self):
        token = ''
        while self.index < len(self.string) and self.string[self.index] != ' ':
            token += self.string[self.index]
            self.index += 1
        self.index += 1
        return token

# The RuntimeError class is used to throw runtime errors
class RuntimeError(Exception):
    pass

# The IOException class is used to throw I/O errors
class IOException(Exception):
    pass

if __name__ == '__main__':
    main()

