import sys

# FastReader class to handle fast input
class FastReader:
    def __init__(self):
        self.buf = sys.stdin.buffer
        self.off = 0
        self.end = 0
        self.s = b""

    def read(self):
        while self.off == self.end:
            self.buf = sys.stdin.buffer
            self.off = 0
            self.end = len(self.buf)
        self.s = self.s[self.off:self.end]
        self.off = self.end
        return self.s

    def readline(self):
        while self.off == self.end:
            self.buf = sys.stdin.buffer
            self.off = 0
            self.end = len(self.buf)
        self.s = self.s[self.off:self.end]
        self.off = self.end
        return self.s

    def next(self):
        while self.off == self.end:
            self.buf = sys.stdin.buffer
            self.off = 0
            self.end = len(self.buf)
        self.s = self.s[self.off:self.end]
        self.off = self.end
        return self.s

    def __next__(self):
        return self.next()

    def readint(self):
        return int(self.next())

    def readints(self):
        return [int(x) for x in self.next().split()]

    def readlong(self):
        return int(self.next())

    def readlongs(self):
        return [int(x) for x in self.next().split()]

    def readfloat(self):
        return float(self.next())

    def readfloats(self):
        return [float(x) for x in self.next().split()]

    def readstr(self):
        return self.next()

    def readstrs(self):
        return self.next().split()


# Create an instance of FastReader for input
scan = FastReader()

# Function to solve the problem
def solve():
    # Read the number of elements in the array
    t = scan.readint()
    arr = [0] * t

    # Populate the array with input values
    for i in range(t):
        arr[i] = scan.readint()

    prevWinner = 0

    # Iterate through the array to determine the winner for each element
    for i in range(t):
        # Check if the current element is 1
        if arr[i] == 1:
            # If the previous winner is 0, set the previous winner to 2
            if prevWinner == 0:
                prevWinner = 2
        # Determine the winner based on the previous winner and the current element
        if prevWinner == 2 or prevWinner == 0:
            # If the previous winner is 2 or 0, check the parity of (arr[i] - 1)
            if (arr[i] - 1) % 2 == 0:
                print(2)  # Print winner 2
                prevWinner = 2  # Update previous winner
            else:
                print(1)  # Print winner 1
                prevWinner = 1  # Update previous winner
        else:
            # If the previous winner is 1, check the parity of (arr[i] - 1)
            if (arr[i] - 1) % 2 == 0:
                print(1)  # Print winner 1
                prevWinner = 1  # Update previous winner
            else:
                print(2)  # Print winner 2
                prevWinner = 2  # Update previous winner


# Main function
if __name__ == '__main__':
    solve()

# 