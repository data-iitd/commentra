# Importing necessary modules
import sys

# Defining a function for reading input
class FastReader:
    def __init__(self):
        self.input = sys.stdin.read
        self.data = self.input().split()
        self.index = 0

    def next(self):
        if self.index < len(self.data):
            token = self.data[self.index]
            self.index += 1
            return token
        return None

    def next_int(self):
        return int(self.next())

    def next_long(self):
        return int(self.next())  # Python's int can handle long values

    def next_double(self):
        return float(self.next())

    def next_line(self):
        return self.input().strip()

# Function for reversing a number
def reverse(n):
    # Base case for numbers less than 10
    if n < 10:
        return n * 10

    # Initializing variables
    t = n
    r = 0

    # Reversing the number
    while t > 0:
        # Adding the digit to the reversed number
        r = (r * 10) + t % 10
        # Moving to the next digit
        t = t // 10

    # Returning the reversed number
    return r

# Main function
def main():
    # Creating an instance of FastReader
    sc = FastReader()

    # Reading input for number of test cases
    n = sc.next_int()

    # Reading input for number of operations
    m = sc.next_int()

    # Calling reverse function for m and adding it to n
    t = reverse(m)
    print(t + n)

# Entry point of the program
if __name__ == "__main__":
    main()

# <END-OF-CODE>
