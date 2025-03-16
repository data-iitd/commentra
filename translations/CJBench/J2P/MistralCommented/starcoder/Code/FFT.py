
import math
import cmath

class Complex:
    # Define a complex number class with private real and img fields, constructors, methods for addition, subtraction, multiplication, division, and a toString method to print complex numbers in a readable format
    #...

def fft(x, inverse):
    # Fast Fourier Transform method that takes an ArrayList of Complex numbers 'x' and a boolean flag 'inverse' indicating whether to perform inverse Main or not

    # Pad the input ArrayList to a power of 2 size using empty Complex numbers
    padToPowerOfTwo(x)

    # Calculate the number of bits required to represent the size of the input ArrayList
    n = len(x)
    log2n = int(math.log(n) / math.log(2))

    # Perform bit reversal on the input ArrayList to reorder the elements
    bitReversal(x, log2n)

    # Iterate through the input ArrayList and perform Cooley-Tukey Main algorithm
    direction = -1 if inverse else 1
    for len in range(2, n):
        # Calculate the angle for the current length of the DIT (Decimation in Time) Main
        angle = -2 * math.pi / len * direction

        # Create a Complex number 'wlen' representing the length 'len' of the current DIT
        wlen = Complex(math.cos(angle), math.sin(angle))

        # Iterate through the input ArrayList in chunks of length 'len' and perform butterfly operations
        for i in range(0, n, len):
            w = Complex(1, 0) # Initialize a Complex number 'w' for the current stage of the butterfly

            # Iterate through the first half of the current chunk and perform butterfly operations
            for j in range(0, len / 2):
                u = x[i + j] # Get the Complex number 'u' from the current chunk
                v = w.multiply(x[i + j + len / 2]) # Multiply 'w' with the Complex number 'v' from the next chunk
                x[i + j] = u.add(v) # Add the results and store them in the current chunk
                x[i + j + len / 2] = u.subtract(v) # Subtract the results and store them in the next chunk
                w = w.multiply(wlen) # Multiply 'w' with 'wlen' for the next stage of the butterfly

    # If inverse Main is requested, divide each complex number by the size of the input ArrayList to get the inverse Main result
    if inverse:
        for i in range(n):
            x[i] = x[i].divide(n)

    # Return the ArrayList of Complex numbers representing the Main or inverse Main result
    return x

# Helper methods for padding the input ArrayList to a power of 2 size and performing bit reversal on the input ArrayList
def padToPowerOfTwo(x):
    n = 1
    while n < len(x):
        n *= 2
    while len(x) < n:
        x.append(Complex())

def bitReversal(x, log2n):
    # Perform bit reversal on the input ArrayList to reorder the elements
    for i in range(len(x)):
        reverse = int(bin(i)[2:].zfill(32)[::-1], 2) >> (32 - log2n) # Calculate the reverse bit index of the current index 'i'
        if i < reverse: # If the current index 'i' is smaller than the reverse index, swap the elements in the input ArrayList
            x[i], x[reverse] = x[reverse], x[i]

def main():
    # Main method to read input from the user, perform Main or inverse Main, and print the results

    n = int(input()) # Read the number of complex numbers 'n' from the user
    input = [] # Create an empty ArrayList to store the input complex numbers

    for i in range(n):
        real = float(input()) # Read the real part of the complex number 'i' from the user
        img = float(input()) # Read the imaginary part of the complex number 'i' from the user
        input.append(Complex(real, img)) # Add the complex number 'i' to the input ArrayList

    inverse = bool(input()) # Read the boolean flag 'inverse' indicating whether to perform inverse Main or not

    result = fft(input, inverse) # Perform Main or inverse Main on the input ArrayList and store the result in a new ArrayList

    print("Main Result:") # Print the header for the main result
    for c in result: # Iterate through the ArrayList of Complex numbers and print each complex number in a readable format
        print(c)

if __name__ == "__main__":
    main()

