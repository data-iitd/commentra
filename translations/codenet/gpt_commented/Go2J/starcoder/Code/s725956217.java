package main;

import java.util.Arrays;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int M = sc.nextInt();
		shop[] s = new shop[N];
		for (int i = 0; i < N; i++) {
			int a = sc.nextInt();
			int b = sc.nextInt();
			s[i] = new shop(a, b);
		}
		Arrays.sort(s);
		int total = 0;
		for (shop e : s) {
			int n = Math.min(e.b, M);
			total += n * e.a;
			M -= n;
			if (M == 0) {
				break;
			}
		}
		System.out.println(total);
	}
}

class shop implements Comparable<shop> {
	int a, b;

	public shop(int a, int b) {
		this.a = a;
		this.b = b;
	}

	@Override
	public int compareTo(shop o) {
		return a - o.a;
	}
}

