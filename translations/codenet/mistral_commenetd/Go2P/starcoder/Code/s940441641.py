# Function to read a single integer from standard input
# Returns an integer value read from standard input
def ReadInt():
	var i int
	Scan(&i)
	return i

# Function to read a single string from standard input
# Returns a string value read from standard input
def ReadString():
	var s string
	Scan(&s)
	return s

# Function to read multiple integers from standard input
# Reads n integers from standard input and returns a slice of integers
def ReadInts(n int):
	v = make([]int, n)
	for i in range(n):
		Scan(&v[i])
	return v

# Function to read the initial dimensions and number of moves from standard input
# Returns the height, width, and number of moves of the grid
def ReadInput():
	H, W, K = ReadInt(), ReadInt(), ReadInt()
	x1, y1, x2, y2 = ReadInt()-1, ReadInt()-1, ReadInt()-1, ReadInt()-1
	x1, y1 = y1, x1
	x2, y2 = y2, x2
	return H, W, K, x1, y1, x2, y2

# Function to read the input grid from standard input
# Returns a slice of strings representing the grid
def ReadGrid(H, W):
	c = make([]string, H)
	for y in range(H):
		c[y] = ReadString()
	return c

# Function to calculate the index of a cell in the grid based on its position and direction
def toID(x, y, dir):
	return 4 * (W * y + x) + dir

# Function to extract the position and direction from the index of a cell
def splatID(id):
	x = id % W
	y = id / W
	dir = id % 4
	return x, y, dir

# Function to initialize the distances to all cells to infinity and add the starting cell to the heap
def initDist(H, W, K, x1, y1, x2, y2):
	dist = make([]int, W*H*4)
	for i in range(W*H*4):
		dist[i] = Inf
	for i in range(4):
		q.push(State{
			Cost: 0,
			ID:   toID(x1, y1, i),
		})

# Function to process the heap until the goal cell is reached or all cells have been visited
def processHeap():
	for len(q) > 0:
		now = q.pop()
		x, y, dir = splatID(now.ID)

		if x == x2 and y == y2:
			break

		if dist[now.ID] <= now.Cost:
			continue

		dist[now.ID] = now.Cost
		for i in range(4):
			nCost = now.Cost + K
			nID = toID(x, y, i)
			if dist[nID] <= nCost:
				continue
			q.push(State{
				Cost: nCost,
				ID:   nID,
			})

		nx = x + dx[dir]
		ny = y + dy[dir]
		if 0 <= nx and nx < W and 0 <= ny and ny < H:
			nCost = now.Cost + 1
			nID = toID(nx, ny, dir)
			if dist[nID] <= nCost:
				continue
			q.push(State{
				Cost: nCost,
				ID:   nID,
			})

# Function to calculate the minimum number of moves to reach the goal cell
def calculateAnswer():
	ans = Inf
	for i in range(4):
		id = toID(x2, y2, i)
		if dist[id] < ans:
			ans = dist[id]
	return ans

# Function to print the result
def printResult():
	if ans < Inf:
		print(ans)
	else:
		print(-1)

# Global variables
dist = []
q = Heap()

# Constants
dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

# Types
class State:
	def __init__(self, cost, id):
		self.Cost = cost
		self.ID = id

class HeapElement:
	pass

class Heap(list):
	def push(self, v):
		self.append(v)

	def pop(self):
		return self.pop()

# Functions
def ReadInt():
	var i int
	Scan(&i)
	return i

def ReadString():
	var s string
	Scan(&s)
	return s

def ReadInts(n int):
	v = make([]int, n)
	for i in range(n):
		Scan(&v[i])
	return v

def ReadInput():
	H, W, K = ReadInt(), ReadInt(), ReadInt()
	x1, y1, x2, y2 = ReadInt()-1, ReadInt()-1, ReadInt()-1, ReadInt()-1
	x1, y1 = y1, x1
	x2, y2 = y2, x2
	return H, W, K, x1, y1, x2, y2

def ReadGrid(H, W):
	c = make([]string, H)
	for y in range(H):
		c[y] = ReadString()
	return c

