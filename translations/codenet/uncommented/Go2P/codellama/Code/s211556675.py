
import sys

def main():
    sc = Scanner()
    wtr = sys.stdout
    A, B, C, K = sc.nextInt(), sc.nextInt(), sc.nextInt(), sc.nextInt()
    ma = max(A, B, C)
    rest = 0
    if ma == A:
        rest += B + C
    elif ma == B:
        rest += A + C
    else:
        rest += A + B
    for i in range(1, K+1):
        ma *= 2

    print(ma+rest, file=wtr)


class Scanner:
    def __init__(self):
        self.sc = sys.stdin.readline

    def nextInt(self):
        return int(self.sc().strip())

    def nextStr(self):
        return self.sc().strip()

    def nextFloat(self):
        return float(self.sc().strip())

    def nextRuneSlice(self):
        return list(self.sc().strip())

    def nextIntSlice(self, n):
        return [self.nextInt() for i in range(n)]

    def nextFloatSlice(self, n):
        return [self.nextFloat() for i in range(n)]


if __name__ == "__main__":
    main()

