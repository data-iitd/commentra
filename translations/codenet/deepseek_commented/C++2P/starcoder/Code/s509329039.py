
# Python 3 program to find the first valid number
# with given number of digits and constraints

# Function to check if the given number
# satisfies all the constraints
def check(st, s, c):
	for i in range(len(s)):
		if st[s[i]]!= c[i]:
			return False
	return True

# Function to find the first valid number
# with given number of digits and constraints
def find_first_valid(n, m):
	# s stores the positions of constraints
	# c stores the values of constraints
	s = [0] * m
	c = [0] * m

	# Read the number of digits and the number of constraints
	n, m = map(int, input().split())

	# Read the positions and values of constraints
	for i in range(m):
		s[i], c[i] = map(int, input().split())
		s[i] -= 1

	# Loop to find the first valid number
	for i in range(10 ** n):
		st = str(i)
		if len(st)!= n:
			continue
		if check(st, s, c):
			print(i)
			return
	print(-1)

# Driver Code
if __name__ == '__main__':
	find_first_valid(n, m)

