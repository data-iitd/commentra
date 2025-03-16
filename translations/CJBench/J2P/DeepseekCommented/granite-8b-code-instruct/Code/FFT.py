
import cmath
import math

# Represents a complex number with real and imaginary parts
class Complex:
    def __init__(self, real=0, img=0):
        self.real = real
        self.img = img

    # Adds two complex numbers
    def __add__(self, z):
        return Complex(self.real + z.real, self.img + z.img)

    # Subtracts one complex number from another
    def __sub__(self, z):
        return Complex(self.real - z.real, self.img - z.img)

    # Multiplies two complex numbers
    def __mul__(self, z):
        return Complex(self.real * z.real - self.img * z.img, self.real * z.img + self.img * z.real)

    # Multiplies a complex number by a real number
    def __rmul__(self, n):
        return Complex(self.real * n, self.img * n)

    # Divides a complex number by a real number
    def __truediv__(self, n):
        return Complex(self.real / n, self.img / n)

    # Returns a string representation of the complex number
    def __str__(self):
        return f"{self.real:.6f} + {self.img:.6f}i"

# Computes the Fast Fourier Transform of a list of complex numbers
def fft(x, inverse=False):
    n = len(x)
    log2n = math.log2(n)

    # Ensures the input size is a power of two by padding with zeros
    x += [Complex() for _ in range(n, 2**log2n)]

    # Performs bit reversal on the input list
    for i in range(n):
        reverse = int.from_bytes(i.to_bytes(4, "big"), "big") >> (32 - log2n)
        if i < reverse:
            x[i], x[reverse] = x[reverse], x[i]

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

    # Adjusts the result for inverse Main
    if inverse:
        for i in range(n):
            x[i] /= n

    return x

# Main method to read input, compute Main, and print the result
if __name__ == "__main__":
    n = int(input())
    input = [Complex(*map(float, input().split())) for _ in range(n)]
    inverse = bool(int(input()))
    result = fft(input, inverse)
    print("Main Result:")
    for c in result:
        print(c)

