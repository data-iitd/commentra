import sys

class Main:
    def __init__(self):
        # Reading input from standard input
        tokens = sys.stdin.read().strip().split()  # Reading the input and splitting it into tokens
        self.A = int(tokens[0])  # Parsing the first token into an integer and assigning it to A
        self.B = int(tokens[1])  # Parsing the second token into an integer and assigning it to B
        self.K = int(tokens[2])  # Parsing the third token into an integer and assigning it to K
        self.x = 0  # Initializing x
        self.y = 0  # Initializing y

    def calc(self):
        self.x = self.A  # Assigning the value of A to x
        self.y = self.B  # Assigning the value of B to y

        self.x = self.A - self.K  # Subtracting K from A and assigning the result to x

        if self.x < 0:  # Checking if x is negative
            self.y = self.B + self.x  # If x is negative, adding the absolute value of x to B and assigning the result to y
            self.x = 0  # Setting x to zero

        if self.y < 0:  # Checking if y is negative
            self.y = 0  # If y is negative, setting it to zero

    def show_result(self):
        print(self.x, self.y)  # Printing the values of x and y separated by a space character

if __name__ == "__main__":
    ins = Main()  # Creating an instance of the Main class
    ins.calc()  # Calling the calc() method to perform the calculations
    ins.show_result()  # Calling the show_result() method to display the results

# <END-OF-CODE>
