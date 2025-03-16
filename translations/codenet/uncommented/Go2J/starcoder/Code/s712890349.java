package main;

import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int K = sc.nextInt();
		String S = sc.next();
		int[] blocks = new int[N];
		int sum = 0, zero = 0, l = 0;
		for (int r = 0; r < N; r++) {
			blocks[r] = S.charAt(r) == '0'? 1 : 0;
			sum += blocks[r];
			if (S.charAt(r) == '0') {
				zero++;
			}
			for (int k = 0; k < K && zero > K; k++) {
				sum -= blocks[l];
				if (S.charAt(l) == '0') {
					zero--;
				}
				l++;
			}
		}
		System.out.println(sum);
	}
}

