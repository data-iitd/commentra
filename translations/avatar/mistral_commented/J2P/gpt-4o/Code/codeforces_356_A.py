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
    in_reader = FastReader()

    n = in_reader.next_int()  # Reading the number of elements in the array

    left = SortedSet(range(n))  # Creating a SortedSet to store the indices of elements in the sorted order
    answer = [-1] * n  # Creating an array to store the answer for each index

    q = in_reader.next_int()  # Reading the number of queries

    # Processing each query
    for _ in range(q):
        l = in_reader.next_int() - 1  # Reading the left index of the query range
        r = in_reader.next_int() - 1  # Reading the right index of the query range
        win = in_reader.next_int()  # Reading the winning index

        # Updating the answer for the winning index and all the indices between the left and right indices
        while left and left[0] >= l and left[0] <= r:
            curr = left.pop(0)  # Get the smallest index in the range
            answer[curr] = win
        # Updating the answer for the winning index in the answer array
        answer[win - 1] = 0

        # Adding the winning index back to the SortedSet
        left.add(win - 1)

    # Printing the answer for each index in the answer array
    print(" ".join(map(str, answer)))  # Printing the answer as a single line

if __name__ == "__main__":
    main()

# <END-OF-CODE>
