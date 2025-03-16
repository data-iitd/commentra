#include <iostream>
#include <vector>

using namespace std;

vector<int> f1(100), f2(100);

void calc(int n) {
	int k = n % 10;
	while (n >= 10) {
		n /= 10;
	}
	++f1[10*k + n];
	++f2[n*10 + k];
}

int main()
{
	int i, N, ans;

	cin >> N;
	while (N) {
		calc(N);
		N--;
	}

	ans = 0;
	for (i = 0; i < 100; ++i) {
		ans += f1[i] * f2[i];
	}
	cout << ans << endl;
	return 0;
}

