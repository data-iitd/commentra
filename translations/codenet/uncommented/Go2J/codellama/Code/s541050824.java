
package main

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer tokenizer = new StringTokenizer(reader.readLine());
		int N = Integer.parseInt(tokenizer.nextToken());
		long[] T = new long[N];
		long[] A = new long[N];
		for (int i = 0; i < N; i++) {
			String[] line = reader.readLine().split(" ");
			T[i] = Long.parseLong(line[0]);
			A[i] = Long.parseLong(line[1]);
		}
		long t = T[0], a = A[0];
		for (int i = 1; i < N; i++) {
			long r = Math.max(t / T[i], a / A[i]);
			t = T[i] * r;
			a = A[i] * r;
		}
		System.out.println(t + a);
	}
}

