import sys

# FastScanner class for reading input efficiently
class FastScanner:
    def __init__(self):
        self.buffer = sys.stdin.read().splitlines()
        self.index = 0

    def next_int(self):
        return int(self.next())

    def next(self):
        if self.index >= len(self.buffer):
            return ""
        line = self.buffer[self.index]
        self.index += 1
        return line

# Main function is the entry point of our program
def main():
    # Initialize a new FastScanner object called fsc
    fsc = FastScanner()

    # Read the first three integers A, B, and C from the standard input
    A = fsc.next_int()
    B = fsc.next_int()
    C = fsc.next_int()

    # Check if the difference between B and A is equal to the difference between C and B
    if B - A == C - B:
        # If it is, print "YES"
        print("YES")
    else:
        # Otherwise, print "NO"
        print("NO")

# Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
