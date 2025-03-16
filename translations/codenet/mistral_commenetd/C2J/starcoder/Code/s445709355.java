// ABC 152-D
// 2020.1.19 bal4u

import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N, ans, i;
		N = sc.nextInt(); // 入力数を入力する
		while (N > 0) { // Nが0以外である限り
			int n = N % 10; // nの最後の桁を取得
			while (N >= 10) { // nが10の倍数である限りnを10で割る
				N /= 10;
			}
			++f1[10*n + N]; // f1配列の[10*k+n]番目にカウントアップ
			++f2[n*10 + k]; // f2配列の[n*10+k]番目にカウントアップ
			N--; // Nを1減らす
		}

		ans = 0; // 答えを初期化
		for (i = 0; i < 100; ++i) { // f1, f2配列をループして答えを計算
			ans += f1[i] * f2[i];
		}
		System.out.println(ans); // 答えを出力
	}
}

