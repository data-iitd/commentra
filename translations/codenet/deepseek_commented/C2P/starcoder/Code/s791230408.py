# <START-OF-CODE>

# Step 1: Read the number of test cases (j) from the user input.
j = int(input())

for i in range(j):
	# Step 3: For each test case, read three integers (a, b, c).
	a,b,c = map(int,input().split())

	# Step 4: Determine the maximum of the three integers.
	max = a
	k = 0
	if max <= b:
		max = b
		k = 1
	if max <= c:
		max = c
		k = 2

	# Step 5: Calculate the square of the maximum and the squares of a, b, and c.
	max = max*max
	a = a*a
	b = b*b
	c = c*c

	# Step 6: Check if the square of the maximum is equal to the sum of the squares of the other two integers.
	if k == 0 and max == b+c:
		print("YES")
	elif k == 1 and max == a+c:
		print("YES")
	elif k == 2 and max == a+b:
		print("YES")
	else:
		print("NO")

# 