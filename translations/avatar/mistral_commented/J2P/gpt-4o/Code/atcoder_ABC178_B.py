import sys  # Importing necessary modules

class FastReader:  # Defining a FastReader class for reading input
    def __init__(self):  # Constructor for initializing the FastReader object
        self.input = sys.stdin.read  # Using sys.stdin.read for fast input
        self.data = self.input().split()  # Reading all input at once and splitting into tokens
        self.index = 0  # Initializing an index for tracking the current position in the input

    def next(self):  # Method for reading the next token from the input
        token = self.data[self.index]  # Getting the current token
        self.index += 1  # Moving to the next token
        return token  # Returning the current token

    def next_int(self):  # Method for reading the next integer from the input
        return int(self.next())  # Converting the next token to an integer and returning it

    def next_long(self):  # Method for reading the next long integer from the input
        return int(self.next())  # In Python, int can handle long integers

    def next_double(self):  # Method for reading the next double from the input
        return float(self.next())  # Converting the next token to a float and returning it

    def next_line(self):  # Method for reading the next line from the input
        line = self.data[self.index]  # Getting the current line
        self.index += 1  # Moving to the next line
        return line  # Returning the current line


def mod_power(x, y, mod):  # Method for calculating x raised to the power of y modulo mod
    res = 1  # Initializing the result variable to 1
    x %= mod  # Calculating the remainder of x when divided by mod

    if x == 0:  # If x is 0, the result is 0
        return 0

    while y > 0:  # While y is greater than 0
        if y % 2 == 1:  # If y is odd
            res = (res * x) % mod  # Multiplying the result with x and taking the modulo with mod
        y //= 2  # Dividing y by 2
        x = (x * x) % mod  # Squaring x and taking the modulo with mod
    return res  # Returning the final result


class Pair:  # Defining a generic pair class for storing two elements of different types
    def __init__(self, first, second):  # Constructor for initializing the pair object
        self.first = first  # Initializing the first variable with the first argument
        self.second = second  # Initializing the second variable with the second argument


def main():  # Main function for executing the program
    in_reader = FastReader()  # Creating a FastReader object for reading input

    a = [in_reader.next_long() for _ in range(4)]  # Reading four long integers into a list

    # Calculating the maximum product of pairs of elements in the list a
    result = max(a[0] * a[2], max(a[1] * a[3], max(a[0] * a[3], a[1] * a[2])))

    print(result)  # Printing the result to the standard output


if __name__ == "__main__":  # Checking if the script is being run directly
    main()  # Calling the main function

# <END-OF-CODE>
