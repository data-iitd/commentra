
# <START-OF-CODE>

# Initialize FastReader to read input efficiently
class FastReader:
    def __init__(self):
        self.val = input()
        self.pos = 0

    def next(self):
        self.pos += 1
        return self.val[self.pos - 1]

    def nextInt(self):
        self.pos += 1
        return int(self.val[self.pos - 1])

    def nextLong(self):
        self.pos += 1
        return int(self.val[self.pos - 1])

    def nextDouble(self):
        self.pos += 1
        return float(self.val[self.pos - 1])

    def nextLine(self):
        self.val = input()
        self.pos = 0
        return self.val


# Main function
if __name__ == '__main__':
    # Initialize FastReader to read input efficiently
    in = FastReader()

    # Read the number of elements
    n = in.nextInt()

    # Create a TreeSet to keep track of available positions on the left
    left = set()

    # Initialize an array to store the answers
    answer = [0] * n

    # Populate the TreeSet with indices from 0 to n-1
    for i in range(n):
        left.add(i)

    # Read the number of queries
    q = in.nextInt()

    # Process each query
    while q > 0:
        # Read the range [l, r] and the winning index
        l = in.nextInt() - 1
        r = in.nextInt() - 1
        win = in.nextInt()

        # Update the answer array for all positions in the range [l, r]
        while left and left.pop() <= r:
            curr = left.pop()
            answer[curr] = win
            left.add(curr)

        # Mark the winning index as available again
        answer[win - 1] = 0
        left.add(win - 1)

    # Build the output string from the answer array
    ans = ""
    for i in range(n):
        ans += str(answer[i])

    # Print the final answer
    print(ans)

# 