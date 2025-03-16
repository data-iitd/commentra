#include <stdio.h>
#include <string.h>

#define MOD 1000000000 + 7
#define ALPHABET_NUM 26
#define INF_INT64 1000000000000000000
#define INF_BIT60 1 << 60

int memo[ALPHABET_NUM];
char str[1000001];

int main() {
	scanf("%s", str);

	for (int i = 0; i < strlen(str); i++) {
		char c = str[i];

		if ('a' <= c && c <= 'z') {
			// toUpper
			// c-('a'-'A')
			memo[c-'a']++;
		} else if ('A' <= c && c <= 'Z') {
			// toLower
			// c+('a'-'A')
			memo[c-'A']++;
		} else {
			// stay
			// c
			continue;
		}
	}

	for (int i = 0; i < ALPHABET_NUM; i++) {
		printf("%c : %d\n", i+'a', memo[i]);
	}
}

// Constants
// The code defines constants for MOD and the number of alphabets, which can be used throughout the program.

// Memoization
// The code uses a memoization array to store counts of each letter.
// This is a common technique in competitive programming to optimize repeated calculations.

// Loop and Conditionals
// The main function reads input, processes it, and prints the results.
// This is a common structure for programs that need to handle multiple inputs.

// END-OF-CODE

# Python
# Python 3.6 or above is required.
# The code starts with the usual import statements.
# This is a common setup for competitive programming in Python.

import sys
import io
import time
import pprint

# Input and Output
# The code includes various functions to read different types of inputs: integers, float numbers, strings, and slices of these types.
# This is useful for competitive programming where inputs can be large and need to be read efficiently.

# ReadInt returns an integer.
def ReadInt():
	return int(input())

# ReadIntSlice returns an integer slice that has n integers.
def ReadIntSlice(n):
	b = list(map(int, input().split()))
	if len(b)!= n:
		raise ValueError(str(n) +'values expected.')
	return b

# ReadFloat64 returns an float64.
def ReadFloat64():
	return float(input())

# ReadFloat64Slice returns an float64 slice that has n float64.
def ReadFloat64Slice(n):
	b = list(map(float, input().split()))
	if len(b)!= n:
		raise ValueError(str(n) +'values expected.')
	return b

# ReadRuneSlice returns a rune slice.
def ReadRuneSlice():
	return []rune(input())

# ReadString returns a WORD string.
def ReadString():
	return input()

# ReadStringSlice returns a WORD string slice that has n WORD strings.
def ReadStringSlice(n):
	b = input().split()
	if len(b)!= n:
		raise ValueError(str(n) +'values expected.')
	return b

# Output Functions
# The code includes various functions to output different types of values: integers, float numbers, strings, and slices of these types.
# This is useful for competitive programming where outputs can be large and need to be written efficiently.

# PrintIntsLine returns integers string delimited by a space.
def PrintIntsLine(A):
	s = str(A)[1 : len(str(A)) - 1]
	print(' '.join(s.split(',')))

# PrintIntsLine returns integers string delimited by a space.
def PrintIntsLine(A):
	s = str(A)[1 : len(str(A)) - 1]
	print(' '.join(s.split(',')))

# PrintIntsLine returns integers string delimited by a space.
def PrintIntsLine(A):
	s = str(A)[1 : len(str(A)) - 1]
	print(' '.join(s.split(',')))

# PrintIntsLine returns integers string delimited by a space.
def PrintIntsLine(A):
	s = str(A)[1 : len(str(A)) - 1]
	print(' '.join(s.split(',')))

# PrintIntsLine returns integers string delimited by a space.
def PrintIntsLine(A):
	s = str(A)[1 : len(str(A)) - 1]
	print(' '.join(s.split(',')))

# PrintIntsLine returns integers string delimited by a space.
def PrintIntsLine(A):
	s = str(A)[1 : len(str(A)) - 1]
	print(' '.join(s.split(',')))

