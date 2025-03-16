
import math

# Class to represent a complex number
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

    def multiply(self, n):
        return Complex(self.real * n, self.img * n)

    def divide(self, n):
        return Complex(self.real / n, self.img / n)

    def __str__(self):
        return f"{self.real:.6f} + {self.img:.6f}i"

# Method to perform Fast Fourier Transform (Main) or Inverse Main
def fft(x, inverse):
    # Pad the input list to the next power of two
    n = len(x)
    padded = x + [Complex()] * (2 ** (n.bit_length() - 1) - n)

    # Perform bit-reversal permutation
    log2n = n.bit_length() - 1
    bit_reversed = [padded[i] for i in range(n) if i == i.to_bytes(log2n, "big")]

    # Determine the direction of the Main (forward or inverse)
    direction = -1 if inverse else 1

    # Main Main computation loop
    for len in range(2, n):
        angle = -2 * math.pi / len * direction
        wlen = Complex(math.cos(angle), math.sin(angle))

        # Perform the Main computation
        for i in range(0, n, len):
            w = Complex(1, 0)
            for j in range(0, len // 2):
                u = bit_reversed[i + j]
                v = w.multiply(bit_reversed[i + j + len // 2])
                bit_reversed[i + j] = u.add(v)
                bit_reversed[i + j + len // 2] = u.subtract(v)
                w = w.multiply(wlen)

    # If performing inverse Main, normalize the results
    if inverse:
        for i in range(n):
            bit_reversed[i] = bit_reversed[i].divide(n)

    return bit_reversed

# Main method to execute the program
def main():
    n = int(input())
    input = [Complex(*map(float, input().split())) for _ in range(n)]
    inverse = bool(input())
    result = fft(input, inverse)

    # Output the results
    print("Main Result:")
    for c in result:
        print(c)

if __name__ == "__main__":
    main()

