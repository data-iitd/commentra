#include <stdio.h>
#include <stdlib.h>

def chmin(a, b):
	if a > b:
		return b;
	else:
		return a;

def main():
	n = int(raw_input());
	dp = [10000 for i in range(n)];
	h = [0 for i in range(n)];
	for i in range(n):
		dp[i] = 10000;
		h[i] = int(raw_input());
	dp[0] = 0;
	for i in range(1, n):
		if i == 1:
			dp[1] = abs(h[1] - h[0]);
		else:
			dp[i] = chmin(dp[i - 1] + abs(h[i] - h[i - 1]), dp[i - 2] + abs(h[i] - h[i - 2]));
	print dp[n - 1];

main();
#