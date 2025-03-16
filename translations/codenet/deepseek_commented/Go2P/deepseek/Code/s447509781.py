import sys

def main():
    input_reader = Input(sys.stdin)
    n = input_reader.next_int()  # Read the number of elements
    s = input_reader.next_int_array()  # Read the array of integers
    u = [False] * n  # Initialize a boolean array to track visited positions
    m, f = 0, 0
    # Iterate over possible values of c to find the maximum sum
    for c in range(1, n - 1):
        f = 0
        # Iterate over possible multiples of c
        k = 0
        while k * c < n - 1:
            u[k * c] = True  # Mark the position as visited
            if u[n - 1 - k * c]: break  # If the position is already visited, break the loop
            f += s[n - 1 - k * c] + s[k * c]  # Add the values at the current positions
            if m < f: m = f  # Update the maximum sum if the current sum is greater
            k += 1
        # Reset the boolean array for the next value of c
        for k in range(n - 1): u[k * c] = False
    print(m)  # Print the maximum sum found

class Input:
    def __init__(self, reader):
        self.reader = reader

    def next_line(self):
        buffer = []
        while True:
            line = self.reader.readline()
            if not line:
                break
            buffer.append(line)
        return ''.join(buffer)

    def next_int(self):
        return int(self.next_line())

    def next_int_array(self):
        s = self.next_line().split()
        return [int(x) for x in s]

