import sys
import io
import os

# Importing necessary classes
import sys
import io
import os

# Defining a static inner class FastReader for reading input
class FastReader(io.TextIOWrapper):
    def __init__(self, input_stream):
        super(FastReader, self).__init__(input_stream)
        self.buffer = io.BufferedReader(input_stream)
        self.tokens = []

    # Method for reading next token
    def next(self):
        while not self.tokens:
            data = self.buffer.readline()
            if not data:
                return None
            self.tokens = data.split()
        return self.tokens.pop(0)

    # Methods for reading specific types of input
    def nextInt(self):
        return int(self.next())

    def nextLong(self):
        return int(self.next())

    def nextDouble(self):
        return float(self.next())

    def nextLine(self):
        return self.buffer.readline()

# Main method
def main():
    # Creating an instance of FastReader
    input_stream = io.TextIOWrapper(sys.stdin.buffer, encoding='utf-8')
    sc = FastReader(input_stream)

    # Reading input for number of test cases
    n = sc.nextInt()

    # Reading input for number of operations
    m = sc.nextInt()

    # Calling reverse function for m and adding it to n
    t = reverse(m)
    print(t + n)

# Function for reversing a number
def reverse(n):
    # Base case for numbers less than 10
    if n < 10:
        return n * 10

    # Initializing variables
    t = n
    r = 0

    # Reversing the number
    while t > 0:
        # Adding the digit to the reversed number
        r = (r * 10) + t % 10

        # Moving to the next digit
        t = t // 10

    # Returning the reversed number
    return r

# Calling the main method
if __name__ == "__main__":
    main()
