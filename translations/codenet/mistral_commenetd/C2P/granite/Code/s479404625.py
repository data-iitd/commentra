

# Python code to check if the last character of string A is same as the first character of string B and the last character of string B is same as the first character of string C

# Declare three string variables A, B, and C
A = input("Enter the first string: ")
B = input("Enter the second string: ")
C = input("Enter the third string: ")

# Calculate the length of strings A and B using len function and store the lengths in la and lb respectively
la = len(A)
lb = len(B)

# Logical block to check if the last character of string A is same as the first character of string B
# and the last character of string B is same as the first character of string C
if A[la - 1] == B[0] and B[lb - 1] == C[0]:
	# If the condition is true, print YES on the console
	print("YES")
else:
	# If the condition is false, print NO on the console
	print("NO")

# End of Python code
