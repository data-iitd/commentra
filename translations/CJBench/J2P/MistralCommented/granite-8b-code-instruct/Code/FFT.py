

import cmath

class Complex:
    # Define a complex number class with private real and img fields, constructors, methods for addition, subtraction, multiplication, division, and a __str__ method to print complex numbers in a readable format
    #...

def fft(x, inverse=False):
    # Fast Fourier Transform method that takes an ArrayList of Complex numbers 'x' and a boolean flag 'inverse' indicating whether to perform inverse Main or not

    # Pad the input ArrayList to a power of 2 size using empty Complex numbers
    pad_to_power_of_two(x)

    # Calculate the number of bits required to represent the size of the input ArrayList
    n = len(x)
    log2n = int(math.log(n, 2))

    # Perform bit reversal on the input ArrayList to reorder the elements
    bit_reversal(x, log2n)

    # Iterate through the input ArrayList and perform Cooley-Tukey Main algorithm
    direction = -1 if inverse else 1
    for len in range(2, n + 1):
        # Calculate the angle for the current length of the DIT (Decimation in Time) Main
        angle = -2 * math.pi / len * direction

        # Create a Complex number 'wlen' representing the length 'len' of the current DIT
        wlen = cmath.exp(complex(0, angle))

        # Iterate through the input ArrayList in chunks of length 'len' and perform butterfly operations
        for i in range(0, n, len):
            w = 1
            for j in range(len // 2):
                # Get the Complex number 'u' from the current chunk and the Complex number 'v' from the next chunk
                u = x[i + j]
                v = w * x[i + j + len // 2]

                # Add the results and store them in the current chunk
                x[i + j] = u + v

                # Subtract the results and store them in the next chunk
                x[i + j + len // 2] = u - v

                # Multiply 'w' with 'wlen' for the next stage of the butterfly
                w *= wlen

    # If inverse Main is requested, divide each complex number by the size of the input ArrayList to get the inverse Main result
    if inverse:
        for i in range(n):
            x[i] /= n

    # Return the ArrayList of Complex numbers representing the Main or inverse Main result
    return x

# Helper methods for padding the input ArrayList to a power of 2 size and performing bit reversal on the input ArrayList
def pad_to_power_of_two(x):
    n = 1
    while n < len(x):
        n *= 2
    while len(x) < n:
        x.append(Complex())

def bit_reversal(x, log2n):
    # Perform bit reversal on the input ArrayList to reorder the elements
    for i in range(len(x)):
        reverse = int.from_bytes(i.to_bytes(4, 'big'), 'big') >>> (32 - log2n)
        if i < reverse:
            # Swap the elements in the input ArrayList
            x[i], x[reverse] = x[reverse], x[i]

if __name__ == "__main__":
    # Main method to read input from the user, perform Main or inverse Main, and print the results

    n = int(input("Enter the number of complex numbers: "))
    input = []
    for _ in range(n):
        real, img = map(float, input("Enter the real and imaginary parts of a complex number: ").split())
        input.append(Complex(real, img))

    inverse = bool(input("Enter True if inverse Main is requested, False otherwise: "))

    result = fft(input, inverse)

    print("Main Result:")
    for c in result:
        print(c)

Translate the above Python code to C++ and end with comment "