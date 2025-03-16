

import bufio
import math
import os
import sys

def main():
    io = IO()
    n = io.int()
    aa = [io.int() for _ in range(n)]
    cumsum = cumsum(aa)
    ans = 2020202020
    for i in range(1, len(cumsum) - 1):
        ans = min(ans, abs(cumsum[-1] - cumsum[i] - (cumsum[i] - cumsum[0])))
    io.println(ans)

class IO:
    def __init__(self):
        self.reader = bufio.NewReader(sys.stdin)
        self.writer = bufio.BufferedWriter(sys.stdout)
        self.tokens = []
        self.nextToken = 0

    def next_line(self):
        line = ""
        while line.endswith("\n"):
            line = self.reader.readline().decode("utf-8")
        return line

    def next(self):
        while self.nextToken >= len(self.tokens):
            self.tokens = self.next_line().split()
            self.nextToken = 0
        token = self.tokens[self.nextToken]
        self.nextToken += 1
        return token

    def int(self):
        return int(self.next())

    def float(self):
        return float(self.next())

    def print_ln(self, *args):
        self.writer.write(" ".join(map(str, args)) + "\n")

    def print_f(self, format, *args):
        self.writer.write(format.format(*args))

    def print_int_ln(self, a):
        self.print_ln(*a)

    def print_string_ln(self, a):
        self.print_ln(*a)

    def log(self, name, value):
        print(f"{name}={value}", file=sys.stderr)

    def abs(self, a):
        return abs(a)

    def pow(self, p, q):
        return pow(p, q)

    def min(self, *nums):
        return min(nums)

    def max(self, *nums):
        return max(nums)

    def sort_asc(self, a):
        return sorted(a)

    def sort_desc(self, a):
        return sorted(a, reverse=True)

    def gcd(self, a, b):
        if b == 0:
            return a
        return self.gcd(b, a % b)

    def lcm(self, a, b):
        if a == 0 and b == 0:
            return 0
        return a * b // self.gcd(a, b)

    def cumsum(self, nums):
        sums = [0]
        for num in nums:
            sums.append(sums[-1] + num)
        return sums

    def bisect_left(self, nums, left, right, target):
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
            return self.bisect_left(nums, left, mid, target)
        else:
            return self.bisect_left(nums, mid + 1, right, target)

    def permutations(self, nums):
        n = len(nums)
        if n == 0:
            return []
        ans = []
        for num in nums:
            rest = self.remove(nums, num)
            lists = self.permutations(rest)
            if len(lists) == 0:
                lists = [None]
            for i in range(len(lists)):
                lists[i] = lists[i] + [num]
                ans.append(lists[i])
        return ans

    def remove(self, nums, target):
        return [num for num in nums if num!= target]

    def power_set(self, nums):
        size = self.pow(2, len(nums))
        result = [[] for _ in range(size)]
        idx = 0
        result[idx] = []
        idx += 1
        for num in nums:
            max_idx = idx
            for i in range(max_idx):
                result[idx] = self.copy_and_append(result[i], num)
                idx += 1
        return result

    def copy_and_append(self, nums, num):
        dst = nums[:]
        dst.append(num)
        return dst

    def combination(self, nums, k):
        size = len(nums)
        result = [[] for _ in range(self.combination_count(size, k, 10e10))]
        bi = (1 << k) - 1
        max_idx = 1 << size
        idx = 0
        for bi in range(max_idx):
            flags = bi
            s = []
            for num in nums:
                if flags % 2!= 0:
                    s.append(num)
                flags //= 2
            result[idx] = s
            idx += 1
            bi = self.combination2_next_index(bi)
        return result

    def combination2_next_index(self, n):
        smallest = n & -n
        ripple = n + smallest
        new_smallest = ripple & -ripple
        ones = ((new_smallest // smallest) >> 1) - 1
        return ripple | ones

    def combination_count(self, n, m, max_input):
        memo = {}
        for i in range(1, max_input * max_input + 1):
            memo[i] = {}
        return self.combination_count_helper(n, m, memo)

    def combination_count_helper(self, n, m, memo):
        if n == m or m == 0:
            return 1
        if (n, m) in memo:
            return memo[(n, m)]
        left = self.combination_count_helper(n - 1, m - 1, memo)
        right = self.combination_count_helper(n - 1, m, memo)
        memo[(n, m)] = left + right
        return left + right

    def fact(self, n):
        if n == 0:
            return 1
        return n * self.fact(n - 1)

    def divisors(self, n):
        divisors = {}
        for i in range(1, int(math.sqrt(n)) + 1):
            if n % i == 0:
                divisors[i] = True
                if i!= n:
                    divisors[n // i] = True
        ans = []
        for k in divisors:
            ans.append(k)
        return ans

io = IO()
main()
io.writer.flush()

