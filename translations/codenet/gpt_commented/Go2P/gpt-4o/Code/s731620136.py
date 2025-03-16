import sys

class Scanner:
    def __init__(self):
        self.input = sys.stdin.read
        self.data = self.input().split()
        self.index = 0

    def next_str(self):
        result = self.data[self.index]
        self.index += 1
        return result

    def next_int(self):
        return int(self.next_str())

    def next_float(self):
        return float(self.next_str())

    def next_int_slice(self, n):
        return [self.next_int() for _ in range(n)]

    def next_float_slice(self, n):
        return [self.next_float() for _ in range(n)]

def run():
    sc = Scanner()
    N = sc.next_int()  # Read the number of elements
    S = sc.next_str()  # Read the string of colors

    # Handle case where there are no elements
    if N == 0:
        return 0

    # If there are fewer than 4 elements, output 0
    if N < 4:
        print(0)
        return 0

    # Count occurrences of each color
    nr = nb = ng = 0
    for c in S:
        if c == 'R':
            nr += 1
        elif c == 'B':
            nb += 1
        elif c == 'G':
            ng += 1

    same = 0  # Counter for same color combinations

    # Iterate through possible combinations of indices
    for a in range(1, N):
        i = 0
        j = 1 * a
        k = 2 * a
        if k >= N:
            break  # Exit if index exceeds string length
        while k < N:
            # Check if the colors at the indices are different
            if S[i] != S[j] and S[i] != S[k] and S[j] != S[k]:
                same += 1  # Increment same color combination counter
            i += 1  # Move to the next index
            j += 1
            k += 1

    # Calculate total combinations of different colors
    tot = nr * nb * ng

    # Output the result by subtracting same combinations from total
    print(tot - same)

    return 0  # Return success

if __name__ == "__main__":
    run()  # Run the program

# <END-OF-CODE>
