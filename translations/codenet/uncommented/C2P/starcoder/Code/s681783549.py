
#include <stdio.h>
#include <stdlib.h>

def main():
	S = raw_input()
	for i in range(len(S)):
		if S[i] == 'A' and S[i + 1] == 'C':
			print "Yes"
			return 0
	print "No"
	return 0

