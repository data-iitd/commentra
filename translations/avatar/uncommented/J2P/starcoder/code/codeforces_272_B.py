
# <START-OF-CODE>

import sys

class FastReader:
    def __init__(self):
        self.buf = sys.stdin.buffer
        self.lines = self.buf.readlines

    def readline(self):
        return self.lines().decode('ascii').strip()

    def read(self):
        return self.buf.read().decode('ascii').strip()

    def nextInt(self):
        return int(self.read())

    def nextLong(self):
        return int(self.read())

    def nextDouble(self):
        return float(self.read())

def rec(x):
    answer = 0
    for k in range(31, -1, -1):
        if (x & (1 << k))!= 0:
            answer += 1
    return answer

def main():
    reader = FastReader()
    n = reader.nextInt()
    a = [0] * 33
    for i in range(n):
        a[rec(reader.nextInt())] += 1
    answer = 0
    for i in range(33):
        summ = (1 + a[i] - 1) / 2.0 * (a[i] - 1)
        answer += summ
    print(int(answer))

if __name__ == '__main__':
    main()

# 