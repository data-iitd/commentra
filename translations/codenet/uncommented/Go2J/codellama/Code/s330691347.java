
package main;

import java.util.Scanner;

public class Main {

	public static void out(Object... x) {
		//		System.out.println(x);
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int N = sc.nextInt();
		int L = sc.nextInt();
		Data[] s = new Data[N];

		for (int i = 0; i < N; i++) {
			s[i] = new Data();
			s[i].X = sc.next();
		}

		out(N, L, s);
		sort(s);
		out(s);

		String ans = "";
		for (int i = 0; i < N; i++) {
			ans = ans + s[i].X;
		}
		System.out.println(ans);

	}

	static class Data implements Comparable<Data> {
		String X;

		@Override
		public int compareTo(Data o) {
			return this.X.compareTo(o.X);
		}
	}

	static void sort(Data[] s) {
		for (int i = 0; i < s.length; i++) {
			for (int j = i + 1; j < s.length; j++) {
				if (s[i].compareTo(s[j]) > 0) {
					Data temp = s[i];
					s[i] = s[j];
					s[j] = temp;
				}
			}
		}
	}

}

