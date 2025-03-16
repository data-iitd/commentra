# Depth-first search
import sys

def genid(a, b):
	if b < a:
		a, b = b, a
	return a*100000 + b

def main():
	N = int(sys.stdin.readline())

	ab = [[0, 0] for i in range(N-1)]
	edges = [[] for i in range(N)]
	for i in range(N-1):
		a, b = map(int, sys.stdin.readline().split())
		a -= 1
		b -= 1
		ab[i][0], ab[i][1] = a, b
		edges[a].append(b)
		edges[b].append(a)

	colors = {}
	q = []
	q.append([0, -1, -1])
	while len(q)!= 0:
		currentNode, usedColor, parentNode = q.pop()
		color = 1
		for childNode in edges[currentNode]:
			if childNode == parentNode:
				continue
			if color == usedColor:
				color += 1
			colors[genid(currentNode, childNode)] = color
			q.append([childNode, color, currentNode])
			color += 1

	K = -1
	for i in range(N):
		t = len(edges[i])
		if t > K:
			K = t
	print(K)

	for i in range(N-1):
		print(colors[genid(ab[i][0], ab[i][1])])

if __name__ == "__main__":
	main()

# 