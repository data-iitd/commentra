import sys
import math

def main():
	n = int(sys.stdin.readline())
	aa = [int(x) for x in sys.stdin.readline().split()]

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

def BisectLeft(nums, left, right, target):
	if left == right:
		if nums[left] == target:
			return left
		elif nums[left] < target:
			return left + 1
		else:
			return left
	mid = (left + right) / 2
	if nums[mid] == target:
		return mid
	if nums[mid] > target:
		return BisectLeft(nums, left, mid, target)
	elif nums[mid] < target:
		return BisectLeft(nums, mid+1, right, target)
	return 0

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
			lists[i] = append(lists[i], n)
			ans = append(ans, lists[i])
	return ans

def remove(nums, target):
	result = []
	for i in range(len(nums)):
		if nums[i]!= target:
			result = append(result, nums[i])
	return result

def PowerSet(nums):
	size = 2**len(nums)
	result = make([][], size)

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
	dst = make([]int, len(nums)+1)
	copy(dst, nums)
	dst[len(nums)] = n
	return dst

def Combination(nums, k):
	size = len(nums)
	result = make([][], CombinationCount(len(nums), k, 10e10))
	bi = (1 << uint(k)) - 1
	max = 1 << uint(size)
	idx = 0

	for bi < max:
		flags = bi
		s = []
		for _, n in enumerate(nums):
			if flags%2!= 0:
				s = append(s, n)
			flags /= 2
		result[idx] = s
		idx += 1
		bi = Combination2NextIndex(bi)
	return result

def Combination2NextIndex(n):
	smallest = n & -n
	ripple = n + smallest
	newSmallest = ripple & -ripple
	ones = ((newSmallest / smallest) >> 1) - 1
	return ripple | ones

# CombinationCount はnCmを計算する関数。メモ化を使って計算量を削減する。
def CombinationCount(n, m, maxInput):
	memo = {}
	for i in range(1, maxInput*maxInput+1):
		memo[i] = {}
	return combinationCount(n, m, memo)
def combinationCount(n, m, memo):
	if n == m or m == 0:
		return 1
	left, lOK = memo[n-1][m-1]
	right, rOK = memo[n-1][m]

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
	for i in range(1, int(math.sqrt(float(n)))+1):
		if n%i == 0:
			divisors[i] = True
			if i!= n:
				divisors[n/i] = True
	ans = []
	for k in divisors:
		ans = append(ans, k)
	return ans

# 