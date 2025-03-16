import math
from typing import List

class Complex:
    def __init__(self, real=0.0, img=0.0):
        self.real = real
        self.img = img

    def add(self, other):
        return Complex(self.real + other.real, self.img + other.img)

    def subtract(self, other):
        return Complex(self.real - other.real, self.img - other.img)

    def multiply(self, other):
        return Complex(self.real * other.real - self.img * other.img,
                       self.real * other.img + self.img * other.real)

    def divide(self, other):
        denom = other.real ** 2 + other.img ** 2
        return Complex((self.real * other.real + self.img * other.img) / denom,
                       (self.img * other.real - self.real * other.img) / denom)

    def __str__(self):
        return f"{self.real} + {self.img}i"

def fft(x: List[Complex], inverse: bool) -> List[Complex]:
    pad_to_power_of_two(x)
    n = len(x)
    log2n = int(math.log2(n))

    bit_reversal(x, log2n)

    direction = -1 if inverse else 1
    for length in range(2, n + 1, 2):
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

def main():
    n = int(input("Enter the number of complex numbers: "))
    input_data = []
    
    for _ in range(n):
        real, img = map(float, input("Enter real and imaginary parts: ").split())
        input_data.append(Complex(real, img))

    inverse = input("Perform inverse FFT? (True/False): ").strip().lower() == 'true'
    
    result = fft(input_data, inverse)

    print("FFT Result:")
    for c in result:
        print(c)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
