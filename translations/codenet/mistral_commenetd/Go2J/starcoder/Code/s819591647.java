//problem_b.java
// This is the main file for problem B solution

import java.io.*;
import java.util.*;

public class problem_b {

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
		for (int i = 0; i < n; i++) {
			sum += a[i];
		}

		int count = 0;
		for (int i = 0; i < n; i++) {
			double rate = (double) sum / (4 * m);
			if (a[i] >= rate) {
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

