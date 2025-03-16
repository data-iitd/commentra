#include <iostream>

using namespace std;

int main() {
	int m, f, r;
	while (cin >> m >> f >> r && (m != -1 || f != -1 || r != -1)):
		if m == -1 or f == -1:
			print("F")
		elif m + f >= 80:
			print("A")
		elif m + f >= 65:
			print("B")
		elif m + f >= 50 or r >= 50:
			print("C")
		elif m + f >= 30:
			print("D")
		else:
			print("F")
		print()

	return 0
}

