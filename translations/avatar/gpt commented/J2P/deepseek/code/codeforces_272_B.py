import sys
import io
import os
import math

class FastReader:
    def __init__(self):
        self.buffer = io.BytesIO(os.read(0, os.fstat(0).st_size))
        self.tokens = []

    def readline(self):
        return self.buffer.readline().decode('utf-8').strip()

    def read(self):
        while not self.tokens:
            self.tokens = self.readline().split()
        return self.tokens.pop(0)

    def next_int(self):
        return int(self.read())

    def next_long(self):
        return int(self.read())

    def next_double(self):
        return float(self.read())

def count_set_bits(x):
    answer = 0
    for k in range(31, -1, -1):
        if (x & (1 << k)) != 0:
            answer += 1
    return answer

def main():
    sc = FastReader()
    out = io.TextIOWrapper(sys.stdout)
    
    n = sc.next_int()
    a = [0] * 33
    
    for i in range(n):
        a[count_set_bits(sc.next_int())] += 1
    
    answer = 0
    for i in range(len(a)):
        summ = (1 + a[i] - 1) / 2 * (a[i] - 1)
        answer += summ
    
    out.write(f"{int(answer)}\n")
    out.flush()

if __name__ == "__main__":
    main()
