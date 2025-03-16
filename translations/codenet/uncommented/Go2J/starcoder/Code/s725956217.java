package main;

import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);

		int N = sc.nextInt();
		int M = sc.nextInt();
		Shop[] s = new Shop[N];
		for (int i = 0; i < N; i++) {
			int a = sc.nextInt();
			int b = sc.nextInt();
			s[i] = new Shop(a, b);
		}
		Arrays.sort(s);

		int total = 0;
		for (Shop e : s) {
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

class Shop implements Comparable<Shop> {
	int a, b;

	public Shop(int a, int b) {
		this.a = a;
		this.b = b;
	}

	@Override
	public int compareTo(Shop o) {
		return a - o.a;
	}
}

