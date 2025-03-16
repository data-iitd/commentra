import math
import cmath

class Complex:
    def __init__(self, real=0, imag=0):
        self.real = real
        self.imag = imag

    def __add__(self, other):
        return Complex(self.real + other.real, self.imag + other.imag)

    def __sub__(self, other):
        return Complex(self.real - other.real, self.imag - other.imag)

    def __mul__(self, other):
        return Complex(self.real * other.real - self.imag * other.imag, self.real * other.imag + self.imag * other.real)

    def __truediv__(self, other):
        return Complex(self.real / other.real, self.imag / other.imag)

    def __str__(self):
        return f"{self.real} + {self.imag}i"

def fft(x, inverse=False):
    n = len(x)
    log2n = int(math.log2(n))
    bit_reversal(x, log2n)
    direction = -1 if inverse else 1
    for len in range(2, n):
        angle = -2 * math.pi / len * direction
        wlen = Complex(math.cos(angle), math.sin(angle))
        for i in range(0, n, len):
            w = Complex(1, 0)
            for j in range(0, len // 2):
                u = x[i + j]
                v = w * x[i + j + len // 2]
                x[i + j] = u + v
                x[i + j + len // 2] = u - v
                w = w * wlen
    if inverse:
        for i in range(n):
            x[i] = x[i] / n
    return x

def bit_reversal(x, log2n):
    for i in range(len(x)):
        reverse = int(bin(i)[2:].zfill(log2n)[::-1], 2)
        if i < reverse:
            x[i], x[reverse] = x[reverse], x[i]

if __name__ == "__main__":
    n = int(input())
    input = [Complex(*map(float, input().split())) for _ in range(n)]
    inverse = bool(input())
    result = fft(input, inverse)
    print("Main Result:")
    for c in result:
        print(c)

