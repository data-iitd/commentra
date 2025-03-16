
import sys

class Main:
    def __init__(self):
        self.sc = FastReader()
        self.pw = sys.stdout

    def solve(self):
        # Read an integer input
        x = self.sc.nextInt()
        # Initialize a counter to keep track of the number of iterations
        count = 0
        # Store the initial value of x in a temporary variable
        tmp = x
        # Initialize x to 0 to start the loop
        x = 0
        # Loop until x becomes 360
        while x!= 360:
            # Increment x by tmp
            x = x + tmp
            # If x exceeds 360, adjust it by subtracting 360
            if x > 360:
                x = x - 360
            # Increment the counter
            count += 1
        # Print the final count
        print(count)

    def main(self):
        self.solve()

class FastReader:
    def __init__(self):
        self.r = sys.stdin

    def next(self):
        return self.r.readline().strip()

    def nextInt(self):
        return int(self.next())

    def nextLong(self):
        return int(self.next())

    def nextDouble(self):
        return float(self.next())

    def nextLine(self):
        return str(self.r.readline().strip())

if __name__ == '__main__':
    obj = Main()
    obj.main()

