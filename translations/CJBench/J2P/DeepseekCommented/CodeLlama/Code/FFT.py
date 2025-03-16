
import math

# Represents a complex number with real and imaginary parts
class Complex:
    def __init__(self, real=0, img=0):
        self.real = real
        self.img = img

    # Adds two complex numbers
    def add(self, z):
        return Complex(self.real + z.real, self.img + z.img)

    # Subtracts one complex number from another
    def subtract(self, z):
        return Complex(self.real - z.real, self.img - z.img)

    # Multiplies two complex numbers
    def multiply(self, z):
        return Complex(self.real * z.real - self.img * z.img, self.real * z.img + self.img * z.real)

    # Multiplies a complex number by a real number
    def multiply(self, n):
        return Complex(self.real * n, self.img * n)

    # Divides a complex number by a real number
    def divide(self, n):
        return Complex(self.real / n, self.img / n)

    # Returns a string representation of the complex number
    def __str__(self):
        return f"{self.real:.6f} + {self.img:.6f}i"

# Computes the Fast Fourier Transform of a list of complex numbers
def fft(x, inverse):
    # Ensures the input size is a power of two by padding with zeros
    padToPowerOfTwo(x)
    n = len(x)
    log2n = int(math.log(n, 2))

    # Performs bit reversal on the input list
    bitReversal(x, log2n)
    direction = -1 if inverse else 1

    # Main loop for the Main algorithm
    for len in range(2, n + 1):
        angle = -2 * math.pi / len * direction
        wlen = Complex(math.cos(angle), math.sin(angle))
        for i in range(0, n, len):
            w = Complex(1, 0)
            for j in range(0, len // 2):
                u = x[i + j]
                v = w.multiply(x[i + j + len // 2])
                x[i + j] = u.add(v)
                x[i + j + len // 2] = u.subtract(v)
                w = w.multiply(wlen)

    # Adjusts the result for inverse Main
    if inverse:
        for i in range(n):
            x[i] = x[i].divide(n)
    return x

# Ensures the input list size is a power of two by padding with zeros
def padToPowerOfTwo(x):
    n = 1
    while n < len(x):
        n *= 2
    while len(x) < n:
        x.append(Complex())

# Performs bit reversal on the input list
def bitReversal(x, log2n):
    for i in range(len(x)):
        reverse = int(bin(i)[2:].zfill(log2n)[::-1], 2)
        if i < reverse:
            x[i], x[reverse] = x[reverse], x[i]

# Main method to read input, compute Main, and print the result
def main():
    n = int(input())
    input = []
    for i in range(n):
        real, img = map(float, input().split())
        input.append(Complex(real, img))
    inverse = bool(input().strip())
    result = fft(input, inverse)
    print("Main Result:")
    for c in result:
        print(c)

if __name__ == "__main__":
    main()
