import math
from cmath import exp
from collections import deque

class Complex:
    def __init__(self, real=0, img=0):
        self.real = real
        self.img = img

    def add(self, z):
        return Complex(self.real + z.real, self.img + z.img)

    def subtract(self, z):
        return Complex(self.real - z.real, self.img - z.img)

    def multiply(self, z):
        return Complex(self.real * z.real - self.img * z.img, self.real * z.img + self.img * z.real)

    def multiply_scalar(self, n):
        return Complex(self.real * n, self.img * n)

    def divide_scalar(self, n):
        return Complex(self.real / n, self.img / n)

    def __str__(self):
        return f"{self.real:.6f} + {self.img:.6f}i"

def fft(x, inverse=False):
    n = len(x)
    if n <= 1:
        return x
    even = fft(x[0::2], inverse)
    odd = fft(x[1::2], inverse)
    T = [Complex() for _ in range(n)]
    n_inv = 1 / n if inverse else 1
    for k in range(n // 2):
        angle = -2 * math.pi * k / n * (1 if not inverse else -1)
        w = Complex(math.cos(angle), math.sin(angle))
        T[k] = even[k].add(w.multiply(odd[k]))
        T[k + n // 2] = even[k].subtract(w.multiply(odd[k]))
    return T

def pad_to_power_of_two(x):
    n = 1
    while n < len(x):
        n *= 2
    while len(x) < n:
        x.append(Complex())

def bit_reversal(x, log2n):
    for i in range(len(x)):
        reverse = int('{:0{width}b}'.format(i, width=log2n)[::-1], 2)
        if i < reverse:
            x[i], x[reverse] = x[reverse], x[i]

def main():
    n = int(input())
    input_data = [Complex(float(input().split()[0]), float(input().split()[1])) for _ in range(n)]
    inverse = input().strip() == 'True'
    pad_to_power_of_two(input_data)
    result = fft(input_data, inverse)
    print("Main Result:")
    for c in result:
        print(c)

if __name__ == "__main__":
    main()
