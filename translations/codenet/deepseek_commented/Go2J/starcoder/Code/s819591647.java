//problem_b.java

import java.io.*;
import java.util.*;

public class Main {

	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		BufferedWriter wr = new BufferedWriter(new OutputStreamWriter(System.out));

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

		wr.close();
		sc.close();
	}

}