def toID(x, y, dir):
	return 4 * (W * y + x) + dir

def splatID(id):
	x = id % W
	y = id / W
	dir = id % 4
	return x, y, dir

def initDist(H, W, K, x1, y1, x2, y2):
	dist = make([]int, W*H*4)
	for i in range(W*H*4):
		dist[i] = Inf
	for i in range(4):
		q.push(State(0, toID(x1, y1, i)))

def processHeap():
	for len(q) > 0:
		now = q.pop()
		x, y, dir = splatID(now.ID)

		if x == x2 and y == y2:
			break

		if dist[now.ID] <= now.Cost:
			continue

		dist[now.ID] = now.Cost
		for i in range(4):
			nCost = now.Cost + K
			nID = toID(x, y, i)
			if dist[nID] <= nCost:
				continue
			q.push(State(nCost, nID))

		nx = x + dx[dir]
		ny = y + dy[dir]
		if 0 <= nx and nx < W and 0 <= ny and ny < H:
			nCost = now.Cost + 1
			nID = toID(nx, ny, dir)
			if dist[nID] <= nCost:
				continue
			q.push(State(nCost, nID))

def calculateAnswer():
	ans = Inf
	for i in range(4):
		id = toID(x2, y2, i)
		if dist[id] < ans:
			ans = dist[id]
	return ans

def printResult():
	if ans < Inf:
		print(ans)
	else:
		print(-1)

# Main
H, W, K, x1, y1, x2, y2 = ReadInput()
c = ReadGrid(H, W)
initDist(H, W, K, x1, y1, x2, y2)
processHeap()
ans = calculateAnswer()
printResult()

# Comments
# Function to read a single integer from standard input
# Returns an integer value read from standard input
def ReadInt():
	var i int
	Scan(&i)
	return i

# Function to read a single string from standard input
# Returns a string value read from standard input
def ReadString():
	var s string
	Scan(&s)
	return s

# Function to read multiple integers from standard input
# Reads n integers from standard input and returns a slice of integers
def ReadInts(n int):
	v = make([]int, n)
	for i in range(n):
		Scan(&v[i])
	return v

# Function to read the initial dimensions and number of moves from standard input
# Returns the height, width, and number of moves of the grid
def ReadInput():
	H, W, K = ReadInt(), ReadInt(), ReadInt()
	x1, y1, x2, y2 = ReadInt()-1, ReadInt()-1, ReadInt()-1, ReadInt()-1
	x1, y1 = y1, x1
	x2, y2 = y2, x2
	return H, W, K, x1, y1, x2, y2

# Function to read the input grid from standard input
# Returns a slice of strings representing the grid
def ReadGrid(H, W):
	c = make([]string, H)
	for y in range(H):
		c[y] = ReadString()
	return c

# Function to calculate the index of a cell in the grid based on its position and direction
def toID(x, y, dir):
	return 4 * (W * y + x) + dir

# Function to extract the position and direction from the index of a cell
def splatID(id):
	x = id % W
	y = id / W
	dir = id % 4
	return x, y, dir

# Function to initialize the distances to all cells to infinity and add the starting cell to the heap
def initDist(H, W, K, x1, y1, x2, y2):
	dist = make([]int, W*H*4)
	for i in range(W*H*4):
		dist[i] = Inf
	for i in range(4):
		q.push(State(0, toID(x1, y1, i)))

# Function to process the heap until the goal cell is reached or all cells have been visited
def processHeap():
	for len(q) > 0:
		now = q.pop()
		x, y, dir = splatID(now.ID)

		if x == x2 and y == y2:
			break

		if dist[now.ID] <= now.Cost:
			continue

		dist[now.ID] = now.Cost
		for i in range(4):
			nCost = now.Cost + K
			nID = toID(x, y, i)
			if dist[nID] <= nCost:
				continue
			q.push(State(nCost, nID))

		nx = x + dx[dir]
		ny = y + dy[dir]
		if 0 <= nx and nx < W and 0 <= ny and ny < H:
			nCost = now.Cost + 1
			nID = toID(nx, ny, dir)
			if dist[nID] <= nCost:
				continue
			q.push(State(nCost, nID))

