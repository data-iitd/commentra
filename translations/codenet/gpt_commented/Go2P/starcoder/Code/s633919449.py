import sys

# Constants for buffer sizes and modulo value
initialBufSize = 10000
maxBufSize     = 1000000
mod            = 1e9 + 7

# Function to read an integer from input
def getInt():
	return int(sys.stdin.readline().strip())

# Function to read an array of integers from input
def getIntArray(n):
	return [int(x) for x in sys.stdin.readline().strip().split()]

# Function to read a string from input
def getString():
	return sys.stdin.readline().strip()

# Function to read an array of strings from input
def getStringArray(n):
	return [x for x in sys.stdin.readline().strip().split()]

# Function to calculate the absolute value of an integer
def abs(a):
	return abs(a)

# Function to calculate p raised to the power of q
def pow(p, q):
	return pow(p, q)

# Function to calculate n raised to the power of p modulo mod
def powMod(n, p):
	if p == 0:
		return 1
	elif p%2 == 0:
		t = powMod(n, p/2)
		return calcMod(t * t)
	else:
		return calcMod(n * powMod(n, p-1))

# Function to find the minimum value among a list of integers
def min(nums):
	if len(nums) == 0:
		raise Exception("function min() requires at least one argument.")
	res = nums[0]
	for i in range(0, len(nums)):
		res = min(res, nums[i])
	return res

# Function to find the maximum value among a list of integers
def max(nums):
	if len(nums) == 0:
		raise Exception("function max() requires at least one argument.")
	res = nums[0]
	for i in range(0, len(nums)):
		res = max(res, nums[i])
	return res

# Function to check if a string exists in an array of strings
def strSearch(a, b):
	for i in range(0, len(a)):
		if a[i] == b:
			return True
	return False

# Function to print an array of integers
def printIntArray(array):
	strArray = str(array)
	print strArray[1 : len(strArray)-1]

# Function to calculate x modulo mod
def calcMod(x):
	return x % mod

# Function to reverse a string
def reverse(s):
	return s[::-1]

# Function to check if a number is prime
def isPrime(n):
	if n < 2:
		return False
	elif n == 2:
		return True
	elif n%2 == 0:
		return False

	sqrtN = int(math.sqrt(float(n)))
	for i in range(3, sqrtN+1, 2):
		if n%i == 0:
			return False
	return True

# Function to check if an integer exists in a slice
def contains(s, e):
	for _, v in enumerate(s):
		if e == v:
			return True
	return False

# Function to create a range of integers from min to max
def makeRange(min, max):
	a = [0] * (max-min+1)
	for i in range(0, len(a)):
		a[i] = min + i
	return a

# Function to generate the powerset of a given slice of integers
def powerset2(nums):
	length = int(math.pow(2, float(len(nums))))
	result = [[]] * length

	index = 0
	result[index] = []
	index += 1

	# Generate all subsets
	for _, n in enumerate(nums):
		max = index
		for i in range(0, max):
			result[index] = copyAndAppend(result[i], n)
			index += 1

	return result

# Helper function to copy a slice and append a new element
def copyAndAppend(nums, n):
	dst = [0] * (len(nums)+1)
	for i in range(0, len(nums)):
		dst[i] = nums[i]
	dst[len(nums)] = n
	return dst

# Function to calculate the greatest common divisor (GCD) of two integers
def calcGcd(x, y):
	if y == 0:
		return x
	elif x >= y:
		return calcGcd(y, x%y)
	else:
		return calcGcd(x, y%x)

# Function to get all divisors of a number
def getDivisor(n):
	divisor = {}
	divisor[1] = struct{}{}
	if n!= 1:
		divisor[n] = struct{}{}

	sqrt = int(math.sqrt(float(n)))
	for i in range(2, sqrt+1):
		if n%i == 0:
			divisor[i] = struct{}{}
			divisor[n/i] = struct{}{}
	return divisor.keys()

# Custom heap type for integers
class intHeap:
	def __init__(self):
		self.h = []

	def Len(self):
		return len(self.h)

	def Less(self, i, j):
		return self.h[i] > self.h[j]

	def Swap(self, i, j):
		self.h[i], self.h[j] = self.h[j], self.h[i]

	# Push an element onto the heap
	def Push(self, x):
		self.h.append(x)

	# Pop an element from the heap
	def Pop(self):
		return self.h.pop()

# Initialize a new integer heap
def initHeap():
	ih = intHeap()
	ih.h = []
	return ih

# Push an integer onto the heap
def pushHeap(h, n):
	h.Push(n)

# Pop an integer from the heap
def popHeap(h):
	return h.Pop()

# Function to calculate factorial modulo mod
def factMod(n):
	value = 1
	for ; n > 1; n--:
		value = calcMod(value * n)
	return value

# Function to calculate combinations modulo mod
def combinationMod(n, k):
	factN = factMod(n)
	factK = factMod(k)
	factNK = factMod(n - k)
	factKR = powMod(factK, mod-2)
	factNKR = powMod(factNK, mod-2)
	return calcMod(factN * calcMod(factKR * factNKR))

# Function to find prime factors of a number
def primeFactors(n):
	factors = []
	i = 2
	for i*i <= n:
		r = n % i
		if r!= 0:
			i += 1
		else:
			n /= i
			factors.append(i)
	if n > 1:
		factors.append(n)
	return factors

# 