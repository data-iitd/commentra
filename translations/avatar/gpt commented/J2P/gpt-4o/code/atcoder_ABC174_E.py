import sys
import math

class InputReader:
    def __init__(self, stream):
        self.stream = stream
        self.current_line = []
    
    def next(self):
        if not self.current_line:
            self.current_line = self.stream.readline().strip().split()
        return self.current_line.pop(0)
    
    def next_int(self):
        return int(self.next())
    
    def read_array(self, n):
        return [self.next_int() for _ in range(n)]

class Solution:
    def solve(self, in_reader, out_writer):
        # Read the number of logs and the value of k
        n = in_reader.next_int()
        k = in_reader.next_int()
        
        # Read the lengths of the logs into a list
        logs_length = in_reader.read_array(n)
        
        # Initialize binary search bounds
        min_length = 1
        max_length = int(1e9) + 1000
        
        # Perform binary search to find the minimum possible length
        while min_length < max_length:
            mid_length = (min_length + max_length) // 2
            
            # Check if it's possible to cut the logs with the current mid length
            if self.can_cut(mid_length, logs_length, k):
                max_length = mid_length  # If possible, search in the lower half
            else:
                min_length = mid_length + 1  # Otherwise, search in the upper half
        
        # Output the minimum length found
        out_writer.write(f"{min_length}\n")
    
    def can_cut(self, mid, logs_length, k):
        for log in logs_length:
            k -= (log + mid - 1) // mid - 1  # Calculate the number of cuts needed
        
        # Return true if we can make the cuts within the limit of k
        return k >= 0

def main():
    # Set up input and output streams
    input_reader = InputReader(sys.stdin)
    output_writer = sys.stdout
    
    # Create an instance of Solution to solve the problem
    sol = Solution()
    sol.solve(input_reader, output_writer)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
