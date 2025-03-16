
# <START-OF-CODE>

def combi(n, k):
	min = (k-1) * k / 2
	max = (2*n-k+1) * k / 2
	return max - min + 1

def main():
	sc = NewScanner()

	n = sc.ReadInt()
	k = sc.ReadInt()

	total = 0
	for i in range(k, n+1):
		total += combi(n, i)
		total = total % (10**9 + 7)
	print(total)

class Scanner:
	def __init__(self):
		self.bufScanner = bufio.Scanner(sys.stdin)
		self.bufScanner.split(bufio.ScanWords)

	def ReadString(self):
		self.bufScanner.Scan()
		return self.bufScanner.Text()

	def ReadInt(self):
		self.bufScanner.Scan()
		text = self.bufScanner.Text()

		num, err = int(text), None
		if err!= None:
			raise err
		return num

	def ReadInt64(self):
		self.bufScanner.Scan()
		text = self.bufScanner.Text()

		num, err = int(text), None
		if err!= None:
			raise err
		return num

def NewScanner():
	return Scanner()

def main():
	sc = NewScanner()

	n = sc.ReadInt()
	k = sc.ReadInt()

	total = 0
	for i in range(k, n+1):
		total += combi(n, i)
		total = total % (10**9 + 7)
	print(total)

# 