import math
from typing import List, Optional

class Complex:
    def __init__(self, real: float = 0.0, img: float = 0.0):
        self.real = real
        self.img = img

    def add(self, other: 'Complex') -> 'Complex':
        return Complex(self.real + other.real, self.img + other.img)

    def subtract(self, other: 'Complex') -> 'Complex':
        return Complex(self.real - other.real, self.img - other.img)

    def multiply(self, other: 'Complex') -> 'Complex':
        return Complex(self.real * other.real - self.img * other.img, self.real * other.img + self.img * other.real)

    def divide(self, other: 'Complex') -> 'Complex':
        denominator = other.real ** 2 + other.img ** 2
        return Complex((self.real * other.real + self.img * other.img) / denominator, (self.img * other.real - self.real * other.img) / denominator)

    def __str__(self) -> str:
        return f"{self.real} + {self.img}i"

def fft(x: List[Complex], inverse: bool = False) -> List[Complex]:
    # Fast Fourier Transform method that takes a list of Complex numbers 'x' and a boolean flag 'inverse' indicating whether to perform inverse FFT or not

    # Pad the input list to a power of 2 size using empty Complex numbers
    pad_to_power_of_two(x)

    # Calculate the number of bits required to represent the size of the input list
    n = len(x)
    log2n = int(math.log2(n))

    # Perform bit reversal on the input list to reorder the elements
    bit_reversal(x, log2n)

    # Iterate through the input list and perform Cooley-Tukey FFT algorithm
    direction = -1 if inverse else 1
    for len in range(2, n + 1, 2):
        # Calculate the angle for the current length of the DIT (Decimation in Time) FFT
        angle = -2 * math.pi / len * direction

        # Create a Complex number 'wlen' representing the length 'len' of the current DIT
        wlen = Complex(math.cos(angle), math.sin(angle))

        # Iterate through the input list in chunks of length 'len' and perform butterfly operations
        for i in range(0, n, len):
            w = Complex(1, 0)  # Initialize a Complex number 'w' for the current stage of the butterfly

            # Iterate through the first half of the current chunk and perform butterfly operations
            for j in range(0, len // 2):
                u = x[i + j]  # Get the Complex number 'u' from the current chunk
                v = w.multiply(x[i + j + len // 2])  # Multiply 'w' with the Complex number 'v' from the next chunk
                x[i + j] = u.add(v)  # Add the results and store them in the current chunk
                x[i + j + len // 2] = u.subtract(v)  # Subtract the results and store them in the next chunk
                w = w.multiply(wlen)  # Multiply 'w' with 'wlen' for the next stage of the butterfly

    # If inverse FFT is requested, divide each complex number by the size of the input list to get the inverse FFT result
    if inverse:
        for i in range(n):
            x[i] = x[i].divide(n)

    # Return the list of Complex numbers representing the FFT or inverse FFT result
    return x

# Helper methods for padding the input list to a power of 2 size and performing bit reversal on the input list
def pad_to_power_of_two(x: List[Complex]) -> None:
    n = 1
    while n < len(x):
        n *= 2
    while len(x) < n:
        x.append(Complex())

def bit_reversal(x: List[Complex], log2n: int) -> None:
    # Perform bit reversal on the input list to reorder the elements
    for i in range(len(x)):
        reverse = i
        reverse = ((reverse >> 1) & 0x55555555) | ((reverse & 0x55555555) << 1)
        reverse = ((reverse >> 2) & 0x33333333) | ((reverse & 0x33333333) << 2)
        reverse = ((reverse >> 4) & 0x0F0F0F0F) | ((reverse & 0x0F0F0F0F) << 4)
        reverse = ((reverse >> 8) & 0x00FF00FF) | ((reverse & 0x00FF00FF) << 8)
        reverse = ((reverse >> 16) & 0x0000FFFF) | ((reverse & 0x0000FFFF) << 16)
        reverse = reverse >> (32 - log2n)
        if i < reverse:
            x[i], x[reverse] = x[reverse], x[i]

# Main method to read input from the user, perform FFT or inverse FFT, and print the results
if __name__ == "__main__":
    import sys
    input = sys.stdin.read
    data = input().split()

    n = int(data[0])  # Read the number of complex numbers 'n' from the user
    input_complex = [Complex(float(data[i * 2 + 1]), float(data[i * 2 + 2])) for i in range(n)]  # Create a list to store the input complex numbers

    inverse = bool(int(data[n * 2 + 1]))  # Read the boolean flag 'inverse' indicating whether to perform inverse FFT or not

    result = fft(input_complex, inverse)  # Perform FFT or inverse FFT on the input list and store the result in a new list

    print("Main Result:")  # Print the header for the main result
    for c in result:  # Iterate through the list of Complex numbers and print each complex number in a readable format
        print(c)
