package main;

import java.util.*;
import java.io.*;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int sqrtN = (int) Math.sqrt(N);

		int min = N;
		for (int i = 1; i <= sqrtN; i++) {
			if (N % i!= 0) {
				continue;
			}

			int num = i + (N / i) - 2;
			if (num < min) {
				min = num;
			}
		}

		System.out.println(min);
	}
}

