
# Package main defines the entry point for the program.

# <START-OF-CODE>

# initialBufSize and maxBufSize define the buffer sizes for scanning input.
initialBufSize = 1e4
maxBufSize = 1e8
INF = 1e8

# scanner and writer are initialized for reading from standard input and writing to standard output.
scanner = bufio.NewScanner(os.Stdin)
writer = bufio.NewWriter(os.Stdout)
di = [-1, 0, 1, 0]
dj = [0, -1, 0, 1]

# NextPermutation finds the next permutation of a slice.
def NextPermutation(x):
	n = len(x) - 1
	if n < 1:
		return False
	j = n - 1
	for ; not x[j] < x[j+1]; j--:
		if j == 0:
			return False
	l = n
	for not x[j] < x[l]:
		l--
	x[j], x[l] = x[l], x[j]
	for k, l in enumerate(x[j+1:], j+1):
		x[k], x[l] = x[l], x[k]
	return True

# doubleAry creates a 2D slice initialized with a given value.
def doubleAry(h, w, init):
	res = make([][], h)
	for i in range(h):
		res[i] = make([]int, w)
		for j in range(w):
			res[i][j] = init
	return res

# aryEq checks if two slices are equal.
def aryEq(a, b):
	return reflect.DeepEqual(a, b)

# clone creates a copy of a slice.
def clone(n):
	r = make([]int, len(n))
	for i in range(len(n)):
		r[i] = n[i]
	return r

# write writes a string to the writer.
def write(s):
	writer.WriteString(s)

# print flushes the writer.
def print():
	writer.Flush()

# readLine reads a line of text from the scanner.
def readLine():
	if scanner.Scan():
		return scanner.Text()
	return ""

# readInt reads an integer from the scanner.
def readInt():
	scanner.Scan()
	return int(scanner.Text())

# readFloat reads a float from the scanner.
def readFloat():
	scanner.Scan()
	return float(scanner.Text())

# readRunes reads a slice of runes from the scanner.
def readRunes():
	scanner.Scan()
	return list(scanner.Text())

# readString reads a string from the scanner.
def readString():
	scanner.Scan()
	return scanner.Text()

# readStrings reads multiple strings from the scanner.
def readStrings():
	scanner.Scan()
	return strings.Split(scanner.Text(), " ")

# s2i converts a string to an integer.
def s2i(s):
	return int(s)

# i2s converts an integer to a string.
def i2s(i):
	return str(i)

# s2f converts a string to a float.
def s2f(s):
	return float(s)

# abs returns the absolute value of an integer.
def abs(i):
	return abs(i)

# max returns the maximum value in a list of integers.
def max(a):
	ans = a[0]
	for i, v in enumerate(a):
		if i == 0:
			ans = v
		if ans < v:
			ans = v
	return ans

# min returns the minimum value in a list of integers.
def min(a):
	ans = a[0]
	for i, v in enumerate(a):
		if i == 0:
			ans = v
		if ans > v:
			ans = v
	return ans

# sum returns the sum of a slice of integers.
def sum(i):
	sum = 0
	for _, val in enumerate(i):
		sum += val
	return sum

# split splits a string into a slice of strings.
def split(s):
	return s.split()

# strAry2intAry converts a slice of strings to a slice of integers.
def strAry2intAry(strs):
	ret = []
	for str in strs:
		intVal = s2i(str)
		ret.append(intVal)
	return ret

# intAry2strAry converts a slice of integers to a slice of strings.
def intAry2strAry(nums):
	ret = []
	for num in nums:
		strVal = i2s(num)
		ret.append(strVal)
	return ret

# ary2str joins a slice of strings into a single string.
def ary2str(strs):
	return " ".join(strs)

# reverse reverses a slice of integers.
def reverse(res):
	for i, j in enumerate(range(len(res)-1, -1, -1)):
		res[i], res[j] = res[j], res[i]
	return res

# reverseStr reverses a slice of strings.
def reverseStr(res):
	for i, j in enumerate(range(len(res)-1, -1, -1)):
		res[i], res[j] = res[j], res[i]
	return res

# ini initializes a slice with a specific value.
def ini(res, init):
	if len(res) == 0:
		return
	res[0] = init
	for i in range(len(res)):
		res[i:] = res[:i]

# 