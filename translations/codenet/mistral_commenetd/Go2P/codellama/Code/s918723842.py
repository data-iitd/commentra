
# Package main contains the entry point of the program.
import sys

# fmt package provides functions for formatting and printing data.
from fmt import Println

# bufio package provides methods for reading and writing text from I/O streams.
from bufio import Scanner

# os package provides access to the operating system.
from os import Stdin

# strconv package provides functions for converting between strings and other types.
from strconv import Atoi

# main function is the entry point of the program.
def main():
    # Initialize a new Scanner object named sc.
    sc = Scanner(Stdin)
    # Read the height H, width W, and number of obstacles N from the standard input.
    H, W, N = sc.NextInt(), sc.NextInt(), sc.NextInt()
    # Calculate the maximum dimension A between H and W.
    A = max(H, W)
    # Print the result, which is the number of rows or columns needed to place all obstacles without overlapping.
    Println((N + A - 1) / A)

# max function returns the maximum value between two integers a and b.
def max(a, b):
    # If a is smaller than b, return b.
    if a < b:
        return b
    # Otherwise, return a.
    return a

# Scanner struct represents the input reader.
class Scanner:
    # bufio.Reader field r is used for reading from the standard input.
    r = Stdin
    # buf byte slice buffer is used for storing the input line.
    buf = []
    # p integer p keeps track of the current position in the buffer.
    p = 0

    # NewScanner function initializes a new Scanner object with the standard input os.Stdin as the reader.
    def __init__(self):
        # Initialize a new bufio.Reader object named rdr with the standard input as the I/O source.
        self.r = Stdin

    # Next method reads the next token from the input, which can be a single word, number, or symbol.
    # It skips leading whitespaces and returns the result as a string.
    def Next(self):
        # Set the current position p to the beginning of the buffer if it's at the end.
        self.pre()
        # Start index of the token in the buffer.
        start = self.p
        # Read the input until a non-whitespace character is found.
        for ; self.p < len(self.buf); self.p++:
            # If the current character is a whitespace, break the loop.
            if self.buf[self.p] == ' ':
                break
        # Read the token, including the whitespace character if any.
        result = self.buf[start:self.p]
        # Increment the current position p.
        self.p++
        # Return the result.
        return result

    # NextLine method reads the next line from the input and returns it as a string.
    def NextLine(self):
        # Set the current position p to the beginning of the buffer if it's at the end.
        self.pre()
        # Start index of the line in the buffer.
        start = self.p
        # Read the input until the end of the line is reached.
        for ; self.p < len(self.buf); self.p++:
            # If the current character is a newline character, break the loop.
            if self.buf[self.p] == '\n':
                break
        # Read the line, including the newline character if any.
        result = self.buf[start:self.p]
        # Increment the current position p.
        self.p++
        # Return the result.
        return result

    # NextInt method reads an integer from the input and returns it.
    def NextInt(self):
        # Read the next token as a string.
        token = self.Next()
        # Parse the token as an integer and return the result.
        v = Atoi(token)
        # Return the result.
        return v

    # NextInt64 method reads a 64-bit integer from the input and returns it.
    def NextInt64(self):
        # Read the next token as a string.
        token = self.Next()
        # Parse the token as a 64-bit integer and return the result.
        v = Atoi(token)
        # Return the result.
        return v

    # NextFloat method reads a floating-point number from the input and returns it.
    def NextFloat(self):
        # Read the next token as a string.
        token = self.Next()
        # Parse the token as a floating-point number and return the result.
        v = Atoi(token)
        # Return the result.
        return v

    # NextIntArray method reads an array of integers from the input and returns it.
    def NextIntArray(self):
        # Read the next line as a string.
        line = self.NextLine()
        # Split the line into tokens using spaces as delimiters.
        tokens = line.split(" ")
        # Parse each token as an integer and append it to the result slice.
        result = []
        for token in tokens:
            v = Atoi(token)
            result.append(v)
        # Return the result.
        return result

    # NextInt64Array method reads an array of 64-bit integers from the input and returns it.
    def NextInt64Array(self):
        # Read the next line as a string.
        line = self.NextLine()
        # Split the line into tokens using spaces as delimiters.
        tokens = line.split(" ")
        # Parse each token as a 64-bit integer and append it to the result slice.
        result = []
        for token in tokens:
            v = Atoi(token)
            result.append(v)
        # Return the result.
        return result

    # NextMap method reads a map from the input and returns it.
    def NextMap(self):
        # Read the next line as a string.
        line = self.NextLine()
        # Split the line into tokens using spaces as delimiters.
        tokens = line.split(" ")
        # Parse each token as an integer and create a key-value pair.
        mp = {}
        for token in tokens:
            key = Atoi(token.split(":")[0])
            mp[key] = True
        # Return the result.
        return mp

    # pre method sets the current position p to the beginning of the buffer if it's at the end.
    def pre(self):
        # If the current position p is at the end of the buffer, read the next line.
        if self.p >= len(self.buf):
            self.readLine()
            self.p = 0

    # readLine method reads a line from the input and appends it to the buffer.
    def readLine(self):
        # Read a line from the input using the bufio.Reader.
        line = self.r.readline()
        # Remove the newline character from the line.
        line = line.strip()
        # Append the line to the buffer.
        self.buf.append(line)

# 