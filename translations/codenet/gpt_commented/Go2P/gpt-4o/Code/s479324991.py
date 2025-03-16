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
            line = self.buffer[self.current_line].strip()
            if line:
                tokens = line.split()
                if self.current_token < len(tokens):
                    token = tokens[self.current_token]
                    self.current_token += 1
                    return token
                else:
                    self.current_line += 1
                    self.current_token = 0
        raise StopIteration

def main():
    sc = Scanner()

    # Read the number of elements
    n = sc.next_int()
    # Create a list to hold the float values
    arr = []

    # Read n integers from input and convert them to float
    for _ in range(n):
        arr.append(float(sc.next_int()))

    # Sort the array of float values
    arr.sort()

    # Initialize 'prev' with the first element of the sorted array
    prev = arr[0]

    # Calculate the average of the elements iteratively
    for i in range(1, len(arr)):
        prev = (prev + arr[i]) / 2

    # Print the final computed average
    print(prev)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
