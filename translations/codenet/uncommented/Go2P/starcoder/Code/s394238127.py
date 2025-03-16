import sys

def main():
	c = [[0 for i in range(3)] for j in range(3)]
	a = [0 for i in range(3)]
	b = [0 for i in range(3)]
	for i in range(3):
		for j in range(3):
			c[i][j] = int(sys.stdin.readline())
	for i in range(3):
		a[i] = c[0][i]
	for i in range(3):
		b[i] = c[i][0] - a[0]
	if a[1] == c[1][1] - c[0][1] and a[1] == c[1][2] - c[0][2] and
		a[2] == c[2][1] - c[0][1] and a[2] == c[2][2] - c[0][2]:
		print("Yes")
	else:
		print("No")

if __name__ == "__main__":
	main()

