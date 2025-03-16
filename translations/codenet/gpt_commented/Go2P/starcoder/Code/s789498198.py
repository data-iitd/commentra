import sys

def main():
	# Read two integers from input
	AB = list(map(int, input().split()))
	A = AB[0]
	B = AB[1]

	# Check if the sum of A and B is even
	if (A+B)%2 == 0:
		# If even, print the average
		print((A + B) / 2)
		return
	# If odd, print "IMPOSSIBLE"
	print("IMPOSSIBLE")

if __name__ == "__main__":
	main()

