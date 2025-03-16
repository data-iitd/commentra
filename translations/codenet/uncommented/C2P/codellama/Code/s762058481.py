#include <stdio.h>
#include <stdlib.h>

def chmin(a, b):
	if a > b:
		return b
	else:
		return a


def main(argc, argv):
	n = int(input())
	dp = [10000] * n
	h = [0] * n
	for i in range(n):
		dp[i] = 10000

	for i in range(n):
		scanf("%d", &h[i])

	dp[0] = 0
	for i in range(1, n):
		if i == 1:
			dp[1] = abs(h[1] - h[0])
		else:
			dp[i] = chmin(dp[i - 1] + abs(h[i] - h[i - 1]), dp[i - 2] + abs(h[i] - h[i - 2]))

	print(dp[n - 1])
	return 0


