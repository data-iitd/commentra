package main;

import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		try (BufferedReader reader = new BufferedReader(new InputStreamReader(System.in))) {
			try (BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out))) {
				solve(reader, writer);
			}
		}
	}

	public static void solve(BufferedReader reader, BufferedWriter writer) throws IOException {
		int N = Integer.parseInt(reader.readLine());
		int[] T = new int[N];
		int[] A = new int[N];
		for (int i = 0; i < N; i++) {
			String[] line = reader.readLine().split(" ");
			T[i] = Integer.parseInt(line[0]);
			A[i] = Integer.parseInt(line[1]);
		}
		int t = T[0], a = A[0];
		for (int i = 1; i < N; i++) {
			int r = Math.max(Math.ceil((double) t / T[i]), Math.ceil((double) a / A[i]));
			t = T[i] * r;
			a = A[i] * r;
		}
		writer.write(t + a + "\n");
	}
}

