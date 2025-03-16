import math
from typing import List, Optional

class Complex:
    def __init__(self, real: float = 0, img: float = 0):
        self.real = real
        self.img = img

    def add(self, z: 'Complex') -> 'Complex':
        return Complex(self.real + z.real, self.img + z.img)

    def subtract(self, z: 'Complex') -> 'Complex':
        return Complex(self.real - z.real, self.img - z.img)

    def multiply(self, z: 'Complex') -> 'Complex':
        return Complex(self.real * z.real - self.img * z.img, self.real * z.img + self.img * z.real)

    def multiply_real(self, n: float) -> 'Complex':
        return Complex(self.real * n, self.img * n)

    def divide_real(self, n: float) -> 'Complex':
        return Complex(self.real / n, self.img / n)

    def __str__(self) -> str:
        return f"{self.real:.6f} + {self.img:.6f}i"

def fft(x: List[Complex], inverse: bool = False) -> List[Complex]:
    def pad_to_power_of_two(x: List[Complex]) -> List[Complex]:
        n = 1
        while n < len(x):
            n *= 2
        while len(x) < n:
            x.append(Complex())
        return x

    def bit_reversal(x: List[Complex], log2n: int) -> List[Complex]:
        for i in range(len(x)):
            reverse = int(bin(i)[2:].zfill(log2n)[::-1], 2)
            if i < reverse:
                x[i], x[reverse] = x[reverse], x[i]
        return x

    x = pad_to_power_of_two(x)
    n = len(x)
    log2n = int(math.log2(n))
    x = bit_reversal(x, log2n)

    direction = -1 if inverse else 1

    for len in range(2, n + 1, 2):
        angle = -2 * math.pi / len * direction
        wlen = Complex(math.cos(angle), math.sin(angle))

        for i in range(0, n, len):
            w = Complex(1, 0)
            for j in range(len // 2):
                u = x[i + j]
                v = w.multiply(x[i + j + len // 2])
                x[i + j] = u.add(v)
                x[i + j + len // 2] = u.subtract(v)
                w = w.multiply(wlen)

    if inverse:
        for i in range(n):
            x[i] = x[i].divide_real(n)

    return x

def main():
    import sys
    input = sys.stdin.read
    data = input().split()

    n = int(data[0])
    input_data = []
    for i in range(1, n + 1):
        real = float(data[i])
        img = float(data[i + n])
        input_data.append(Complex(real, img))

    inverse = bool(int(data[2 * n + 1]))
    result = fft(input_data, inverse)

    print("Main Result:")
    for c in result:
        print(c)

if __name__ == "__main__":
    main()
