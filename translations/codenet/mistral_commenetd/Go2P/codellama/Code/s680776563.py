
# main function is the entry point of our program
def main():
    # Initialize a new FastScanner object called fsc
    fsc = FastScanner()

    # Read the first three integers A, B, and C from the standard input
    A, B, C = fsc.next_int(), fsc.next_int(), fsc.next_int()

    # Check if the difference between B and A is equal to the difference between C and B
    if B-A == C-B:
        # If it is, print "YES"
        print("YES")
    else:
        # Otherwise, print "NO"
        print("NO")

# FastScanner class and methods for reading input efficiently
class FastScanner:
    # Initialize a new FastScanner object with a buffer size of 1024 bytes
    def __init__(self):
        self.r = open(0, 'rb')
        self.buf = bytearray(1024)
        self.p = 0

    # Read the next token from the input buffer
    def next(self):
        # Preprocess the input buffer if necessary
        self.pre()

        # Find the start index of the next token
        start = self.p
        # Find the end index of the next token (space or newline character)
        for self.p < len(self.buf):
            if self.buf[self.p] == ' ':
                break
            self.p += 1

        # Return the substring of the input buffer from the start index to the current position
        result = str(self.buf[start:self.p], 'ascii')
        # Move the position index to the next character
        self.p += 1

        # Return the result
        return result

    # Read the next line from the input buffer
    def next_line(self):
        # Preprocess the input buffer if necessary
        self.pre()

        # Find the start index of the next line
        start = self.p
        # Read the rest of the line into the buffer
        self.p = len(self.buf)

        # Return the substring of the input buffer from the start index to the end of the line
        return str(self.buf[start:], 'ascii')

    # Read the next integer from the input buffer
    def next_int(self):
        # Read a string token as an integer
        token = self.next()
        # Convert the string token to an integer and return it
        return int(token)

    # Preprocess the input buffer if necessary
    def pre(self):
        # If the position index is at the end of the buffer, read a new line
        if self.p >= len(self.buf):
            self.read_line()
            self.p = 0

    # Read a line from the input buffer into the buffer
    def read_line(self):
        # Read a line from the input buffer into a temporary byte slice
        line = self.r.readline()
        # Copy the temporary byte slice to the FastScanner's buffer
        self.buf += line

    # Helper functions for finding the maximum and minimum values
    def int_max(a, b):
        # Return the larger of the two integers
        if a < b:
            return b
        return a

    def int64_max(a, b):
        # Return the larger of the two integers
        if a < b:
            return b
        return a

    def float64_max(a, b):
        # Return the larger of the two floating-point numbers
        if a < b:
            return b
        return a

    def int_min(a, b):
        # Return the smaller of the two integers
        if a > b:
            return b
        return a

    def int64_min(a, b):
        # Return the smaller of the two integers
        if a > b:
            return b
        return a

    def float64_min(a, b):
        # Return the smaller of the two floating-point numbers
        if a > b:
            return b
        return a

    # Helper function for finding the greatest common divisor of two integers
    def int_gcd(a, b):
        # If b is 0, return a as the GCD
        if b == 0:
            return a

        # Recursively call int_gcd with b and the remainder of a divided by b
        return int_gcd(b, a%b)

    def int64_gcd(a, b):
        # If b is 0, return a as the GCD
        if b == 0:
            return a

        # Recursively call int64_gcd with b and the remainder of a divided by b
        return int64_gcd(b, a%b)

    # Helper function for finding the absolute value of an integer
    def int_abs(a):
        # If a is negative, return the negative of a
        if a < 0:
            return -a
        # Otherwise, return a as is
        return a

    def int64_abs(a):
        # If a is negative, return the negative of a
        if a < 0:
            return -a
        # Otherwise, return a as is
        return a



