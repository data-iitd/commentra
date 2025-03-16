import math

# This is the main function where the program starts execution.
# It reads two integers N and M from the standard input.
# Depending on the values of N and M, it calculates the number of cells in the grid.
# Finally, it prints the result to the standard output.
def main():
    N, M = map(int, input().split())
    ans = 0
    # If both N and M are 1, there is only one cell, so the answer is 1.
    if N == 1 and M == 1:
        ans += 1
    elif N > 1 and M > 1:
        # If both N and M are greater than 1, the number of cells is (N-2)*(M-2).
        ans += (N - 2) * (M - 2)
    else:
        # If either N or M is 1, the number of cells is (N*M) - 2.
        ans += (N * M) - 2

    print(ans)

# This function returns the maximum value among the given integers.
def max_value(*args):
    return max(args)

# This function returns the minimum value among the given integers.
def min_value(*args):
    return min(args)

# This function returns x raised to the power of y.
def pow_value(x, y):
    return int(math.pow(x, y))

# This function returns the absolute value of x.
def abs_value(x):
    return abs(x)

# This function returns the floor value of x.
def floor_value(x):
    return math.floor(x)

# This class is a list of integers that can be sorted by their absolute values.
class SortBy:
    def __init__(self, data):
        self.data = data

    def __len__(self):
        return len(self.data)

    def swap(self, i, j):
        self.data[i], self.data[j] = self.data[j], self.data[i]

    def less(self, i, j):
        return abs_value(self.data[i]) < abs_value(self.data[j])

# Call the main function to execute the program
if __name__ == "__main__":
    main()

# <END-OF-CODE>
