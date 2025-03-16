
// ABC 152-D
// 2020.1.19 bal4u

#include <iostream>

using namespace std;

int main()
{
	int i, N, ans;
	
	N = 123; // input
	int f1[100] = {}, f2[100] = {};
	while (N) {
		int k = N % 10;
		while (N >= 10) N /= 10;
		++f1[10*k + N], ++f2[N*10 + k];
	}

	ans = 0;
	for (i = 0; i < 100; ++i) ans += f1[i] * f2[i];
	cout << ans << endl;
	return 0;
}
