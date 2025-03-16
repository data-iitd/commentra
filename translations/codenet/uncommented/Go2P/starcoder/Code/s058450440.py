
# <START-OF-CODE>

a = []
ans = 0

def dfs(left, i, res):
	if left == 0:
		global ans
		ans += res
		return
	for j in range(i, len(a)):
		dfs(left-1, j+1, res*a[j])

def main():
	io = newIo()
	n = io.nextInt()
	dic = {}

	for _ in range(n):
		c = io.nextString()[0]
		if c in dic:
			dic[c] += 1
		else:
			dic[c] = 1

	for _, v in dic.items():
		a.append(v)

	dfs(3, 0, 1)
	print(ans)

class io:
	def __init__(self):
		self.reader = bufio.NewReader(os.Stdin)
		self.tokens = []
		self.nextToken = 0

	def nextLine(self):
		buffer = []
		for {
			line, isPrefix, _ := self.reader.ReadLine()
			buffer.append(line)
			if not isPrefix:
				break
		}
		return ''.join(buffer)

	def nextString(self):
		for self.nextToken >= len(self.tokens):
			line = self.nextLine()
			self.tokens = line.split()
			self.nextToken = 0
		r = self.tokens[self.nextToken]
		self.nextToken += 1
		return r

	def nextInt(self):
		i, _ = int(self.nextString()), 0
		return i

if __name__ == '__main__':
	main()

# 