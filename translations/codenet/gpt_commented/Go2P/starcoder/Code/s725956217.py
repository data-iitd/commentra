# <START-OF-CODE>

# out is a utility function to print output to the console.
def out(x):
	print(x)

# sc is a scanner for reading input from standard input.
sc = bufio.NewScanner(sys.stdin)

# getInt reads an integer from input and returns it.
def getInt():
	sc.Scan()
	i, e = int(sc.Text()), None
	if e!= None:
		raise e
	return i

# getString reads a string from input and returns it.
def getString():
	sc.Scan()
	return sc.Text()

# max returns the maximum of two integers.
def max(a, b):
	if a > b:
		return a
	return b

# min returns the minimum of two integers.
def min(a, b):
	if a < b:
		return a
	return b

# asub returns the absolute difference between two integers.
def asub(a, b):
	if a > b:
		return a - b
	return b - a

# abs returns the absolute value of an integer.
def abs(a):
	if a >= 0:
		return a
	return -a

# lowerBound returns the index of the first element in a that is not less than x.
def lowerBound(a, x):
	idx = bisect.bisect_left(a, x)
	return idx

# upperBound returns the index of the first element in a that is greater than x.
def upperBound(a, x):
	idx = bisect.bisect_right(a, x)
	return idx

# shop represents a shop with a price (a) and available quantity (b).
class shop:
	def __init__(self, a, b):
		self.a = a
		self.b = b

# Datas is a slice of shop, implementing sort.Interface.
class Datas(list):
	def __init__(self, a):
		list.__init__(self, a)

	def Len(self):
		return len(self)

	def Swap(self, i, j):
		self[i], self[j] = self[j], self[i]

	def Less(self, i, j):
		return self[i].a < self[j].a

# main is the entry point of the program.
def main():
	sc.Split(bufio.ScanWords)

	# Read the number of shops (N) and the total quantity needed (M)
	N, M = getInt(), getInt()
	s = Datas([shop(0, 0) for i in range(N)])

	# Read the price and quantity for each shop
	for i in range(N):
		a, b = getInt(), getInt()
		s[i] = shop(a, b)

	s.sort()

	total = 0

	# Calculate the total cost based on available quantities and prices
	for e in s:
		n = min(e.b, M)
		total += n * e.a
		M -= n
		if M == 0:
			break

	out(total)

# 