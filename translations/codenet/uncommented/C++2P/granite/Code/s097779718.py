
def Euclid(x, y):
	tmp = 0

	if x < y:
		tmp = x
		x = y
		y = tmp

	if not (x%y): return y
	return Euclid(y, x%y)

if __name__ == '__main__':
	A, B = map(int, input().split())

	print((A*B) // Euclid(A, B))
