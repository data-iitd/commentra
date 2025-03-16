import sys

# Initialize a new scanner
def main():
    sc = newScanner()

    # Read the first string from the standard input
    S = sc.next()

    # Check if the string starts with "YAKI"
    if S.startswith("YAKI"):
        print("Yes") # Print "Yes" if the condition is true
    else:
        print("No") # Print "No" if the condition is false

# Minimum function
def min(a, b):
    # Determine the minimum of two integers
    return b if a > b else a

# Maximum function
def max(a, b):
    # Determine the maximum of two integers
    return a if a > b else b

# Scanner structure definition
class scanner:
    def __init__(self, rdr):
        self.rdr = rdr
        self.buf = []
        self.p = 0

    # Next function to read the next token as a string
    def next(self):
        self.pre()
        start = self.p
        for i in range(start, len(self.buf)):
            if self.buf[i] == ' ':
                break
        result = ''.join(self.buf[start:i])
        self.p = i + 1
        return result

    # NextLine function to read the next line as a string
    def nextLine(self):
        self.pre()
        start = self.p
        self.p = len(self.buf)
        return ''.join(self.buf[start:])

    # NextInt function to read the next integer from the standard input
    def nextInt(self):
        return int(self.next())

    # NextIntArray function to read an array of integers from the standard input
    def nextIntArray(self):
        self.pre()
        start = self.p
        result = []
        for i in range(start, len(self.buf) + 1):
            if i == len(self.buf) or self.buf[i] == ' ':
                v = int(''.join(self.buf[start:i]))
                result.append(v)
                start = i + 1
        return result

    # Pre function to prepare the scanner for reading the next token
    def pre(self):
        if self.p >= len(self.buf):
            self.buf = list(self.rdr.readline().strip())

# Initialize a new scanner instance
def newScanner():
    rdr = sys.stdin
    return scanner(rdr)

# Call the main function
if __name__ == "__main__":
    main()
