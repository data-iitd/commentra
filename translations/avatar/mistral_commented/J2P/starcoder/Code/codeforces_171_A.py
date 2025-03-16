# Importing necessary classes
import sys
import io

# Defining a static inner class FastReader for reading input
class Main:
    class FastReader:
        def __init__(self):
            self.s = io.StringIO(sys.stdin.read())
            self.eol = '\n'
            self.whitespace =''

        def readline(self):
            return self.s.readline().rstrip()

        def read(self):
            return self.s.read()

        def readInt(self):
            return int(self.readline())

        def readLong(self):
            return int(self.readline())

        def readFloat(self):
            return float(self.readline())

        def readDouble(self):
            return float(self.readline())

        def readString(self):
            return str(self.readline())

        def readStrings(self):
            return self.readline().split()

        def readInts(self):
            return list(map(int, self.readline().split()))

        def readLongs(self):
            return list(map(int, self.readline().split()))

        def readFloats(self):
            return list(map(float, self.readline().split()))

        def readDoubles(self):
            return list(map(float, self.readline().split()))

        def readChars(self):
            return list(self.readline())

        def readChar(self):
            return self.readChars()[0]

        def readBool(self):
            return self.readline() == 'true'

    # Main method
    def main(self):
        # Creating an instance of FastReader
        f = self.FastReader()

        # Reading input for number of test cases
        n = f.readInt()

        # Reading input for number of operations
        m = f.readInt()

        # Calling reverse function for m and adding it to n
        t = self.reverse(m)
        print(t + n)

    # Function for reversing a number
    def reverse(self, n):
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

# 