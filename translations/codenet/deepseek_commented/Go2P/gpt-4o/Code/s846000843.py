import sys

class Io:
    def __init__(self):
        self.reader = sys.stdin
        self.writer = sys.stdout

    def flush(self):
        self.writer.flush()

    def next_line(self):
        return self.reader.readline().strip()

    def next(self):
        return self.next_line()

    def int(self):
        return int(self.next())

    def print_ln(self, *args):
        print(*args, file=self.writer)

def cum_sum(nums):
    sums = [0]
    for num in nums:
        sums.append(sums[-1] + num)
    return sums

def abs_value(a):
    return a if a >= 0 else -a

def min_value(*nums):
    if len(nums) == 0:
        raise ValueError("Function min_value() requires at least one argument.")
    return min(nums)

def main():
    io = Io()

    n = io.int()  # Read the number of integers.

    aa = [io.int() for _ in range(n)]  # Read each integer and store it in the list.

    cumsum = cum_sum(aa)  # Compute the cumulative sum of the integers.

    ans = 2020202020
    for i in range(1, len(cumsum) - 1):
        ans = min_value(ans, abs_value(cumsum[-1] - cumsum[i] - (cumsum[i] - cumsum[0])))

    io.print_ln(ans)  # Print the minimum absolute difference.

if __name__ == "__main__":
    main()

# <END-OF-CODE>
