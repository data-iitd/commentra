#include <stdio.h>

W, N = 0, 0
input = [[0, 0] for i in range(1024)]

def main():
	i, j = 0, 0
	ans = [[0, 0] for i in range(1024)]
	t = 0

	while True:
		for i in range(1024):
			ans[i][0] = 0
			ans[i][1] = 0
			input[i][0] = 0
			input[i][1] = 0

		W, N = map(int, input().split())
		if W == 0:
			break
		for i in range(N):
			input[i][0], input[i][1] = map(int, input().split(','))

		for i in range(N):
			for j in range(1023, input[i][1] - 1, -1):
				if ans[j][0] < input[i][0] + ans[j - input[i][1]][0]:
					ans[j][0] = input[i][0] + ans[j - input[i][1]][0]
					ans[j][1] = input[i][1] + ans[j - input[i][1]][1]

		for j in range(1024):
			if ans[W][0] == ans[W - j - 1][0]:
				break

		print("Case %d:" % (t + 1))
		print("%d" % ans[W - j][0])
		print("%d" % ans[W - j][1])
		t += 1

	return 0