# PrintIntsLine returns integers string delimited by a space.
def PrintIntsLine(A):
	s = str(A)[1 : len(str(A)) - 1]
	print(' '.join(s.split(',')))

# PrintIntsLine returns integers string delimited by a space.
def PrintIntsLine(A):
	s = str(A)[1 : len(str(A)) - 1]
	print(' '.join(s.split(',')))

# PrintIntsLine returns integers string delimited by a space.
def PrintIntsLine(A):
	s = str(A)[1 : len(str(A)) - 1]
	print(' '.join(s.split(',')))

# PrintIntsLine returns integers string delimited by a space.
def PrintIntsLine(A):
	s = str(A)[1 : len(str(A)) - 1]
	print(' '.join(s.split(',')))

# PrintIntsLine returns integers string delimited by a space.
def PrintIntsLine(A):
	s = str(A)[1 : len(str(A)) - 1]
	print(' '.join(s.split(',')))

# PrintIntsLine returns integers string delimited by a space.
def PrintIntsLine(A):
	s = str(A)[1 : len(str(A)) - 1]
	print(' '.join(s.split(',')))

# PrintIntsLine returns integers string delimited by a space.
def PrintIntsLine(A):
	s = str(A)[1 : len(str(A)) - 1]
	print(' '.join(s.split(',')))

# PrintIntsLine returns integers string delimited by a space.
def PrintIntsLine(A):
	s = str(A)[1 : len(str(A)) - 1]
	print(' '.join(s.split(',')))

# PrintIntsLine returns integers string delimited by a space.
def PrintIntsLine(A):
	s = str(A)[1 : len(str(A)) - 1]
	print(' '.join(s.split(',')))

# PrintIntsLine returns integers string delimited by a space.
def PrintIntsLine(A):
	s = str(A)[1 : len(str(A)) - 1]
	print(' '.join(s.split(',')))

# PrintIntsLine returns integers string delimited by a space.
def PrintIntsLine(A):
	s = str(A)[1 : len(str(A)) - 1]
	print(' '.join(s.split(',')))

# PrintIntsLine returns integers string delimited by a space.
def PrintIntsLine(A):
	s = str(A)[1 : len(str(A)) - 1]
	print(' '.join(s.split(',')))

# PrintIntsLine returns integers string delimited by a space.
def PrintIntsLine(A):
	s = str(A)[1 : len(str(A)) - 1]
	print(' '.join(s.split(',')))

# PrintIntsLine returns integers string delimited by a space.
def PrintIntsLine(A):
	s = str(A)[1 : len(str(A)) - 1]
	print(' '.join(s.split(',')))

# PrintIntsLine returns integers string delimited by a space.
def PrintIntsLine(A):
	s = str(A)[1 : len(str(A)) - 1]
	print(' '.join(s.split(',')))

# PrintIntsLine returns integers string delimited by a space.
def PrintIntsLine(A):
	s = str(A)[1 : len(str(A)) - 1]
	print(' '.join(s.split(',')))

# PrintIntsLine returns integers string delimited by a space.
def PrintIntsLine(A):
	s = str(A)[1 : len(str(A)) - 1]
	print(' '.join(s.split(',')))

# PrintIntsLine returns integers string delimited by a space.
def PrintIntsLine(A):
	s = str(A)[1 : len(str(A)) - 1]
	print(' '.join(s.split(',')))

# PrintIntsLine returns integers string delimited by a space.
def PrintIntsLine(A):
	s = str(A)[1 : len(str(A)) - 1]
	print(' '.join(s.split(',')))

# PrintIntsLine returns integers string delimited by a space.
def PrintIntsLine(A):
	s = str(A)[1 : len(str(A)) - 1]
	print(' '.join(s.split(',')))

# PrintIntsLine returns integers string delimited by a space.
def PrintIntsLine(A):
	s = str(A)[1 : len(str(A)) - 1]
	print(' '.join(s.split(',')))

# PrintIntsLine returns integers string delimited by a space.
def PrintIntsLine(A):
	s = str(A)[1 : len(str(A)) - 1]
	print(' '.join(s.split(',')))

