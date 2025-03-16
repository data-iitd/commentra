import sys

def main():
    input_stream = sys.stdin
    output_stream = sys.stdout
    in_reader = InputReader(input_stream)
    out_writer = PrintWriter(output_stream)
    
    a = in_reader.nextInt()
    b = in_reader.nextInt()
    c = in_reader.nextInt()
    d = in_reader.nextInt()
    
    if c > b:
        out_writer.println(0)
    elif a > d:
        out_writer.println(0)
    elif a < c:
        out_writer.println(min(b, d) - c)
    else:
        l = [a, b, c, d]
        l.sort()
        out_writer.println(l[2] - l[1])
    
    out_writer.close()

class InputReader:
    def __init__(self, stream):
        self.reader = sys.stdin
        self.tokenizer = None
    
    def next(self):
        while self.tokenizer is None or not self.tokenizer.has_more_tokens():
            self.tokenizer = StringTokenizer(self.reader.readline())
        return self.tokenizer.next_token()
    
    def nextInt(self):
        return int(self.next())
    
    def nextLong(self):
        return long(self.next())

class PrintWriter:
    def __init__(self, stream):
        self.writer = sys.stdout
    
    def println(self, value):
        self.writer.write(str(value) + '\n')
    
    def close(self):
        self.writer.close()

if __name__ == "__main__":
    main()
