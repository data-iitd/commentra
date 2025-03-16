import sys

class Main:
    def __init__(self):
        # Read input values A, B, and K from standard input
        tokens = sys.stdin.read().strip().split()
        self.A = int(tokens[0])
        self.B = int(tokens[1])
        self.K = int(tokens[2])
        self.x = 0
        self.y = 0

    def calc(self):
        # Initialize x with the value of A and y with the value of B
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
        else:
            self.y = self.B

    def show_result(self):
        # Print the values of x and y
        print(self.x, self.y)

if __name__ == "__main__":
    # Create an instance of Main class
    ins = Main()
    
    # Perform calculations based on the input values
    ins.calc()
    
    # Display the results of the calculations
    ins.show_result()

# <END-OF-CODE>
