import sys

# Reads a single integer from standard input.
def next_int():
    return int(sys.stdin.readline().strip())

# Reads a list of integers from standard input.
def scan_nums(length):
    return list(map(int, sys.stdin.readline().strip().split()))[:length]

# Computes a value using the first two and last two elements of the input list.
def pattern1(l):
    return (l[0] * l[3]) + (l[1] * l[4])

# Computes another value using the third element and the maximum of the last two elements.
def pattern2(l):
    return 2 * l[2] * max(l[3], l[4])

# Computes yet another value using the third element, the minimum of the last two elements, and the result of doch(l).
def pattern3(l):
    return 2 * l[2] * min(l[3], l[4]) + doch(l)

# Returns the minimum value among the given integers.
def min_value(*nums):
    if len(nums) == 0:
        raise ValueError("function min_value() requires at least one argument.")
    return min(nums)

# Returns the maximum value among the given integers.
def max_value(*nums):
    if len(nums) == 0:
        raise ValueError("function max_value() requires at least one argument.")
    return max(nums)

# Calculates a specific value based on the input list.
def doch(l):
    if l[3] > l[4]:
        return l[0] * (l[3] - l[4])
    else:
        return l[1] * (l[4] - l[3])

# Main function to read input, compute the minimum value, and print it.
if __name__ == "__main__":
    length = 5
    l = scan_nums(length)
    print(min_value(pattern1(l), pattern2(l), pattern3(l)))

# <END-OF-CODE>
