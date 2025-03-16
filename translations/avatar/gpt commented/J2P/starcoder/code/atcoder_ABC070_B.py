import sys

class Main:
    def main(self):
        # Set up input and output streams
        inputStream = sys.stdin
        outputStream = sys.stdout
        in = InputReader(inputStream)
        out = PrintWriter(outputStream)

        # Read four integers from input
        a = in.nextInt()
        b = in.nextInt()
        c = in.nextInt()
        d = in.nextInt()

        # Check conditions to determine the output
        if c > b:
            # If c is greater than b, output 0
            out.println(0)
        elif a > d:
            # If a is greater than d, output 0
            out.println(0)
        elif a < c:
            # If a is less than c, calculate and output the difference
            out.println(min(b, d) - c)
        else:
            # Create a list to hold the four integers
            l = []
            l.append(a)
            l.append(b)
            l.append(c)
            l.append(d)

            # Sort the list to find the second largest and third largest values
            l.sort()

            # Output the difference between the second largest and third largest values
            out.println(l[2] - l[1])

# InputReader class to handle input reading
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

    def nextInt(self):
        return Integer.parseInt(self.next())

    def nextLong(self):
        return Long.parseLong(self.next())

# 