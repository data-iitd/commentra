import sys
import math

# scanner is a wrapper around sys.stdin for convenient scanning of input.
class Scanner:
    def __init__(self, input_stream):
        self.input_stream = input_stream
        self.buf = []
        self.index = 0

    def next_word(self):
        while self.index >= len(self.buf):
            self.buf = self.input_stream.readline().split()
            self.index = 0
        result = self.buf[self.index]
        self.index += 1
        return result

    def int(self):
        return int(self.next_word())

    def int_slice(self, l):
        if l == 0:
            return []
        return [self.int() for _ in range(l)]

def iabs(x):
    return abs(x)

def solve(n, heights):
    # Initialize the minimum cost array with a large value.
    t = [math.inf] * (n + 1)

    # The cost to reach the first stone is 0.
    t[0] = 0

    # Calculate the minimum cost to reach each stone.
    for i in range(1, n):
        # Cost to reach the current stone from the previous stone.
        if v := t[i - 1] + iabs(heights[i] - heights[i - 1]):
            t[i] = min(t[i], v)
        # Cost to reach the current stone from two stones back (if possible).
        if i > 1:
            if v := t[i - 2] + iabs(heights[i] - heights[i - 2]):
                t[i] = min(t[i], v)

    # Return the minimum cost to reach the last stone.
    return t[n - 1]

# main function reads input, calls the solve function, and prints the result.
def main():
    sc = Scanner(sys.stdin)
    n = sc.int()
    heights = sc.int_slice(n)
    ans = solve(n, heights)
    print(ans)

main()
