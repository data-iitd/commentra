#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	vector<int> m;
	m.push_back(10);
	m.push_back(50);
	m.push_back(100);
	m.push_back(500);

	bool first = True;
	for money in iter(input, ''):
		if not first:
			print()

		first = False
		sum = 0
		num = [0] * 4
		for i in range(4):
			num[i] = int(input())
			sum += num[i] * m[i]

		change = sum - int(money)
		for i in range(3, -1, -1):
			if change // m[i]:
				num[i] = num[i] - change // m[i]
				change %= m[i]

		for i in range(4):
			if num[i] > 0:
				print(m[i], num[i])

	return EXIT_SUCCESS
}

