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
		int[] dict = new int[3];
		for (int i = 0; i < N; i++) {
			dict[T.charAt(i) - 'r']++;
		}
		int res = 0;
		for (int i = 0; i < N; i++) {
			if (i >= K) {
				if (T.charAt(i) == T.charAt(i - K)) {
					switch (T.charAt(i)) {
					case's':
						if (dict[0] > 0) {
							dict[0]--;
							continue;
						} else {
							dict[0]++;
						}
					case 'r':
						if (dict[1] > 0) {
							dict[1]--;
							continue;
						} else {
							dict[1]++;
						}
					case 'p':
						if (dict[2] > 0) {
							dict[2]--;
							continue;
						} else {
							dict[2]++;
						}
					}
				} else {
					switch (T.charAt(i)) {
					case's':
						dict[0]++;
					case 'r':
						dict[1]++;
					case 'p':
						dict[2]++;
					}
				}
			}
			switch (T.charAt(i)) {
			case's':
				dict[0]++;
			case 'r':
				dict[1]++;
			case 'p':
				dict[2]++;
			}
		}
		res = P * dict[1] + S * dict[2] + R * dict[0];
		System.out.println(res);
	}
}

