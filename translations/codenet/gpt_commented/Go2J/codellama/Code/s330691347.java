
package main;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int L = sc.nextInt();
		Data[] s = new Data[N];
		for (int i = 0; i < N; i++) {
			s[i] = new Data(sc.next());
		}
		sort(s);
		String ans = "";
		for (int i = 0; i < N; i++) {
			ans += s[i].X;
		}
		System.out.println(ans);
	}

	public static void sort(Data[] s) {
		for (int i = 0; i < s.length - 1; i++) {
			for (int j = i + 1; j < s.length; j++) {
				if (s[i].X.compareTo(s[j].X) > 0) {
					Data temp = s[i];
					s[i] = s[j];
					s[j] = temp;
				}
			}
		}
	}

	public static class Data {
		public String X;

		public Data(String X) {
			this.X = X;
		}
	}
}

