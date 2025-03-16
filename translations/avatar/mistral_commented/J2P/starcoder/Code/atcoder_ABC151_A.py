
import sys

class RemRing:
    def __init__(self, module):
        self.module = module

    def sum(self, a, b):
        return (a + b + self.module) % self.module

    def sub(self, a, b):
        return (a - b + self.module) % self.module

    def prod(self, a, b):
        return (a * b) % self.module

    def div(self, a, b):
        quotient = a * self.inv(b)
        return quotient % self.module

    def inv(self, a):
        b = self.module
        u = 1
        v = 0

        while b > 0:
            t = a // b
            z = a
            a = b
            b = z % self.module
            temp = u
            u = v
            v = temp - t * v

        if u < 0:
            u += self.module

        return u

def main():
    r = RemRing(1000000007)
    s = sys.stdin.readline().strip()
    print(chr(ord(s[0]) + 1), end='')

if __name__ == '__main__':
    main()

