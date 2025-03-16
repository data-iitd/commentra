# Define a constant for modulo operations
mod = 1000000007

def main():
    # Create a Scanner object to read input
    sc = Scanner(input)

    # Read the length of the string and the number of queries
    n = sc.nextInt()
    q = sc.nextInt()

    # Read the string as a character array
    c = list(sc.next())

    # Read the ranges for the queries and store them in a 2D array
    range_ = [list(sc.nextInt() for _ in range(2)) for _ in range(q)]

    # Initialize arrays to count "AC" fragments and store cumulative sums
    frag = [0] * (n + 1)
    rui = [0] * (n + 1)

    # Process the string to find "AC" fragments
    for i in range(2, n + 1):
        if c[i - 2] == 'A' and c[i - 1] == 'C':
            # Increment the count of "AC" fragments at position i
            frag[i] += 1
        # Update the cumulative sum array
        rui[i] = rui[i - 1] + frag[i]

    # Process the queries
    for i in range(q):
        left, right = range_[i]
        # Calculate the number of "AC" fragments in the given range
        print(rui[right] - rui[left])

# Assuming a Scanner class is defined as follows:
class Scanner:
    def __init__(self, input_source):
        self.tokens = input_source.split()

    def nextInt(self):
        return int(self.tokens.pop(0))

    def next(self):
        return self.tokens.pop(0)

# Call the main function
main()
