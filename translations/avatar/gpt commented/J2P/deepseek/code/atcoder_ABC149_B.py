import sys

class Main:
    def __init__(self, input_reader):
        # Read a line of input, split it into tokens, and parse them as long integers
        tokens = input_reader.readline().split()
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

    def show_result(self):
        # Print the values of x and y
        print(self.x, self.y)

# Read input from standard input
input_reader = sys.stdin

# Create an instance of Main class and pass the input reader
ins = Main(input_reader)

# Perform calculations based on the input values
ins.calc()

# Display the results of the calculations
ins.show_result()
