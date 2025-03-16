
package main;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int L = sc.nextInt();
		String[] s = new String[N];

		for (int i = 0; i < N; i++) {
			s[i] = sc.next();
		}

		System.out.println(N + " " + L + " " + s);
		sort(s);
		System.out.println(s);

		String ans = "";
		for (int i = 0; i < N; i++) {
			ans = ans + s[i];
		}
		System.out.println(ans);
	}

	public static void sort(String[] s) {
		for (int i = 0; i < s.length; i++) {
			for (int j = i + 1; j < s.length; j++) {
				if (s[i].compareTo(s[j]) > 0) {
					String temp = s[i];
					s[i] = s[j];
					s[j] = temp;
				}
			}
		}
	}
}

