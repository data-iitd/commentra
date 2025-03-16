
import sys

# FastScanner class for reading input efficiently
class FastScanner:
    def __init__(self):
        self.br = sys.stdin

    def next(self):
        while True:
            try:
                return self.br.readline().strip()
            except:
                pass

    def nextInt(self):
        return int(self.next())

    def nextLong(self):
        return long(self.next())

    def nextDouble(self):
        return float(self.next())

# Main method is the entry point of the Python application
def main():
    input = FastScanner()
    n = input.nextInt()

    # Initialize an empty dictionary with integer keys and integer values
    map = {}

    # Iterate through the given number of integers and add each integer to the dictionary with its count
    for i in range(n):
        val = input.nextInt()
        map[val] = map.get(val, 0) + 1

    # Initialize minimum value and maximum value variables
    max = -sys.maxsize
    for key in map:
        # Update the maximum value if the current entry's value is greater than the maximum value
        max = max(max, map[key])

    # Print the maximum value and the size of the dictionary
    print(max, len(map))

if __name__ == "__main__":
    main()

