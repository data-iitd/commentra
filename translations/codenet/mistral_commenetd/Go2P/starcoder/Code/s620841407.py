
# <START-OF-CODE>

MOD = 1000000000 + 7
ALPHABET_NUM = 26
INF_INT64 = 1 << 60
INF_BIT60 = 1 << 60
INF_INT32 = 1 << 30
INF_BIT30 = 1 << 30
NIL = -1

WHITE = 0
GRAY = 1
BLACK = 2

def main():
	# Read input: number of nodes and edges
	n, m = ReadInt2()
	for i in range(n-1):
		x, y = ReadInt2()
		x -= 1
		y -= 1

		e = [x, y]
		edges = append(edges, e)

	# Initialize the disjoint set data structure
	f = lambda x, y: (x * y) % m
	g = lambda v, p: v + 1
	s = NewReRootingSolver(n, edges, 1, f, g)

	# Query the product of subtrees for all nodes and print the result
	for i in range(n):
		print(s.Query(i) - 1)

class T:
	def __init__(self, v):
		self.v = v

	def __add__(self, other):
		return T(self.v + other.v)

	def __mul__(self, other):
		return T(self.v * other.v)

	def __str__(self):
		return str(self.v)

class ReRootingSolver:
	def __init__(self, nodeCount, edges, identity, operate, operateNode):
		self.NodeCount = nodeCount

		self.Adjacents = []
		self.IndexForAdjacents = []

		self.Res = []
		self.DP = []

		self.Identity = identity
		self.Operate = operate
		self.OperateNode = operateNode

		for i in range(nodeCount):
			self.Adjacents.append([])
			self.IndexForAdjacents.append([])

		for e in edges:
			self.IndexForAdjacents[e[0]] = append(self.IndexForAdjacents[e[0]], len(self.Adjacents[e[1]]))
			self.IndexForAdjacents[e[1]] = append(self.IndexForAdjacents[e[1]], len(self.Adjacents[e[0]]))
			self.Adjacents[e[0]] = append(self.Adjacents[e[0]], e[1])
			self.Adjacents[e[1]] = append(self.Adjacents[e[1]], e[0])

		for i in range(len(self.Adjacents)):
			self.DP.append([])
			for j in range(len(self.Adjacents[i])):
				self.DP[i].append(T(0))

		if self.NodeCount > 1:
			self.Initialize()
		else:
			self.Res[0] = self.OperateNode(self.Identity, 0)

	def Query(self, node):
		return self.Res[node]

	def Initialize(self):
		parents, order = make([]int, self.NodeCount), make([]int, self.NodeCount)

		# InitOrderedTree
		index = 0
		stack = []
		stack = append(stack, 0)
		parents[0] = -1
		for len(stack) > 0:
			node = stack[len(stack)-1]
			stack = stack[:len(stack)-1]
			order[index] = node
			index++
			for i in range(len(self.Adjacents[node])):
				adjacent = self.Adjacents[node][i]
				if adjacent == parents[node]:
					continue
				stack = append(stack, adjacent)
				parents[adjacent] = node

		# fromLeaf
		for i in range(len(order) - 1, 0, -1):
			node = order[i]
			parent = parents[node]

			accum = self.Identity
			parentIndex = -1
			for j in range(len(self.Adjacents[node])):
				if self.Adjacents[node][j] == parent:
					parentIndex = j
					continue
				accum = self.Operate(accum, self.DP[node][j])
			self.DP[parent][self.IndexForAdjacents[node][parentIndex]] = self.OperateNode(accum, node)
			accum = self.Operate(accum, self.DP[node][j])
			self.DP[node][j] = accum

		# toLeaf
		for i in range(len(order)):
			node = order[i]
			accum = self.Identity
			accumsFromTail = make([]T, len(self.Adjacents[node]))
			accumsFromTail[len(accumsFromTail)-1] = self.Identity
			for j in range(len(accumsFromTail) - 1, 0, -1):
				accumsFromTail[j-1] = self.Operate(self.DP[node][j], accumsFromTail[j])
			for j in range(len(accumsFromTail)):
				self.DP[self.Adjacents[node][j]][self.IndexForAdjacents[node][j]] = self.OperateNode(self.Operate(accum, accumsFromTail[j]), node)
				accum = self.Operate(accum, self.DP[node][j])
			self.Res[node] = self.OperateNode(accum, node)

def NewReRootingSolver(nodeCount, edges, identity, operate, operateNode):
	return ReRootingSolver(nodeCount, edges, identity, operate, operateNode)

def ReadInt():
	return int(stdin.readline())

def ReadInt2():
	return map(int, stdin.readline().split())

def ReadInt3():
	return map(int, stdin.readline().split())

def ReadInt4():
	return map(int, stdin.readline().split())

def ReadInt5():
	return map(int, stdin.readline().split())

def ReadInt6():
	return map(int, stdin.readline().split())

def ReadInt7():
	return map(int, stdin.readline().split())

def ReadInt8():
	return map(int, stdin.readline().split())

def ReadInt9():
	return map(int, stdin.readline().split())

def ReadInt10():
	return map(int, stdin.readline().split())

def ReadInt11():
	return map(int, stdin.readline().split())

def ReadInt12():
	return map(int, stdin.readline().split())

def ReadInt13():
	return map(int, stdin.readline().split())

def ReadInt14():
	return map(int, stdin.readline().split())

def ReadInt15():
	return map(int, stdin.readline().split())

def ReadInt16():
	return map(int, stdin.readline().split())

def ReadInt17():
	return map(int, stdin.readline().split())

