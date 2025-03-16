package main;

import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);

		int[] a = sc.nextLine().split(" ");
		int N = Integer.parseInt(a[0]);
		int D = Integer.parseInt(a[1]);

		int[][] lines = new int[N][2];
		for (int i = 0; i < N; i++) {
			lines[i] = sc.nextLine().split(" ");
		}

		int count = 0;
		for (int[] line : lines) {
			double d = Math.sqrt(line[0] * line[0] + line[1] * line[1]);
			if (d >= D) {
				count++;
			}
		}
		System.out.println(count);
	}
}

