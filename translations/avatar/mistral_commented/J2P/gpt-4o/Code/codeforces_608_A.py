import sys

class FastScanner:
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

def main():
    scanner = FastScanner()  # Creating an instance of FastScanner for reading input
    n = scanner.next_int()  # Reading the number of test cases

    max_sum = 0  # Initializing the maximum sum to zero

    for _ in range(n):  # Processing each test case
        f = scanner.next_int()  # Reading the first number
        t = scanner.next_int()  # Reading the second number

        if max_sum < f + t:  # Checking if the sum of the current numbers is greater than the current maximum sum
            max_sum = f + t  # Updating the maximum sum if it is

    print(max_sum)  # Writing the maximum sum to the output

if __name__ == "__main__":
    main()  # Calling the main function

# <END-OF-CODE>
