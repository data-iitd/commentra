#include <iostream>

using namespace std;

a = [0] * 100100

def main():
	k = int(input())

	for i in range(k):
		a[i] = int(input())

	max = 3
	min = 2

	if a[k - 1] != 2:
		print(-1)
		return

	for i in range(k - 2, -1, -1):
		if a[i] > max:
			print(-1)
			return
		else:
			max = ((max // a[i]) + 1) * a[i] - 1
			if min % a[i] != 0:
				min = ((min // a[i]) + 1) * a[i]

		if max <= min:
			print(-1)
			return

	print(min, max)

main()

