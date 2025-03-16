
# -*- coding: utf-8 -*-

# Constants for the program
MOD = 1000000000 + 7
ALPHABET_NUM = 26

n, x = map(int, input().split())
A = list(map(int, input().split()))

# Sort the array A
A.sort()

# Initialize answer variable
ans = 0
# Count how many elements can be taken from A without exceeding x
for i in range(n):
	if x >= A[i]:
		ans += 1
		x -= A[i]
	else:
		break
# Adjust answer if all elements are taken and there is still remaining x
if ans == n and x > 0:
	ans -= 1
# Print the final answer
print(ans)

