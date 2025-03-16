import math
from cmath import exp
from typing import List, Tuple

class Complex:
    def __init__(self, real: float = 0, img: float = 0):
        self.real = real
        self.img = img

    def __add__(self, other: 'Complex') -> 'Complex':
        return Complex(self.real + other.real, self.img + other.img)

    def __sub__(self, other: 'Complex') -> 'Complex':
        return Complex(self.real - other.real, self.img - other.img)

    def __mul__(self, other: 'Complex') -> 'Complex':
        return Complex(self.real * other.real - self.img * other.img, self.real * other.img + self.img * other.real)

    def __mul__(self, scalar: float) -> 'Complex':
        return Complex(self.real * scalar, self.img * scalar)

    def __truediv__(self, scalar: float) -> 'Complex':
        return Complex(self.real / scalar, self.img / scalar)

    def __str__(self) -> str:
        return f"{self.real:.6f} + {self.img:.6f}i"

def fft(x: List[Complex], inverse: bool = False) -> List[Complex]:
    n = len(x)
    if n <= 1:
        return x

    even = fft(x[0::2], inverse)
    odd = fft(x[1::2], inverse)

    T = [Complex() for _ in range(n)]
    for k in range(n // 2):
        angle = -2 * math.pi * k / n * (1 if not inverse else -1)
        w_k = Complex(math.cos(angle), math.sin(angle))
        T[k] = even[k] + w_k * odd[k]
        T[k + n // 2] = even[k] - w_k * odd[k]

    return T

def pad_to_power_of_two(x: List[Complex]) -> List[Complex]:
    n = 1
    while n < len(x):
        n *= 2
    while len(x) < n:
        x.append(Complex())
    return x

def bit_reversal_permutation(x: List[Complex], log2n: int) -> List[Complex]:
    for i in range(len(x)):
        rev = 0
        for j in range(log2n):
            rev |= (i >> j & 1) << (log2n - 1 - j)
        if i < rev:
            x[i], x[rev] = x[rev], x[i]
    return x

def main():
    n = int(input())
    input_signal = [Complex(float(input().split()[0]), float(input().split()[1])) for _ in range(n)]
    inverse = input().strip() == 'True'

    padded_signal = pad_to_power_of_two(input_signal)
    log2n = int(math.log2(len(padded_signal)))
    permuted_signal = bit_reversal_permutation(padded_signal, log2n)

    fft_result = fft(permuted_signal, inverse)
    print("FFT Result:")
    for c in fft_result:
        print(c)

if __name__ == "__main__":
    main()
