import math

def main():
    # Declare variables for input dimensions and the answer
    N, M = map(int, input().split())
    ans = 0
    
    # Calculate the number of valid positions based on the dimensions
    if N == 1 and M == 1:
        # If both dimensions are 1, there's only one position
        ans += 1
    elif N > 1 and M > 1:
        # If both dimensions are greater than 1, calculate the inner positions
        ans += (N - 2) * (M - 2)
    else:
        # If one dimension is 1, count the edge positions
        ans += (N * M) - 2

    # Output the calculated answer
    print(ans)

# Utility functions
def max_value(*args):
    return max(args)

def min_value(*args):
    return min(args)

def pow_value(x, y):
    return int(math.pow(x, y))

def abs_value(x):
    return abs(x)

def floor_value(x):
    return math.floor(x)

# SortBy class to implement sorting based on absolute values
class SortBy:
    def __init__(self, data):
        self.data = data

    def __len__(self):
        return len(self.data)

    def swap(self, i, j):
        self.data[i], self.data[j] = self.data[j], self.data[i]

    def less(self, i, j):
        return abs_value(self.data[i]) < abs_value(self.data[j])

if __name__ == "__main__":
    main()

# <END-OF-CODE>
