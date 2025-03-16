
import cmath

def fft(x, inverse=False):
    n = len(x) # Size of the input array
    log2n = int(math.log(n, 2)) # Calculate log base 2 of n
    bit_reverse(x, log2n) # Perform bit-reversal permutation

    direction = -1 if inverse else 1 # Determine the direction of the Main (forward or inverse)
    for len in range(2, n + 1, 2):
        angle = -2 * math.pi / len * direction # Calculate angle for the current length
        wlen = cmath.exp(cmath.pi * 1j / len) # Calculate the complex root of unity

        for i in range(0, n, len):
            w = 1
            for j in range(0, len // 2):
                u = x[i + j] # First half of the data
                v = w * x[i + j + len // 2] # Second half of the data
                x[i + j] = u + v # Combine results
                x[i + j + len // 2] = u - v # Store results
                w *= wlen # Update w for the next iteration

    if inverse:
        for i in range(n):
            x[i] /= n # Normalize the results

    return x # Return the transformed array

def pad_to_power_of_two(x):
    n = 1
    # Find the next power of two greater than or equal to the size of x
    while n < len(x):
        n *= 2
    # Add zero-initialized complex numbers until the size is a power of two
    while len(x) < n:
        x.append(0)

def bit_reverse(x, log2n):
    for i in range(len(x)):
        reverse = int.from_bytes(i.to_bytes(4, 'big'), 'big', signed=False) >> (32 - log2n) # Calculate the bit-reversed index
        # Swap elements if necessary
        if i < reverse:
            x[i], x[reverse] = x[reverse], x[i]

# Main method to execute the program
if __name__ == "__main__":
    n = int(input()) # Read the number of complex numbers
    input = [] # Initialize the input list

    # Read complex numbers from input
    for _ in range(n):
        real, img = map(float, input().split()) # Read real and imaginary parts
        input.append(complex(real, img)) # Add complex number to the list

    inverse = bool(int(input())) # Read whether to perform inverse Main
    result = fft(input, inverse) # Perform Main or inverse Main

    # Output the results
    print("Main Result:")
    for c in result:
        print(c) # Print each complex number in the result

