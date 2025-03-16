import sys

class FastScanner:
    def __init__(self):
        self.input = sys.stdin.read
        self.data = self.input().split()
        self.index = 0

    def next(self):
        value = self.data[self.index]
        self.index += 1
        return value

    def next_int(self):
        return int(self.next())

def main():
    scanner = FastScanner()  # Creating an instance of FastScanner for fast input reading

    n = scanner.next_int()  # Reading the first integer n from the input
    s = scanner.next_int()  # Reading the second integer s from the input
    max_sum = 0  # Initializing max_sum to store the maximum sum of f and t

    for _ in range(n):  # Looping n times
        f = scanner.next_int()  # Reading the first value in the loop
        t = scanner.next_int()  # Reading the second value in the loop
        if max_sum < f + t:  # Checking if the sum of f and t is greater than the current max_sum
            max_sum = f + t  # Updating max_sum if the condition is true

    print(max(max_sum, s))  # Printing the maximum of max_sum and s

if __name__ == "__main__":
    main()  # Calling the main function

# <END-OF-CODE>