# Function to calculate the minimum number of moves to reach the goal cell
def calculateAnswer():
	ans = Inf
	for i in range(4):
		id = toID(x2, y2, i)
		if dist[id] < ans:
			ans = dist[id]
	return ans

# Function to print the result
def printResult():
	if ans < Inf:
		print(ans)
	else:
		print(-1)

# Global variables
dist = []
q = Heap()

# Constants
dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

# Types
class State:
	def __init__(self, cost, id):
		self.Cost = cost
		self.ID = id

class HeapElement:
	pass

class Heap(list):
	def push(self, v):
		self.append(v)

	def pop(self):
		return self.pop()

# Functions
def ReadInt():
	var i int
	Scan(&i)
	return i

def ReadString():
	var s string
	Scan(&s)
	return s

def ReadInts(n int):
	v = make([]int, n)
	for i in range(n):
		Scan(&v[i])
	return v

def ReadInput():
	H, W, K = ReadInt(), ReadInt(), ReadInt()
	x1, y1, x2, y2 = ReadInt()-1, ReadInt()-1, ReadInt()-1, ReadInt()-1
	x1, y1 = y1, x1
	x2, y2 = y2, x2
	return H, W, K, x1, y1, x2, y2

def ReadGrid(H, W):
	c = make([]string, H)
	for y in range(H):
		c[y] = ReadString()
	return c

def toID(x, y, dir):
	return 4 * (W * y + x) + dir

def splatID(id):
	x = id % W
	y = id / W
	dir = id % 4
	return x, y, dir

def initDist(H, W, K, x1, y1, x2, y2):
	dist = make([]int, W*H*4)
	for i in range(W*H*4):
		dist[i] = Inf
	for i in range(4):
		q.push(State(0, toID(x1, y1, i)))

def processHeap():
	for len(q) > 0:
		now = q.pop()
		x, y, dir = splatID(now.ID)

		if x == x2 and y == y2:
			break

		if dist[now.ID] <= now.Cost:
			continue

		dist[now.ID] = now.Cost
		for i in range(4):
			nCost = now.Cost + K
			nID = toID(x, y, i)
			if dist[nID] <= nCost:
				continue
			q.push(State(nCost, nID))

		nx = x + dx[dir]
		ny = y + dy[dir]
		if 0 <= nx and nx < W and 0 <= ny and ny < H:
			nCost = now.Cost + 1
			nID = toID(nx, ny, dir)
			if dist[nID] <= nCost:
				continue
			q.push(State(nCost, nID))

def calculateAnswer():
	ans = Inf
	for i in range(4):
		id = toID(x2, y2, i)
		if dist[id] < ans:
			ans = dist[id]
	return ans

def printResult():
	if ans < Inf:
		print(ans)
	else:
		print(-1)

# Main
H, W, K, x1, y1, x2, y2 = ReadInput()
c = ReadGrid(H, W)
initDist(H, W, K, x1, y1, x2, y2)
processHeap()
ans = calculateAnswer()
printResult()

# Comments
# Function to read a single integer from standard input
# Returns an integer value read from standard input
def ReadInt():
	var i int
	Scan(&i)
	return i

# Function to read a single string from standard input
# Returns a string value read from standard input
def ReadString():
	var s string
	Scan(&s)
	return s

# Function to read multiple integers from standard input
# Reads n integers from standard input and returns a slice of integers
def ReadInts(n int):
	v = make([]int, n)
	for i in range(n):
		Scan(&v[i])
	return v

# Function to read the initial dimensions and number of moves from standard input
# Returns the height, width, and number of moves of the grid
def ReadInput():
	H, W, K = ReadInt(), ReadInt(), ReadInt()
	x1, y1, x2, y2 = ReadInt()-1, ReadInt()-1, ReadInt()-1, ReadInt()-1
	x1, y1 = y1, x1
	x2, y2 = y2, x2
	return H, W, K, x1, y1, x2, y2

# Function to read the 