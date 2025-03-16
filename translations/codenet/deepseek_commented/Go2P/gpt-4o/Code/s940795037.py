import sys

class Scanner:
    def __init__(self):
        self.buffer = []
        self.index = 0
        self.read_line()

    def read_line(self):
        self.buffer = sys.stdin.readline().strip().split()
        self.index = 0

    def next(self):
        if self.index >= len(self.buffer):
            self.read_line()
        result = self.buffer[self.index]
        self.index += 1
        return result

    def next_int(self):
        return int(self.next())

def main():
    sc = Scanner()  # Initialize a new Scanner instance

    n = sc.next_int()  # Read an integer n from the standard input
    ans = 0.0  # Initialize a variable ans to 0.0
    for _ in range(n):  # Enter a loop that runs n times
        tmp = 1 / float(sc.next_int())  # Read an integer, convert it to a float, and divide 1 by this value
        ans += tmp  # Add this result to ans
    print(1 / ans)  # Calculate the reciprocal of ans and print it

if __name__ == "__main__":
    main()

# <END-OF-CODE>
