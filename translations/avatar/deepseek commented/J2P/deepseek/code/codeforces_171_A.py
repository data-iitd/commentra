import sys
import io
import os
import re

class FastReader:
    def __init__(self):
        self.input_stream = io.TextIOWrapper(sys.stdin.buffer, encoding='utf-8')

    def next(self):
        while not hasattr(self, 'tokenizer') or not self.tokenizer.hasmore:
            try:
                self.tokenizer = re.split(r'\s+', self.input_stream.readline().decode('utf-8').strip())
            except Exception as e:
                print(e)
                exit()
        result = self.tokenizer[0]
        self.tokenizer = self.tokenizer[1:]
        return result

    def nextInt(self):
        return int(self.next())

    def nextLong(self):
        return int(self.next())

    def nextDouble(self):
        return float(self.next())

    def nextLine(self):
        try:
            return self.input_stream.readline().decode('utf-8').strip()
        except Exception as e:
            print(e)
            exit()

def reverse(n):
    if n < 10:
        return n * 10
    t = n
    r = 0
    while t > 0:
        r = (r * 10) + (t % 10)
        t = t // 10
    return r

def main():
    sc = FastReader()
    n = sc.nextInt()
    m = sc.nextInt()
    t = reverse(m)
    print(t + n)

if __name__ == "__main__":
    main()
