import sys
import io
import os
import math

class InputReader:
    def __init__(self, input_stream):
        self.input_stream = input_stream

    def next_line(self):
        try:
            return self.input_stream.readline().decode().strip()
        except:
            return None

    def next_int(self):
        return int(self.next_line())

    def read_array(self, n):
        return list(map(int, self.next_line().split()))

class Solution:
    def solve(self, inp, out):
        n = inp.next_int()
        k = inp.next_int()

        min_day = 1
        max_day = int(1e9) + 1000

        while min_day < max_day:
            mid_day = (min_day + max_day) // 2
            if self.nei(mid_day, n, k):
                max_day = mid_day
            else:
                min_day = mid_day + 1

        out.write(f"{min_day}\n")

    def nei(self, mid, logs_length, k):
        days_needed = 0

        for log in logs_length:
            days_needed += (log + mid - 1) // mid
            k -= days_needed
            if k < 0:
                return False

        return True

# Read from standard input
input_stream = io.TextIOWrapper(sys.stdin.buffer, encoding='utf-8')

# Create an InputReader object
inp = InputReader(input_stream)

# Create a StringIO object for output
output_stream = io.StringIO()

# Create a Solution object
sol = Solution()

# Call the solve method of Solution object
sol.solve(inp, output_stream)

# Get the output from the StringIO object
output = output_stream.getvalue()

# Print the output
print(output, end='<END-OF-CODE>')