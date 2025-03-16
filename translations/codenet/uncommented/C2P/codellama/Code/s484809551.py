#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <ctype.h>
#include <stdint.h>
#include <string.h>
#include <wchar.h>

#define N_MAX (100)
#define P_MAX (100)
#define DP_ARRAY_SIZE (N_MAX * P_MAX / 32 + 1)

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define ABS(a) ((a) < 0 ? -(a) : (a))
#define ABSS(a, b) ((a) > (b) ? (a) - (b) : (b) - (a))

def strrstr(string, pattern):
	offset = 0
	lastP = None

	searchResult = None
	while (searchResult := strstr(string[offset:], pattern)) != None and string[offset] != '\0':
		lastP = searchResult
		offset += 1

	return lastP

def compare_f(a, b):
	return a < b

def comb(n, r):
	result = 1

	for i in range(r):
		result *= n - i
		result //= i + 1

	return result

def gcd(m, n):
	temp = 0

	while m % n != 0:
		temp = n
		n = m % n
		m = temp

	return n

def main():
	patternBase = "keyence"
	top = [0] * 8
	bottom = [0] * 8
	S = [0] * 101

	scanf("%s", S)

	len = len(S)
	found = False

	for offset in range(len(patternBase)):
		top = patternBase[:offset]
		bottom = patternBase[offset:]

		topSearch = strstr(S, top)
		if topSearch != None:
			bottomSearch = strrstr(topSearch[offset:], bottom)
			if bottomSearch != None:
				sepCount = 0

				if topSearch != S:
					sepCount += 1
				if topSearch[offset:] != bottomSearch:
					sepCount += 1
				if bottomSearch[len(bottom)] != '\0':
					sepCount += 1

				if sepCount <= 1:
					found = True
					break

	if found:
		print("YES")
	else:
		print("NO")

	return 0