def ReadInt18():
	return map(int, stdin.readline().split())

def ReadInt19():
	return map(int, stdin.readline().split())

def ReadInt20():
	return map(int, stdin.readline().split())

def ReadInt21():
	return map(int, stdin.readline().split())

def ReadInt22():
	return map(int, stdin.readline().split())

def ReadInt23():
	return map(int, stdin.readline().split())

def ReadInt24():
	return map(int, stdin.readline().split())

def ReadInt25():
	return map(int, stdin.readline().split())

def ReadInt26():
	return map(int, stdin.readline().split())

def ReadInt27():
	return map(int, stdin.readline().split())

def ReadInt28():
	return map(int, stdin.readline().split())

def ReadInt29():
	return map(int, stdin.readline().split())

def ReadInt30():
	return map(int, stdin.readline().split())

def ReadInt31():
	return map(int, stdin.readline().split())

def ReadInt32():
	return map(int, stdin.readline().split())

def ReadInt33():
	return map(int, stdin.readline().split())

def ReadInt34():
	return map(int, stdin.readline().split())

def ReadInt35():
	return map(int, stdin.readline().split())

def ReadInt36():
	return map(int, stdin.readline().split())

def ReadInt37():
	return map(int, stdin.readline().split())

def ReadInt38():
	return map(int, stdin.readline().split())

def ReadInt39():
	return map(int, stdin.readline().split())

def ReadInt40():
	return map(int, stdin.readline().split())

def ReadInt41():
	return map(int, stdin.readline().split())

def ReadInt42():
	return map(int, stdin.readline().split())

def ReadInt43():
	return map(int, stdin.readline().split())

def ReadInt44():
	return map(int, stdin.readline().split())

def ReadInt45():
	return map(int, stdin.readline().split())

def ReadInt46():
	return map(int, stdin.readline().split())

def ReadInt47():
	return map(int, stdin.readline().split())

def ReadInt48():
	return map(int, stdin.readline().split())

def ReadInt49():
	return map(int, stdin.readline().split())

def ReadInt50():
	return map(int, stdin.readline().split())

def ReadInt51():
	return map(int, stdin.readline().split())

def ReadInt52():
	return map(int, stdin.readline().split())

def ReadInt53():
	return map(int, stdin.readline().split())

def ReadInt54():
	return map(int, stdin.readline().split())

def ReadInt55():
	return map(int, stdin.readline().split())

def ReadInt56():
	return map(int, stdin.readline().split())

def ReadInt57():
	return map(int, stdin.readline().split())

def ReadInt58():
	return map(int, stdin.readline().split())

def ReadInt59():
	return map(int, stdin.readline().split())

def ReadInt60():
	return map(int, stdin.readline().split())

def ReadInt61():
	return map(int, stdin.readline().split())

def ReadInt62():
	return map(int, stdin.readline().split())

def ReadInt63():
	return map(int, stdin.readline().split())

def ReadInt64():
	return map(int, stdin.readline().split())

def ReadInt65():
	return map(int, stdin.readline().split())

def ReadInt66():
	return map(int, stdin.readline().split())

def ReadInt67():
	return map(int, stdin.readline().split())

def ReadInt68():
	return map(int, stdin.readline().split())

def ReadInt69():
	return map(int, stdin.readline().split())

def ReadInt70():
	return map(int, stdin.readline().split())

def ReadInt71():
	return map(int, stdin.readline().split())

def ReadInt72():
	return map(int, stdin.readline().split())

def ReadInt73():
	return map(int, stdin.readline().split())

def ReadInt74():
	return map(int, stdin.readline().split())

def ReadInt75():
	return map(int, stdin.readline().split())

def ReadInt76():
	return map(int, stdin.readline().split())

def ReadInt77():
	return map(int, stdin.readline().split())

def ReadInt78():
	return map(int, stdin.readline().split())

def ReadInt79():
	return map(int, stdin.readline().split())

def ReadInt80():
	return map(int, stdin.readline().split())

def ReadInt81():
	return map(int, stdin.readline().split())

def ReadInt82():
	return map(int, stdin.readline().split())

def ReadInt83():
	return map(int, stdin.readline().split())

def ReadInt84():
	return map(int, stdin.readline().split())

def ReadInt85():
	return map(int, stdin.readline().split())

def ReadInt86():
	return map(int, stdin.readline().split())

def ReadInt87():
	return map(int, stdin.readline().split())

def ReadInt88():
	return map(int, stdin.readline().split())

def ReadInt89():
	return map(int, stdin.readline().split())

def ReadInt90():
	return map(int, stdin.readline().split())

def ReadInt91():
	return map(int, stdin.readline().split())

def ReadInt92():
	return map(int, stdin.readline().split())

def ReadInt93():
	return map(int, stdin.readline().split())

def ReadInt94():
	return map(int, stdin.readline().split())

def ReadInt95():
	return map(int, stdin.readline().split())

def ReadInt96():
	return map(int, stdin.readline().split())

def ReadInt97():
	return map(int, stdin.readline().split())

def ReadInt98():
	return map(int, stdin.readline().split())

def ReadInt99():
	return map(int, stdin.readline().split())

def ReadInt100():
	return map(int, stdin.readline().split())

def ReadInt101():
	return map(int, stdin.readline().split())

def ReadInt102():
	return map(int, stdin.readline().split())

def ReadInt103():
	return map(int, stdin.readline().split())

def ReadInt104():
	return map(int, stdin.readline().split())

def ReadInt105():
	return map(int, stdin.readline().split())

def ReadInt106():
	return map(int,