package main;

import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		BufferedWriter wtr = new BufferedWriter(new OutputStreamWriter(System.out));
		int A = sc.nextInt();
		int B = sc.nextInt();
		int C = sc.nextInt();
		int K = sc.nextInt();
		int ma = Math.max(A, Math.max(B, C));
		int rest = 0;
		if (ma == A) {
			rest += B + C;
		} else if (ma == B) {
			rest += A + C;
		} else {
			rest += A + B;
		}
		for (int i = 1; i <= K; i++) {
			ma *= 2;
		}
		System.out.println(ma + rest);
		wtr.flush();
		wtr.close();
	}
}

