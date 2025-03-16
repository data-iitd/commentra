#include <stdio.h>
#include <string.h>

int main()
{
	# Declare character arrays to store three strings
	A = input("Enter three strings separated by spaces: ")
	A = A.split()
	A = [i for i in A]
	B = A[0]
	C = A[1]
	D = A[2]

	# Calculate the lengths of strings A and B
	la = len(B)
	lb = len(C)

	# Check if the last character of A matches the first character of B
	# and if the last character of B matches the first character of C
	if B[la - 1] == C[0] and C[lb - 1] == D[0]:
		# If both conditions are true, print "YES"
		print("YES")
	else:
		# Otherwise, print "NO"
		print("NO")

	# Return 0 to indicate successful execution
	return 0
}

