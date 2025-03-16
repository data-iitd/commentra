import math
from cmath import exp
from typing import List, Union

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

    def divide(self, n: float) -> 'Complex':
        return Complex(self.real / n, self.img / n)

    def __str__(self) -> str:
        return f"{self.real:.6f} + {self.img:.6f}i"

def fft(x: List[Complex], inverse: bool = False) -> List[Complex]:
    n = len(x)
    if n <= 1:
        return x

    even = fft([x[i] for i in range(0, n, 2)], inverse)
    odd = fft([x[i] for i in range(1, n, 2)], inverse)

    angle = -2 * math.pi / n if not inverse else 2 * math.pi / n
    wlen = Complex(math.cos(angle), math.sin(angle))

    result = [Complex() for _ in range(n)]
    w = Complex(1, 0)
    for i in range(n // 2):
        result[i] = even[i].add(w.multiply(odd[i]))
        result[i + n // 2] = even[i].subtract(w.multiply(odd[i]))
        w = w.multiply(wlen)

    if inverse:
        for i in range(n):
            result[i] = result[i].divide(n)

    return result

def main():
    n = int(input())
    input_list = []
    for _ in range(n):
        real, img = map(float, input().split())
        input_list.append(Complex(real, img))
    inverse = input().lower() == 'true'
    result = fft(input_list, inverse)
    print("FFT Result:")
    for c in result:
        print(c)

if __name__ == "__main__":
    main()
