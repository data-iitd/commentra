import sys

class Main:
    # Declare variables to hold the values of A, B, K, and the results x, y
    A = 0
    B = 0
    K = 0
    x = 0
    y = 0

    def __init__(self, in):
        # Read a line of input, split it into tokens, and parse them as long integers
        tokens = in.readline().split(" ")
        self.A = int(tokens[0])
        self.B = int(tokens[1])
        self.K = int(tokens[2])

    def calc(self):
        # Initialize x with the value of A and y with the value of B
        self.x = self.A
        self.y = self.B

        # Subtract K from A and assign the result to x
        self.x = self.A - self.K

        # Check if the result x is negative
        if self.x < 0:
            # If x is negative, adjust y by adding the negative value of x to B
            self.y = self.B + self.x
            # Set x to 0 since it cannot be negative
            self.x = 0

            # Ensure y is not negative
            if self.y < 0:
                self.y = 0

    def showResult(self):
        # Print the values of x and y
        print(self.x, self.y)

if __name__ == "__main__":
    # Set up input reading from standard input with UTF-8 encoding
    in = sys.stdin.buffer.readline

    # Create an instance of Main class and pass the BufferedReader for input
    ins = Main(in)

    # Perform calculations based on the input values
    ins.calc()

    # Display the results of the calculations
    ins.showResult()

