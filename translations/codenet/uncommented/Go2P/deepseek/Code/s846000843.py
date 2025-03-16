import sys
import math
from itertools import accumulate

def main():
    io = Io()
    n = io.int()
    aa = [io.int() for _ in range(n)]
    cumsum = list(accumulate(aa))
    ans = 2020202020
    for i in range(1, len(cumsum) - 1):
        ans = min(ans, abs(cumsum[-1] - cumsum[i] - (cumsum[i] - cumsum[0])))
    print(ans)

class Io:
    def __init__(self):
        self.reader = sys.stdin
        self.writer = sys.stdout
        self.tokens = []
        self.nextToken = 0

    def flush(self):
        pass

    def next_line(self):
        return self.reader.readline().strip()

    def next(self):
        while self.nextToken >= len(self.tokens):
            line = self.next_line()
            self.tokens = line.split()
        r = self.tokens[self.nextToken]
        self.nextToken += 1
        return r

    def int(self):
        return int(self.next())

    def float(self):
        return float(self.next())

    def print_ln(self, *args):
        print(*args, file=self.writer)

    def print_f(self, format, *args):
        print(format.format(*args), file=self.writer)

    def print_int_ln(self, a):
        self.print_ln(a)

    def print_string_ln(self, a):
        self.print_ln(a)

def log(name, value):
    print(f"{name}={value}", file=sys.stderr)

def abs(a):
    return a if a >= 0 else -a

def pow(p, q):
    return int(math.pow(p, q))

def min(*nums):
    return min(nums)

def max(*nums):
    return max(nums)

def sort_asc(a):
    return sorted(a)

def sort_desc(a):
    return sorted(a, reverse=True)

def gcd(a, b):
    while b != 0:
        a, b = b, a % b
    return a

def lcm(a, b):
    return a * b // gcd(a, b)

def cumsum(nums):
    return list(accumulate(nums))

def bisect_left(nums, left, right, target):
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
        return bisect_left(nums, left, mid, target)
    else:
        return bisect_left(nums, mid + 1, right, target)

def permutations(nums):
    if not nums:
        return [[]]
    ans = []
    for i, n in enumerate(nums):
        rest = nums[:i] + nums[i+1:]
        for p in permutations(rest):
            ans.append([n] + p)
    return ans

def remove(nums, target):
    return [x for x in nums if x != target]

def power_set(nums):
    size = 2 ** len(nums)
    result = [[] for _ in range(size)]
    for i, n in enumerate(nums):
        for j in range(1 << i, 1 << (i + 1)):
            result[j] = result[j - (1 << i)] + [n]
    return result

def combination(nums, k):
    size = len(nums)
    result = [[] for _ in range(combination_count(size, k))]
    bi = (1 << k) - 1
    max_bi = 1 << size
    idx = 0
    while bi < max_bi:
        s = []
        for i in range(size):
            if bi & (1 << i):
                s.append(nums[i])
        result[idx] = s
        idx += 1
        bi = combination_next_index(bi)
    return result

def combination_next_index(n):
    smallest = n & -n
    ripple = n + smallest
    new_smallest = ripple & -ripple
    ones = ((new_smallest // smallest) >> 1) - 1
    return ripple | ones

def combination_count(n, m):
    memo = {}
    return combination_count_memo(n, m, memo)

def combination_count_memo(n, m, memo):
    if n == m or m == 0:
        return 1
    if (n, m) in memo:
        return memo[(n, m)]
    memo[(n - 1, m - 1)] = combination_count_memo(n - 1, m - 1, memo)
    memo[(n - 1, m)] = combination_count_memo(n - 1, m, memo)
    return memo[(n - 1, m - 1)] + memo[(n - 1, m)]

def fact(n):
    return math.factorial(n)

def divisors(n):
    divisors_set = set()
    for i in range(1, int(math.sqrt(n)) + 1):
        if n % i == 0:
            divisors_set.add(i)
            divisors_set.add(n // i)
    return list(divisors_set)

