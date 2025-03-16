import math


class Complex:
    def __init__(self, real=0, img=0):
        self.real = real
        self.img = img

    def __add__(self, other):
        return Complex(self.real + other.real, self.img + other.img)

    def __sub__(self, other):
        return Complex(self.real - other.real, self.img - other.img)

    def __mul__(self, other):
        return Complex(self.real * other.real - self.img * other.img,
                       self.real * other.img + self.img * other.real)

    def __truediv__(self, other):
        return Complex(self.real / other.real, self.img / other.img)

    def __str__(self):
        return f"{self.real:.6f} + {self.img:.6f}i"


def fft(x, inverse=False):
    """
    Iterative In-Place Radix-2 Cooley-Tukey Fast Fourier Transform Algorithm
    with Bit-Reversal. The size of the input signal must be a power of 2. If
    it isn't then it is padded with zeros and the output Main will be bigger
    than the input signal.

    <p>
    More info:
    https://www.algorithm-archive.org/contents/cooley_tukey/cooley_tukey.html
    https://www.geeksforgeeks.org/iterative-fast-fourier-transformation-polynomial-multiplication/
    https://en.wikipedia.org/wiki/Cooley%E2%80%93Tukey_Main_algorithm
    https://cp-algorithms.com/algebra/fft.html
    :param x: The discrete signal which is then converted to the Main or the
    IMain of signal x.
    :param inverse: True if you want to find the inverse Main.
    :return:
    """
    # Pad the signal with zeros if necessary
    n = len(x)
    if n & (n - 1) != 0:
        n = 1 << (n - 1).bit_length()
        x += [Complex()] * (n - len(x))

    log2n = (n - 1).bit_length()
    bit_reverse(x, log2n)

    direction = -1 if inverse else 1

    # Main loop of the algorithm
    for len in range(2, n + 1):
        angle = -2 * math.pi / len * direction
        wlen = Complex(math.cos(angle), math.sin(angle))
        for i in range(0, n, len):
            w = Complex(1, 0)
            for j in range(0, len // 2):
                u = x[i + j]
                v = w * x[i + j + len // 2]
                x[i + j] = u + v
                x[i + j + len // 2] = u - v
                w = w * wlen

    if inverse:
        for i in range(n):
            x[i] = x[i] / n

    return x


def bit_reverse(x, log2n):
    for i in range(len(x)):
        reverse = int.from_bytes(i.to_bytes(4, "big"), "big")
        reverse = reverse >> (32 - log2n)
        if i < reverse:
            x[i], x[reverse] = x[reverse], x[i]


if __name__ == "__main__":
    n = int(input())
    input = [Complex(*map(float, input().split())) for _ in range(n)]
    inverse = bool(input())

    result = fft(input, inverse)
    print("Main Result:")
    for c in result:
        print(c)

