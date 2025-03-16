
import sys

def out(*args, **kwargs):
	print(*args, **kwargs)

def getInt():
	return int(sys.stdin.readline())

def getString():
	return sys.stdin.readline().strip()

class Node:
	def __init__(self):
		self.to = []

def main():
	N, M = getInt(), getInt()
	n = [Node() for _ in range(N)]
	for i in range(M):
		from_, to_ = getInt()-1, getInt()-1
		n[from_].to.append(to_)
		n[to_].to.append(from_)

	for i in range(N):
		out(len(n[i].to))

if __name__ == "__main__":
	main()

# 