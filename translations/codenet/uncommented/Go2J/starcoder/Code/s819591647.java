//problem_b.java

import java.util.*;
import java.io.*;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		BufferedWriter wr = new BufferedWriter(new OutputStreamWriter(System.out));

		try {
			int n = sc.nextInt();
			int m = sc.nextInt();
			int[] a = new int[n];
			for (int i = 0; i < n; i++) {
				a[i] = sc.nextInt();
			}

			int sum = 0;
			for (int v : a) {
				sum += v;
			}

			int count = 0;
			for (int v : a) {
				double rate = (double) sum / (4 * m);
				if (v >= rate) {
					count++;
				}
			}

			if (count >= m) {
				wr.write("Yes");
			} else {
				wr.write("No");
			}

			wr.flush();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(1);
		}
	}
}

