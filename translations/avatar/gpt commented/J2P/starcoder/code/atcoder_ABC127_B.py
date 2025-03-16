import sys

class Main:
    def __init__(self):
        self.scanner = sys.stdin
        self.writer = sys.stdout

    def run(self):
        # Read integer values for r and d, and a long value for x from the input
        r = int(self.scanner.readline())
        d = int(self.scanner.readline())
        x = int(self.scanner.readline())

        # Perform the calculation and output the result 10 times
        for i in range(10):
            # Update x according to the formula x = r * x - d
            x = r * x - d
            # Print the updated value of x
            self.writer.write(str(x) + '\n')

        # Close the PrintWriter to release resources
        self.writer.close()

# 