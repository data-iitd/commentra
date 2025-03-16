
#!/usr/bin/env python3

import sys
import math

def main():
    # Initialize input/output handling
    io = Io()
    io.read_input()

    # Read the number of elements
    n = io.next_int()

    # Create a slice to hold the input integers
    aa = [0] * n

    # Read each integer and store it in the slice
    for i in range(n):
        aa[i] = io.next_int()

    # Compute the cumulative sum of the input integers
    cumsum = CumSum(aa)

    # Initialize the answer with a large value
    ans = 2020202020

    # Iterate through the cumulative sums to find the minimum difference
    for i in range(1, len(cumsum)-1):
        ans = min(ans, abs(cumsum[len(cumsum)-1]-cumsum[i]-(cumsum[i]-cumsum[0])))

    # Output the final answer
    io.print_ln(ans)

# Io struct for handling input and output
class Io:
    def __init__(self):
        self.reader = sys.stdin
        self.writer = sys.stdout
        self.tokens = []
        self.next_token = 0

    def read_input(self):
        while True:
            line = self.reader.readline()
            if not line:
                break
            self.tokens = line.split()
            self.next_token = 0

    def next_int(self):
        return int(self.next())

    def next(self):
        while self.next_token >= len(self.tokens):
            self.read_input()
        r = self.tokens[self.next_token]
        self.next_token += 1
        return r

    def print_ln(self, a):
        self.writer.write(str(a) + '\n')

    def print_int_ln(self, a):
        self.writer.write(' '.join(map(str, a)) + '\n')

    def print_string_ln(self, a):
        self.writer.write(' '.join(map(str, a)) + '\n')

    def log(self, name, value):
        print(name + '=' + str(value), file=sys.stderr)

# Abs returns the absolute value of an integer
def Abs(a):
    if a >= 0:
        return a
    else:
        return -a

# Pow calculates p raised to the power of q
def Pow(p, q):
    return int(math.pow(p, q))

# Min returns the minimum value from a list of integers
def Min(nums):
    if len(nums) == 0:
        raise Exception('function min() requires at least one argument.')
    res = nums[0]
    for i in range(len(nums)):
        res = min(res, nums[i])
    return res

# Max returns the maximum value from a list of integers
def Max(nums):
    if len(nums) == 0:
        raise Exception('function max() requires at least one argument.')
    res = nums[0]
    for i in range(len(nums)):
        res = max(res, nums[i])
    return res

# SortAsc sorts a slice of integers in ascending order
def SortAsc(a):
    return sorted(a)

# SortDesc sorts a slice of integers in descending order
def SortDesc(a):
    return sorted(a, reverse=True)

# GCD computes the greatest common divisor of two integers
def GCD(a, b):
    if b == 0:
        return a
    return GCD(b, a%b)

# LCM computes the least common multiple of two integers
def LCM(a, b):
    if a == 0 and b == 0:
        return 0
    return a * b // GCD(a, b)

# CumSum computes the cumulative sum of a slice of integers
def CumSum(nums):
    sums = [0]

    for i in range(len(nums)):
        sums.append(sums[i] + nums[i])
    return sums

# BisectLeft performs a binary search to find the leftmost index of a target in a sorted slice
def BisectLeft(nums, left, right, target):
    if left == right:
        if nums[left] == target:
            return left
        elif nums[left] < target:
            return left + 1
        else:
            return left

    mid = (left + right) // 2
    if nums[mid] == target:
        return mid

    if nums[mid] > target:
        return BisectLeft(nums, left, mid, target)
    elif nums[mid] < target:
        return BisectLeft(nums, mid+1, right, target)
    return 0

# Permutations generates all permutations of a slice of integers
def Permutations(nums):
    n = len(nums)
    if n == 0:
        return []
    ans = []

    for _, n in enumerate(nums):
        rest = remove(nums, n)
        lists = Permutations(rest)
        if len(lists) == 0:
            lists = [[]]

        for i in range(len(lists)):
            lists[i] = lists[i] + [n]
            ans.append(lists[i])
    return ans

# remove removes a target integer from a slice
def remove(nums, target):
    result = []
    for i in range(len(nums)):
        if nums[i] != target:
            result.append(nums[i])
    return result

# PowerSet generates the power set of a slice of integers
def PowerSet(nums):
    size = Pow(2, len(nums))
    result = [[] for _ in range(size)]

    idx = 0
    result[idx] = []
    idx += 1

    for _, n in enumerate(nums):
        max = idx
        for i in range(max):
            result[idx] = copyAndAppend(result[i], n)
            idx += 1
    return result

# copyAndAppend creates a new slice by appending an integer to an existing slice
def copyAndAppend(nums, n):
    dst = nums[:]
    dst.append(n)
    return dst

# Combination generates all combinations of k elements from a slice of integers
def Combination(nums, k):
    size = len(nums)
    result = [[] for _ in range(CombinationCount(int(len(nums)), int(k), 10e10))]
    bi = (1 << uint(k)) - 1
    max = 1 << uint(size)
    idx = 0

    for bi in range(bi, max):
        flags = bi
        s = []
        for _, n in enumerate(nums):
            if flags % 2 != 0:
                s.append(n)
            flags //= 2
        result[idx] = s
        idx += 1
    return result

# Combination2NextIndex computes the next combination index
def Combination2NextIndex(n):
    smallest = n & -n
    ripple = n + smallest
    newSmallest = ripple & -ripple
    ones = ((newSmallest // smallest) >> 1) - 1
    return ripple | ones

# CombinationCount calculates nCm using memoization to reduce computation time
def CombinationCount(n, m, maxInput):
    memo = {i: {} for i in range(1, maxInput*maxInput+1)}
    return combinationCount(n, m, memo)

# combinationCount is a helper function for calculating combinations with memoization
def combinationCount(n, m, memo):
    if n == m or m == 0:
        return 1

    left, lOK = memo[n-1].get(m-1, None)
    right, rOK = memo[n-1].get(m, None)

    if lOK and rOK:
        return left + right

    if lOK:
        right = combinationCount(n-1, m, memo)
        memo[n-1][m] = right
        return left + right

    if rOK:
        left = combinationCount(n-1, m-1, memo)
        memo[n-1][m-1] = left
        return left + right

    left = combinationCount(n-1, m-1, memo)
    right = combinationCount(n-1, m, memo)
    memo[n-1][m-1] = left
    memo[n-1][m] = right
    return left + right

# Fact computes the factorial of a number
def Fact(n):
    if n == 0:
        return 1
    else:
        return n * Fact(n-1)

# Divisors returns all divisors of a given integer
def Divisors(n):
    divisors = {}
    for i in range(1, int(math.sqrt(n))+1):
        if n % i == 0:
            divisors[i] = True
            if i != n // i:
                divisors[n//i] = True
    ans = []
    for k in divisors:
        ans.append(k)
    return ans

if __name__ == '__main__':
    main()

