// ABC 152-D
// 2020.1.19 bal4u

import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N, ans, i;
		N = sc.nextInt();
		while (N > 0) {
			int n = N % 10;
			while (N >= 10) N /= 10;
			++f1[10*n + N], ++f2[N*10 + n];
			N--;
		}
		ans = 0;
		for (i = 0; i < 100; ++i) ans += f1[i] * f2[i];
		System.out.println(ans);
	}
	static int f1[100], f2[100];
}

