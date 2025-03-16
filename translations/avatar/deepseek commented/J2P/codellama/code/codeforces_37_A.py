
import sys

# Create an instance of FastScanner to read input efficiently
input = FastScanner()

# Read the number of integers
n = input.nextInt()

# Create a HashMap to store the frequency of each integer
map = {}

# Read n integers and update their counts in the hash map
for i in range(n):
    val = input.nextInt()
    if val in map:
        map[val] += 1
    else:
        map[val] = 1

# Initialize max to the smallest possible integer value
max = -sys.maxsize - 1

# Iterate through the hash map to find the maximum count
for key, value in map.items():
    max = max(max, value)

# Print the maximum count and the size of the hash map
print(max, len(map))

# Utility class to read input efficiently
class FastScanner:
    def __init__(self):
        self.br = sys.stdin
        self.st = ''

    # Method to read the next token
    def next(self):
        while not self.st:
            self.st = self.br.readline().strip()
        return self.st.pop(0)

    # Method to read the next integer
    def nextInt(self):
        return int(self.next())

    # Method to read the next long
    def nextLong(self):
        return long(self.next())

    # Method to read the next double
    def nextDouble(self):
        return float(self.next())

    # Method to read the next line
    def nextLine(self):
        return self.br.readline().strip()

# END-OF-CODE
