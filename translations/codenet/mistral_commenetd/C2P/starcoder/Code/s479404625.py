
# Declare three character arrays of size 20 each to store strings A, B, and C
A = [None] * 20
B = [None] * 20
C = [None] * 20

# Initialize the character arrays A, B, and C using input() function
A, B, C = input().split()

# Calculate the length of strings A and B using len() function and store the lengths in la and lb respectively
la = len(A)
lb = len(B)

# Logical block to check if the last character of string A is same as the first character of string B
# and the last character of string B is same as the first character of string C
if A[la - 1] == B[0] and B[lb - 1] == C[0]:
	# If the condition is true, print YES on the console
	print("YES")
# Logical block to check if the condition in if block is false
else:
	# If the condition is false, print NO on the console
	print("NO")

# 