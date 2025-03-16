
package main;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int K = sc.nextInt();
		int R = sc.nextInt();
		int S = sc.nextInt();
		int P = sc.nextInt();
		String T = sc.next();

		int[] s = new int[N];
		int[] r = new int[N];
		int[] p = new int[N];
		for (int i = 0; i < N; i++) {
			s[i] = 1;
			r[i] = 1;
			p[i] = 1;
		}
		int[] dict = new int[3];
		String char = "";
		for (int i = 0; i < T.length(); i++) {
			char = T.substring(i, i + 1);
			if (i >= K) {
				if (char.equals(T.substring(i - K, i + 1 - K))) {
					switch (char) {
					case "s":
						if (s[i % K] == 1) {
							s[i % K] = 0;
							continue;
						} else {
							s[i % K] = 1;
						}
					case "r":
						if (r[i % K] == 1) {
							r[i % K] = 0;
							continue;
						} else {
							r[i % K] = 1;
						}
					case "p":
						if (p[i % K] == 1) {
							p[i % K] = 0;
							continue;
						} else {
							p[i % K] = 1;
						}
					}
				} else {
					switch (char) {
					case "s":
						s[i % K] = 1;
					case "r":
						r[i % K] = 1;
					case "p":
						p[i % K] = 1;
					}
				}
			}
			switch (char) {
			case "s":
				dict[0] = dict[0] + 1;
			case "r":
				dict[1] = dict[1] + 1;
			case "p":
				dict[2] = dict[2] + 1;
			}
		}

		int res = P * dict[1] + S * dict[2] + R * dict[0];
		System.out.println(res);
	}
}

