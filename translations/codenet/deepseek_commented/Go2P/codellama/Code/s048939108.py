
# Main function starts here
def main():
    # Initialize a new scanner to read input
    sc = newScanner()
    # Read the next string from the scanner
    S = sc.next()
    # Check if the string S starts with the prefix "YAKI"
    if S.startswith("YAKI"):
        # If it does, print "Yes"
        print("Yes")
    else:
        # Otherwise, print "No"
        print("No")

# Helper function to find the minimum of two integers
def min(a, b):
    if a > b:
        return b
    return a

# Helper function to find the maximum of two integers
def max(a, b):
    if a > b:
        return a
    return b

# Custom scanner type to handle input reading
class scanner:
    # Function to create a new scanner instance
    def __init__(self):
        self.r = open(0)
        self.buf = ""
        self.p = 0

    # Method to read the next word from the input
    def next(self):
        self.pre()
        start = self.p
        for self.p in range(self.p, len(self.buf)):
            if self.buf[self.p] == ' ':
                break
        result = self.buf[start:self.p]
        self.p += 1
        return result

    # Method to read the next line from the input
    def nextLine(self):
        self.pre()
        start = self.p
        self.p = len(self.buf)
        return self.buf[start:]

    # Method to read the next integer from the input
    def nextInt(self):
        v = int(self.next())
        return v

    # Method to read the next array of integers from the input
    def nextIntArray(self):
        self.pre()
        start = self.p
        result = []
        for self.p in range(self.p, len(self.buf)+1):
            if self.p == len(self.buf) or self.buf[self.p] == ' ':
                v = int(self.buf[start:self.p])
                result.append(v)
                start = self.p + 1
        return result

    # Method to preprocess the buffer before reading
    def pre(self):
        if self.p >= len(self.buf):
            self.readLine()
            self.p = 0

    # Method to read a line from the input and update the buffer
    def readLine(self):
        self.buf = ""
        while True:
            l, p, e = self.r.readline()
            if e != None:
                raise e
            self.buf += l
            if not p:
                break

# 