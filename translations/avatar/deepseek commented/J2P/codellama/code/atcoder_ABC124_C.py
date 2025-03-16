import sys

def main():
    inputStream = sys.stdin
    outputStream = sys.stdout
    in = InputReader(inputStream)
    out = PrintWriter(outputStream)
    solver = CColoringColorfully()
    solver.solve(1, in, out)
    out.close()

class CColoringColorfully:
    def solve(self, testNumber, in, out):
        # Read the input string
        x = in.next()
        # Create two StringBuilder objects to manipulate the string
        a = StringBuilder(x)
        b = StringBuilder(x)
        # Initialize counters for the number of changes needed
        a1 = 0
        a2 = 0

        # First loop to change characters to make the string colorful
        for i in range(1, len(x)):
            if a.charAt(i) == a.charAt(i - 1):
                # Change the character to the opposite
                if a.charAt(i) == '1':
                    a.setCharAt(i, '0')
                else:
                    a.setCharAt(i, '1')
                # Increment the counter
                a1 += 1

        # Second loop to change characters to make the string colorful
        for i in range(len(x) - 1, 0, -1):
            if b.charAt(i) == b.charAt(i - 1):
                # Change the character to the opposite
                if b.charAt(i - 1) == '1':
                    b.setCharAt(i - 1, '0')
                else:
                    b.setCharAt(i - 1, '1')
                # Increment the counter
                a2 += 1

        # Output the minimum number of changes needed
        out.println(min(a1, a2))

class InputReader:
    def __init__(self, stream):
        self.reader = BufferedReader(InputStreamReader(stream), 32768)
        self.tokenizer = None

    def next(self):
        while self.tokenizer == None or not self.tokenizer.hasMoreTokens():
            try:
                self.tokenizer = StringTokenizer(self.reader.readLine())
            except IOException as e:
                raise RuntimeException(e)
        return self.tokenizer.nextToken()

class StringBuilder:
    def __init__(self, string):
        self.string = string

    def charAt(self, index):
        return self.string[index]

    def setCharAt(self, index, char):
        self.string = self.string[:index] + char + self.string[index + 1:]

class PrintWriter:
    def __init__(self, stream):
        self.writer = BufferedWriter(OutputStreamWriter(stream))

    def println(self, string):
        self.writer.write(string + '\n')

    def close(self):
        self.writer.close()

if __name__ == '__main__':
    main()

