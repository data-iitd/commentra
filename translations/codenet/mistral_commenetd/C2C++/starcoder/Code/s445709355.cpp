// ABC 152-D
// 2020.1.19 bal4u

#include <cstdio>

#define gc() getchar_unlocked()

int in() {   // 非負整数の入力
	int n = 0, c = gc();
	do {
		n = 10 * n + (c & 0xf); // 数字の桁数を10倍して加算
	} while ((c = gc()) >= '0'); // 次の数字を入力する
	return n;
}

int f1[100], f2[100];

void calc(int n) { // nを処理する関数
	int k = n % 10; // nの最後の桁を取得
	while (n >= 10) { // nが10の倍数である限りnを10で割る
		n /= 10;
	}
	++f1[10*k + n]; // f1配列の[10*k+n]番目にカウントアップ
	++f2[n*10 + k]; // f2配列の[n*10+k]番目にカウントアップ
}

int main()
{
	int i, N, ans;

	N = in(); // 入力数を入力する
	while (N) { // Nが0以外である限り
		calc(N); // calc関数を呼び出す
		N--; // Nを1減らす
	}

	ans = 0; // 答えを初期化
	for (i = 0; i < 100; ++i) { // f1, f2配列をループして答えを計算
		ans += f1[i] * f2[i];
	}
	printf("%d\n", ans); // 答えを出力
	return 0;
}

