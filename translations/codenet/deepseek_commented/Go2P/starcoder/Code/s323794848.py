
# Deque structure to simulate a double-ended queue
class deque:
	def __init__(self):
		self.front = []
		self.back = []

	# Check if the front of the deque is empty
	def isEmptyFront(self):
		return len(self.front) == 0

	# Check if the back of the deque is empty
	def isEmptyBack(self):
		return len(self.back) == 0

	# Push a byte to the back of the deque
	def pushBack(self, v):
		self.back.append(v)

	# Push a byte to the front of the deque
	def pushFront(self, v):
		self.front.append(v)

	# Pop a byte from the back of the deque
	def popBack(self):
		if not self.isEmptyBack():
			return self.back.pop()
		elif not self.isEmptyFront():
			return self.front.pop(0)
		else:
			return None

	# Pop a byte from the front of the deque
	def popFront(self):
		if not self.isEmptyFront():
			return self.front.pop()
		elif not self.isEmptyBack():
			return self.back.pop(0)
		else:
			return None

	# Get the byte at a specific index in the deque
	def get(self, idx):
		tot = len(self.front) + len(self.back)
		if idx < tot:
			if idx < len(self.front):
				return self.front[len(self.front)-1-idx]
			else:
				return self.back[idx-len(self.front)]
		else:
			return None

# Operation struct to store each operation's details
class op:
	def __init__(self):
		self.rev = False
		self.front = False
		self.c = None

# Reverse a string
def rev(s):
	r = []
	for i in range(len(s)-1, -1, -1):
		r.append(s[i])
	return ''.join(r)

def main():
	S = input()
	Q = int(input())
	ops = []
	for i in range(Q):
		q = int(input())
		if q == 1:
			ops.append(op())
			ops[i].rev = True
		else:
			f, c = map(int, input().split())
			ops.append(op())
			ops[i].c = c
			if f == 1:
				ops[i].front = True
	sum = [0] * (Q+1)
	for i in range(Q-1, 0, -1):
		if ops[i].rev:
			sum[i-1] = sum[i] + 1
		else:
			sum[i-1] = sum[i]
	if sum[0]%2 == 1:
		S = rev(S)
	deq = deque()
	for i in range(Q):
		if not ops[i].rev: # Not a reversal operation (string append)
			if ops[i].front:
				if sum[i]%2 == 1:
					deq.pushBack(ops[i].c)
				else:
					deq.pushFront(ops[i].c)
			else:
				if sum[i]%2 == 1:
					deq.pushFront(ops[i].c)
				else:
					deq.pushBack(ops[i].c)
	for i in range(len(deq.front)-1, -1, -1):
		print(deq.front[i], end='')
	print(S, end='')
	for i in range(len(deq.back)):
		print(deq.back[i], end='')
	print()

