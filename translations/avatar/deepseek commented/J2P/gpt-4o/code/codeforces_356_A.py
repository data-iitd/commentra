import sys
from sortedcontainers import SortedSet

class FastReader:
    def __init__(self):
        self.input = sys.stdin.read
        self.data = self.input().split()
        self.index = 0

    def next(self):
        result = self.data[self.index]
        self.index += 1
        return result

    def next_int(self):
        return int(self.next())

def main():
    in_reader = FastReader()  # Initialize FastReader for fast input
    n = in_reader.next_int()  # Read the value of n
    left = SortedSet(range(n))  # Initialize a SortedSet to keep track of indices
    answer = [0] * n  # Initialize an array to store the results

    q = in_reader.next_int()  # Read the number of queries
    for _ in range(q):  # Process each query
        l = in_reader.next_int() - 1  # Read the left index and adjust for 0-based indexing
        r = in_reader.next_int() - 1  # Read the right index and adjust for 0-based indexing
        win = in_reader.next_int() - 1  # Read the winning index and adjust for 0-based indexing

        while left and left[0] >= l and left[0] <= r:  # While there are elements in the range
            curr = left.bisect_left(l)  # Get the smallest element in the range
            if curr < len(left) and left[curr] <= r:
                curr_index = left[curr]
                answer[curr_index] = win + 1  # Assign the winning index to the current element (adjusted for 1-based indexing)
                left.remove(curr_index)  # Remove the current element from the SortedSet

        answer[win] = 0  # Set the winning index to 0
        left.add(win)  # Add the winning index back to the SortedSet

    print(''.join(map(str, answer)))  # Print the final result

if __name__ == "__main__":
    main()

# <END-OF-CODE>
