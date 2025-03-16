
import sys

def main():
    # Initialize a new scanner object
    sc = newScanner()

    # Read the first two integers from the standard input using the scanner
    x = sc.nextInt()
    y = sc.nextInt()

    # Initialize two variables xt and yt to store the indices of the arrays a where x and y are present
    xt, yt = 0, 0

    # Define a 3x3 2D array a
    a = [[1, 3, 5, 7, 8, 10, 12], [4, 6, 9, 11], [2]]

    # Iterate through each inner loop of the outer loop
    for i, t in enumerate(a):
        # Iterate through each element of the current inner loop
        for j, n in enumerate(t):
            # Check if the current element is equal to x, if yes, store its index in xt
            if x == n:
                xt = i
            # Check if the current element is equal to y, if yes, store its index in yt
            if y == n:
                yt = i

    # Check if the indices xt and yt are equal, if yes, print "Yes"
    if xt == yt:
        print("Yes")
    else:
        print("No")

# Helper function to find the maximum of two integers
def max(a, b):
    if a > b:
        return a
    return b

# Define a scanner structure
class scanner:
    def __init__(self):
        self.r = sys.stdin
        self.buf = ""
        self.p = 0

    # Function to read a single word from the input
    def next(self):
        self.pre()
        start = self.p
        while self.p < len(self.buf):
            if self.buf[self.p] =='':
                break
            self.p += 1
        result = self.buf[start:self.p]
        self.p += 1
        return result

    # Function to read a line from the input
    def nextLine(self):
        self.pre()
        start = self.p
        self.p = len(self.buf)
        return self.buf[start:]

    # Function to read an integer from the input
    def nextInt(self):
        return int(self.next())

    # Function to prepare the scanner for the next input
    def pre(self):
        if self.p >= len(self.buf):
            self.readLine()
            self.p = 0

    # Function to read a line from the input
    def readLine(self):
        self.buf = ""
        for line in self.r:
            self.buf += line

if __name__ == "__main__":
    main()

