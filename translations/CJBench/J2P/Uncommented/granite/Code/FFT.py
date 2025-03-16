
import cmath
import math

class Complex:
    def __init__(self, real, img):
        self.real = real
        self.img = img

    def __add__(self, z):
        return Complex(self.real + z.real, self.img + z.img)

    def __sub__(self, z):
        return Complex(self.real - z.real, self.img - z.img)

    def __mul__(self, z):
        return Complex(self.real * z.real - self.img * z.img, self.real * z.img + self.img * z.real)

    def __mul__(self, n):
        return Complex(self.real * n, self.img * n)

    def __truediv__(self, n):
        return Complex(self.real / n, self.img / n)

    def __str__(self):
        return f"{self.real:.6f} + {self.img:.6f}i"

def fft(x, inverse=False):
    n = len(x)
    log2n = math.log2(n)
    x.extend([Complex(0, 0)] * (2 ** log2n - n))
    bit_reverse(x, log2n)
    direction = -1 if inverse else 1
    for len in range(2, n + 1):
        angle = -2 * math.pi / len * direction
        wlen = cmath.exp(complex(0, angle))
        for i in range(0, n, len):
            w = 1
            for j in range(len // 2):
                u = x[i + j]
                v = w * x[i + j + len // 2]
                x[i + j] = u + v
                x[i + j + len // 2] = u - v
                w *= wlen
    if inverse:
        for i in range(n):
            x[i] /= n
    return x

def bit_reverse(x, log2n):
    for i in range(len(x)):
        reverse = int.from_bytes(i.to_bytes(4, "big"), "big") >> (32 - log2n)
        if i < reverse:
            x[i], x[reverse] = x[reverse], x[i]

if __name__ == "__main__":
    n = int(input())
    x = [Complex(*map(float, input().split())) for _ in range(n)]
    inverse = bool(int(input()))
    result = fft(x, inverse)
    print("Main Result:")
    for c in result:
        print(c)

