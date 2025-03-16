
#include <stdio.h>
#include <string.h>

def main():
	A = raw_input()
	B = raw_input()
	C = raw_input()

	la = len(A)
	lb = len(B)

	if A[la - 1] == B[0] and B[lb - 1] == C[0]:
		print "YES"
	else:
		print "NO"

main()

