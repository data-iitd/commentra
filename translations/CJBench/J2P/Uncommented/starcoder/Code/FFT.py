import math
import cmath
import sys

class Complex:
    def __init__(self, real, img):
        self.real = real
        self.img = img

    def add(self, z):
        return Complex(self.real + z.real, self.img + z.img)

    def subtract(self, z):
        return Complex(self.real - z.real, self.img - z.img)

    def multiply(self, z):
        return Complex(self.real * z.real - self.img * z.img, self.real * z.img + self.img * z.real)

    def multiply(self, n):
        return Complex(self.real * n, self.img * n)

    def divide(self, n):
        return Complex(self.real / n, self.img / n)

    def __str__(self):
        return str(self.real) + " + " + str(self.img) + "i"

def fft(x, inverse):
    n = len(x)
    log2n = int(math.log(n) / math.log(2))
    padToPowerOfTwo(x, log2n)
    bitReversal(x, log2n)
    direction = -1 if inverse else 1
    for len in range(2, n + 1):
        angle = -2 * math.pi / len * direction
        wlen = Complex(math.cos(angle), math.sin(angle))
        for i in range(0, n, len):
            w = Complex(1, 0)
            for j in range(0, len / 2):
                u = x[i + j]
                v = w.multiply(x[i + j + len / 2])
                x[i + j] = u.add(v)
                x[i + j + len / 2] = u.subtract(v)
                w = w.multiply(wlen)
    if inverse:
        for i in range(n):
            x[i] = x[i].divide(n)
    return x

def padToPowerOfTwo(x, log2n):
    n = 1
    while n < len(x):
        n *= 2
    while len(x) < n:
        x.append(Complex(0, 0))

def bitReversal(x, log2n):
    for i in range(len(x)):
        reverse = int(bin(i)[2:].zfill(32)[::-1], 2) >> (32 - log2n)
        if i < reverse:
            x[i], x[reverse] = x[reverse], x[i]

def main():
    n = int(sys.stdin.readline())
    input = []
    for i in range(n):
        real, img = map(float, sys.stdin.readline().split())
        input.append(Complex(real, img))
    inverse = sys.stdin.readline().strip() == "True"
    result = fft(input, inverse)
    print("Main Result:")
    for c in result:
        print(c)

if __name__ == "__main__":
    main()

