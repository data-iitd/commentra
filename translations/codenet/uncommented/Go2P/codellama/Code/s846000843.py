
import sys
import math

def main():
    n = int(sys.stdin.readline().rstrip())

    aa = list(map(int, sys.stdin.readline().rstrip().split()))

    cumsum = CumSum(aa)

    #print(cumsum)
    ans = 2020202020
    for i in range(1, len(cumsum)-1):
        ans = min(ans, abs(cumsum[len(cumsum)-1]-cumsum[i]-(cumsum[i]-cumsum[0])))

    print(ans)

def CumSum(nums):
    sums = [0]

    for i in range(len(nums)):
        sums.append(sums[i]+nums[i])
    return sums

def Min(nums):
    if len(nums) == 0:
        raise Exception("function min() requires at least one argument.")
    res = nums[0]
    for i in range(len(nums)):
        res = min(res, nums[i])
    return res

def Max(nums):
    if len(nums) == 0:
        raise Exception("function max() requires at least one argument.")
    res = nums[0]
    for i in range(len(nums)):
        res = max(res, nums[i])
    return res

def SortAsc(a):
    a.sort()
    return a

def SortDesc(a):
    a.sort(reverse=True)
    return a

def GCD(a, b):
    if b == 0:
        return a
    return GCD(b, a%b)

def LCM(a, b):
    if a == 0 and b == 0:
        return 0
    return a * b // GCD(a, b)

def Abs(a):
    if a >= 0:
        return a
    else:
        return -a

def Pow(p, q):
    return int(math.pow(p, q))

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

def remove(nums, target):
    result = []
    for i in range(len(nums)):
        if nums[i] != target:
            result.append(nums[i])
    return result

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

def copyAndAppend(nums, n):
    dst = nums[:]
    dst.append(n)
    return dst

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

def CombinationCount(n, m, maxInput):
    memo = {i: {} for i in range(1, maxInput*maxInput+1)}
    return combinationCount(n, m, memo)

def combinationCount(n, m, memo):
    if n == m or m == 0:
        return 1

    left, lOK = memo[n-1].get(m-1, None), True
    right, rOK = memo[n-1].get(m, None), True

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

def Fact(n):
    if n == 0:
        return 1
    else:
        return n * Fact(n-1)

def Divisors(n):
    divisors = {}
    for i in range(1, int(math.sqrt(n))+1):
        if n % i == 0:
            divisors[i] = True
            #divisors = append(divisors, i)
            if i != n:
                divisors[n//i] = True
                #divisors = append(divisors, n//i)
    ans = []
    for k in divisors:
        ans.append(k)
    return ans

if __name__ == "__main__":
    main()

