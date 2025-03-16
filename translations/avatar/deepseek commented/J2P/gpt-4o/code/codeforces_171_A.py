import sys

class FastReader:
    def __init__(self):
        self.input = sys.stdin.read
        self.data = self.input().split()
        self.index = 0

    def next(self):
        if self.index < len(self.data):
            result = self.data[self.index]
            self.index += 1
            return result
        return None

    def next_int(self):
        return int(self.next())

    def next_long(self):
        return int(self.next())  # In Python, int can handle long values

    def next_double(self):
        return float(self.next())

    def next_line(self):
        return ' '.join(self.data[self.index:])

def reverse(n):
    if n < 10:
        return n * 10  # If the number is a single digit, return it multiplied by 10
    r = 0
    while n > 0:
        r = (r * 10) + (n % 10)  # Reverse the number
        n //= 10
    return r

if __name__ == "__main__":
    sc = FastReader()
    n = sc.next_int()  # Read the first integer
    m = sc.next_int()  # Read the second integer
    t = reverse(m)  # Reverse the second integer
    print(t + n)  # Print the sum of the reversed integer and the first integer

# <END-OF-CODE>
