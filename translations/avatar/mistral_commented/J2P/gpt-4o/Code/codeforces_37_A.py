import sys
from collections import defaultdict

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
    input = FastScanner()  # Create an instance of FastScanner class for reading input
    n = input.next_int()  # Read the number of integers from the standard input

    # Initialize a defaultdict to count occurrences of each integer
    count_map = defaultdict(int)

    # Iterate through the given number of integers and add each integer to the count_map
    for _ in range(n):
        val = input.next_int()  # Read the next integer from the standard input
        count_map[val] += 1  # Increment the count for the integer

    # Find the maximum count and the size of the count_map
    max_count = max(count_map.values())  # Get the maximum count of occurrences
    unique_count = len(count_map)  # Get the number of unique integers

    # Print the maximum count and the size of the count_map
    print(max_count, unique_count)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
