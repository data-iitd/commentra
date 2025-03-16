import math
import cmath
import sys

# Class to represent a complex number
class Complex:
    def __init__(self, real, img):
        self.real = real
        self.img = img

    # Method to add two complex numbers
    def add(self, z):
        return Complex(self.real + z.real, self.img + z.img)

    # Method to subtract one complex number from another
    def subtract(self, z):
        return Complex(self.real - z.real, self.img - z.img)

    # Method to multiply two complex numbers
    def multiply(self, z):
        return Complex(self.real * z.real - self.img * z.img, self.real * z.img + self.img * z.real)

    # Method to multiply a complex number by a real number
    def multiply(self, n):
        return Complex(self.real * n, self.img * n)

    # Method to divide a complex number by a real number
    def divide(self, n):
        return Complex(self.real / n, self.img / n)

    # Override toString method to format complex number as a string
    def __str__(self):
        return str(self.real) + " + " + str(self.img) + "i"

# Method to perform Fast Fourier Transform (Main) or Inverse Main
def fft(x, inverse):
    # Pad the input list to the next power of two
    padToPowerOfTwo(x)
    n = len(x) # Size of the input array
    log2n = int(math.log(n) / math.log(2)) # Calculate log base 2 of n
    bitReversal(x, log2n) # Perform bit-reversal permutation

    # Determine the direction of the Main (forward or inverse)
    direction = -1 if inverse else 1

    # Main Main computation loop
    for len in range(2, n):
        angle = -2 * math.pi / len * direction # Calculate angle for the current length
        wlen = Complex(math.cos(angle), math.sin(angle)) # Calculate the complex root of unity

        # Perform the Main computation
        for i in range(0, n, len):
            w = Complex(1, 0) # Initialize w to 1
            for j in range(0, len / 2):
                u = x[i + j] # First half of the data
                v = w.multiply(x[i + j + len / 2]) # Second half of the data
                x[i + j] = u.add(v) # Combine results
                x[i + j + len / 2] = u.subtract(v) # Store results
                w = w.multiply(wlen) # Update w for the next iteration

    # If performing inverse Main, normalize the results
    if inverse:
        for i in range(0, n):
            x[i] = x[i].divide(n) # Divide each element by n
    return x # Return the transformed array

# Method to pad the input array to the next power of two
def padToPowerOfTwo(x):
    n = 1
    # Find the next power of two greater than or equal to the size of x
    while n < len(x):
        n *= 2
    # Add zero-initialized complex numbers until the size is a power of two
    while len(x) < n:
        x.append(Complex(0, 0))

# Method to perform bit-reversal permutation on the input array
def bitReversal(x, log2n):
    for i in range(0, len(x)):
        reverse = int(bin(i)[2:].zfill(32)[::-1], 2) >> (32 - log2n) # Calculate the bit-reversed index
        # Swap elements if necessary
        if i < reverse:
            x[i], x[reverse] = x[reverse], x[i]

# Main method to execute the program
if __name__ == "__main__":
    n = int(sys.stdin.readline()) # Read the number of complex numbers
    input = [] # Initialize the input list

    # Read complex numbers from input
    for i in range(0, n):
        real, img = map(float, sys.stdin.readline().split()) # Read real and imaginary parts
        input.append(Complex(real, img)) # Add complex number to the list

    inverse = sys.stdin.readline().strip() == "true" # Read whether to perform inverse Main
    result = fft(input, inverse) # Perform Main or inverse Main

    # Output the results
    print("Main Result:")
    for c in result:
        print(c) # Print each complex number in the result

