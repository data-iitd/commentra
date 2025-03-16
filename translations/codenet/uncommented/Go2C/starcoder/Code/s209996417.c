#include <stdio.h>
#include <math.h>

int main() {
	double n, k;
	scanf("%lf %lf", &n, &k);

	// n を k進数にした時に何桁になるか？
	//ex : 10 を 2進数 = 2^3 + 2^1 = 1010 => 4桁
	//桁数は最上位の位で決まる。この場合2^3 <= 10 < 2^4 であるため 4になった
	//抽象化すると k^x <= n < k^(x+1) を満たすxを見つけ x+1を出力する

	double x = 0.0;
	while (1) {
		double under = pow(k, x);
		double upper = pow(k, x + 1);

		if (under <= n && n < upper) {
			printf("%.0lf\n", x + 1);
			return 0;
		}
		x++;
	}
}
