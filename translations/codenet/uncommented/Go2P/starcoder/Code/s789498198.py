import sys

def main():
	AB = [int(x) for x in sys.stdin.readline().split()]
	A = AB[0]
	B = AB[1]

	if (A+B)%2 == 0:
		print((A + B) / 2)
		return
	print("IMPOSSIBLE")

if __name__ == "__main__":
	main()

