import math
from typing import List

class Complex:
    def __init__(self, r=0.0, i=0.0):
        self.real = r
        self.img = i

    def add(self, z):
        return Complex(self.real + z.real, self.img + z.img)

    def subtract(self, z):
        return Complex(self.real - z.real, self.img - z.img)

    def multiply(self, z):
        return Complex(self.real * z.real - self.img * z.img, self.real * z.img + self.img * z.real)

    def multiply_scalar(self, n):
        return Complex(self.real * n, self.img * n)

    def divide(self, n):
        return Complex(self.real / n, self.img / n)

    def __str__(self):
        return f"{self.real:.6f} + {self.img:.6f}i"

def fft(x: List[Complex], inverse: bool) -> List[Complex]:
    pad_to_power_of_two(x)
    n = len(x)
    log2n = int(math.log2(n))
    bit_reversal(x, log2n)

    direction = -1 if inverse else 1

    for length in range(2, n + 1, length * 2):
        angle = -2 * math.pi / length * direction
        wlen = Complex(math.cos(angle), math.sin(angle))
        for i in range(0, n, length):
            w = Complex(1, 0)
            for j in range(length // 2):
                u = x[i + j]
                v = w.multiply(x[i + j + length // 2])
                x[i + j] = u.add(v)
                x[i + j + length // 2] = u.subtract(v)
                w = w.multiply(wlen)

    if inverse:
        for i in range(n):
            x[i] = x[i].divide(n)

    return x

def pad_to_power_of_two(x: List[Complex]):
    n = 1
    while n < len(x):
        n *= 2
    while len(x) < n:
        x.append(Complex())

def bit_reversal(x: List[Complex], log2n: int):
    for i in range(len(x)):
        reverse = int('{:0{width}b}'.format(i, width=log2n)[::-1], 2)
        if i < reverse:
            x[i], x[reverse] = x[reverse], x[i]

if __name__ == "__main__":
    n = int(input())
    input_data = []
    for _ in range(n):
        real, img = map(float, input().split())
        input_data.append(Complex(real, img))
    inverse = bool(int(input()))

    result = fft(input_data, inverse)
    print("Main Result:")
    for c in result:
        print(c)

# <END-OF-CODE>
