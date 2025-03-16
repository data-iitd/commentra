
import sys

def main():
    input = Input(sys.stdin)
    n = input.next_int() # Read the number of elements
    s = input.next_int_array() # Read the array of integers
    u = [False] * n # Initialize a boolean array to track visited positions
    m, f = 0, 0
    # Iterate over possible values of c to find the maximum sum
    for c in range(1, n - 1):
        f = 0
        # Iterate over possible multiples of c
        for k in range(0, n - 1 - k * c):
            u[k * c] = True # Mark the position as visited
            if u[n - 1 - k * c]: break # If the position is already visited, break the loop
            f += s[n - 1 - k * c] + s[k * c] # Add the values at the current positions
            if m < f: m = f # Update the maximum sum if the current sum is greater
        # Reset the boolean array for the next value of c
        for k in range(0, n - 1 - k * c): u[k * c] = False
    print(m) # Print the maximum sum found

class Input:
    def __init__(self, file):
        self.reader = file

    def next_line(self):
        buffer = []
        for line in self.reader:
            buffer.append(line)
            if line == '\n': break
        return ''.join(buffer)

    def next_int(self):
        return int(self.next_line())

    def next_int_array(self):
        s = self.next_line().split()
        a = [0] * len(s)
        for i in range(len(s)): a[i] = int(s[i])
        return a

