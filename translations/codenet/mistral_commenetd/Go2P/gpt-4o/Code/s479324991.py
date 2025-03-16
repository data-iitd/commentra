import sys

class Scanner:
    def __init__(self):
        self.buffer = sys.stdin.read().splitlines()
        self.current_line = 0
        self.current_token = 0

    def next_int(self):
        return int(self.next())

    def next(self):
        while self.current_line < len(self.buffer):
            line = self.buffer[self.current_line]
            tokens = line.split()
            if self.current_token < len(tokens):
                token = tokens[self.current_token]
                self.current_token += 1
                return token
            else:
                self.current_line += 1
                self.current_token = 0
        return None

def main():
    sc = Scanner()

    # Read the number of elements in the array from the standard input
    n = sc.next_int()

    # Allocate memory for the array of size n
    arr = []

    # Read n integers from the standard input and store them in the array
    for _ in range(n):
        arr.append(float(sc.next_int()))

    # Sort the array in ascending order
    arr.sort()

    # Initialize a variable prev to store the previous element in the sorted array
    prev = arr[0]

    # Iterate through the sorted array from the second element to the last
    for i in range(1, len(arr)):
        # Calculate the average of the previous and current elements
        prev = (prev + arr[i]) / 2

    # Print the result to the standard output
    print(prev)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
