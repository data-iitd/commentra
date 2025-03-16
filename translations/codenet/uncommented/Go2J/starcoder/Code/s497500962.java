package main;

import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) {
		new Main().run();
	}

	public void run() {
		Scanner sc = new Scanner(System.in);

		int R = nextInt(sc);
		int G = nextInt(sc);
		int B = nextInt(sc);
		int N = nextInt(sc);

		int ans = 0;
		for (int x = 0; x <= N; x++) {
			for (int y = 0; y <= N; y++) {
				int tmp = N - R * x - G * y;
				if (tmp >= 0 && tmp % B == 0) {
					ans++;
				}
			}
		}

		System.out.println(ans);
	}

	public int nextInt(Scanner sc) {
		sc.next();
		return Integer.parseInt(sc.nextLine());
	}
}

// END-OF-CODE

// Util. ----------

public class Util {
	public static int min(int a, int b) {
		return a < b? a : b;
	}

	public static int max(int a, int b) {
		return a > b? a : b;
	}

	public static int abs(int a) {
		return a < 0? -a : a;
	}
}

// ---------- Util.

'''
