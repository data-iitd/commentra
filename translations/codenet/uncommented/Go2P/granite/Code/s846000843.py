

import bufio
import math
import os
import sys

def main():
    io = Io()
    try:
        n = io.Int()

        aa = [io.Int() for _ in range(n)]

        cumsum = cumsum(aa)

        ans = 2020202020
        for i in range(1, len(cumsum)-1):
            ans = min(ans, abs(cumsum[-1]-cumsum[i]-(cumsum[i]-cumsum[0])))

        print(ans)

    finally:
        io.Flush()

class Io:
    def __init__(self):
        self.reader = bufio.NewReader(sys.stdin)
        self.writer = bufio.BufferedWriter(sys.stdout)
        self.tokens = []
        self.nextToken = 0

    def Flush(self):
        self.writer.flush()

    def NextLine(self):
        line = ""
        while True:
            char = self.reader.read(1).decode()
            if char == "\n":
                break
            line += char
        return line

    def Next(self):
        while self.nextToken >= len(self.tokens):
            self.tokens = self.NextLine().split()
            self.nextToken = 0
        token = self.tokens[self.nextToken]
        self.nextToken += 1
        return token

    def Int(self):
        return int(self.Next())

    def Float(self):
        return float(self.Next())

    def PrintLn(self, *args):
        print(*args, sep="\n", end="\n", file=self.writer, flush=True)

    def Printf(self, format, *args):
        print(format, *args, sep="", end="", file=self.writer, flush=True)

    def PrintIntLn(self, a):
        self.PrintLn(*a)

    def PrintStringLn(self, a):
        self.PrintLn(*a)

def Log(name, value):
    print(f"{name}={value}", file=sys.stderr)

def Abs(a):
    return abs(a)

def Pow(p, q):
    return pow(p, q)

def Min(*args):
    return min(args)

def Max(*args):
    return max(args)

def SortAsc(a):
    return sorted(a)

def SortDesc(a):
    return sorted(a, reverse=True)

def GCD(a, b):
    if b == 0:
        return a
    return GCD(b, a % b)

def LCM(a, b):
    if a == 0 and b == 0:
        return 0
    return a * b // GCD(a, b)

def CumSum(nums):
    sums = [0]
    for num in nums:
        sums.append(sums[-1] + num)
    return sums

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
    if nums[mid] < target:
        return BisectLeft(nums, mid + 1, right, target)
    return 0

def Permutations(nums):
    n = len(nums)
    if n == 0:
        return []
    ans = []
    for num in nums:
        rest = remove(nums, num)
        lists = Permutations(rest)
        if len(lists) == 0:
            lists = [None]
        for i in range(len(lists)):
            lists[i] = lists[i] + [num]
            ans.append(lists[i])
    return ans

def remove(nums, target):
    return [num for num in nums if num!= target]

def PowerSet(nums):
    size = Pow(2, len(nums))
    result = [[] for _ in range(size)]
    idx = 0
    result[idx] = []
    idx += 1
    for num in nums:
        max = idx
        for i in range(max):
            result[idx] = copyAndAppend(result[i], num)
            idx += 1
    return result

def copyAndAppend(nums, num):
    dst = nums[:]
    dst.append(num)
    return dst

def Combination(nums, k):
    size = len(nums)
    result = [[] for _ in range(CombinationCount(size, k, 10e10))]
    bi = (1 << k) - 1
    max = 1 << size
    idx = 0
    for bi in range(max):
        flags = bi
        s = []
        for num in nums:
            if flags % 2!= 0:
                s.append(num)
            flags //= 2
        result[idx] = s
        idx += 1
        bi = Combination2NextIndex(bi)
    return result

def Combination2NextIndex(n):
    smallest = n & -n
    ripple = n + smallest
    newSmallest = ripple & -ripple
    ones = ((newSmallest // smallest) >> 1) - 1
    return ripple | ones

# CombinationCount returns nCm.
def CombinationCount(n, m, maxInput):
    memo = {}
    for i in range(1, maxInput * maxInput + 1):
        memo[i] = {}
    return combinationCount(n, m, memo)

def combinationCount(n, m, memo):
    if n == m or m == 0:
        return 1
    if (n, m) in memo:
        return memo[(n, m)]
    left = combinationCount(n - 1, m - 1, memo)
    right = combinationCount(n - 1, m, memo)
    memo[(n, m - 1)] = left
    memo[(n, m)] = right
    return left + right

def Fact(n):
    if n == 0:
        return 1
    else:
        return n * Fact(n - 1)

def Divisors(n):
    divisors = set()
    for i in range(1, int(math.sqrt(n)) + 1):
        if n % i == 0:
            divisors.add(i)
            if i!= n:
                divisors.add(n // i)
    return list(divisors)

if __name__ == "__main__":
    main()