# PrintIntsLine returns integers string delimited by a space.
def PrintIntsLine(A):
	s = str(A)[1 : len(str(A)) - 1]
	print(' '.join(s.split(',')))

# PrintIntsLine returns integers string delimited by a space.
def PrintIntsLine(A):
	s = str(A)[1 : len(str(A)) - 1]
	print(' '.join(s.split(',')))

# PrintIntsLine returns integers string delimited by a space.
def PrintIntsLine(A):
	s = str(A)[1 : len(str(A)) - 1]
	print(' '.join(s.split(',')))

# PrintIntsLine returns integers string delimited by a space.
def PrintIntsLine(A):
	s = str(A)[1 : len(str(A)) - 1]
	print(' '.join(s.split(',')))

# PrintIntsLine returns integers string delimited by a space.
def PrintIntsLine(A):
	s = str(A)[1 : len(str(A)) - 1]
	print(' '.join(s.split(',')))

# PrintIntsLine returns integers string delimited by a space.
def PrintIntsLine(A):
	s = str(A)[1 : len(str(A)) - 1]
	print(' '.join(s.split(',')))

# PrintIntsLine returns integers string delimited by a space.
def PrintIntsLine(A):
	s = str(A)[1 : len(str(A)) - 1]
	print(' '.join(s.split(',')))

# PrintIntsLine returns integers string delimited by a space.
def PrintIntsLine(A):
	s = str(A)[1 : len(str(A)) - 1]
	print(' '.join(s.split(',')))

# PrintIntsLine returns integers string delimited by a space.
def PrintIntsLine(A):
	s = str(A)[1 : len(str(A)) - 1]
	print(' '.join(s.split(',')))

# PrintIntsLine returns integers string delimited by a space.
def PrintIntsLine(A):
	s = str(A)[1 : len(str(A)) - 1]
	print(' '.join(s.split(',')))

# PrintIntsLine returns integers string delimited by a space.
def PrintIntsLine(A):
	s = str(A)[1 : len(str(A)) - 1]
	print(' '.join(s.split(',')))

# PrintIntsLine returns integers string delimited by a space.
def PrintIntsLine(A):
	s = str(A)[1 : len(str(A)) - 1]
	print(' '.join(s.split(',')))

# PrintIntsLine returns integers string delimited by a space.
def PrintIntsLine(A):
	s = str(A)[1 : len(str(A)) - 1]
	print(' '.join(s.split(',')))

# PrintIntsLine returns integers string delimited by a space.
def PrintIntsLine(A):
	s = str(A)[1 : len(str(A)) - 1]
	print(' '.join(s.split(',')))

# PrintIntsLine returns integers string delimited by a space.
def PrintIntsLine(A):
	s = str(A)[1 : len(str(A)) - 1]
	print(' '.join(s.split(',')))

# PrintIntsLine returns integers string delimited by a space.
def PrintIntsLine(A):
	s = str(A)[1 : len(str(A)) - 1]
	print(' '.join(s.split(',')))

# PrintIntsLine returns integers string delimited by a space.
def PrintIntsLine(A):
	s = str(A)[1 : len(str(A)) - 1]
	print(' '.join(s.split(',')))

# PrintIntsLine returns integers string delimited by a space.
def PrintIntsLine(A):
	s = str(A)[1 : len(str(A)) - 1]
	print(' '.join(s.split(',')))

# PrintIntsLine returns integers string delimited by a space.
def PrintIntsLine(A):
	s = str(A)[1 : len(str(A)) - 1]
	print(' '.join(s.split(',')))

# PrintIntsLine returns integers string delimited by a space.
def PrintIntsLine(A):
	s = str(A)[1 : len(str(A)) - 1]
	print(' '.join(s.split(',')))

# PrintIntsLine returns integers string delimited by a space.
def PrintIntsLine(A):
	s = str(A)[1 : len(str(A)) - 1]
	print(' '.join(s.split