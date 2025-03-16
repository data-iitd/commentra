import sys
from sortedcontainers import SortedSet

class FastReader:
    def __init__(self):
        self.input = sys.stdin.read
        self.data = self.input().split()
        self.index = 0

    def next(self):
        value = self.data[self.index]
        self.index += 1
        return value

    def next_int(self):
        return int(self.next())

def main():
    # Initialize FastReader to read input efficiently
    in_reader = FastReader()
    
    # Read the number of elements
    n = in_reader.next_int()
    
    # Create a SortedSet to keep track of available positions on the left
    left = SortedSet(range(n))
    
    # Initialize an array to store the answers
    answer = [0] * n
    
    # Read the number of queries
    q = in_reader.next_int()
    
    # Process each query
    for _ in range(q):
        # Read the range [l, r] and the winning index
        l = in_reader.next_int() - 1
        r = in_reader.next_int() - 1
        win = in_reader.next_int() - 1
        
        # Update the answer array for all positions in the range [l, r]
        while left and left[0] >= l and left[0] <= r:
            curr = left.bisect_left(l)  # Get the smallest index >= l
            if curr < len(left) and left[curr] <= r:
                pos = left[curr]  # Get the position
                answer[pos] = win + 1  # Set the answer for this position
                left.remove(pos)  # Remove this position from available positions
        
        # Mark the winning index as available again
        answer[win] = 0
        left.add(win)  # Add the winning index back to available positions
    
    # Build the output string from the answer array
    print(" ".join(map(str, answer)))

if __name__ == "__main__":
    main()

# <END-OF-CODE>
