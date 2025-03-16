package main;

import java.io.*;
import java.util.*;

public class Main {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		int K = in.nextInt();
		System.out.println(TenToN(N, K).length());
	}

	public static String TenToN(int number, int n) {
		String s = "";
		int tmp = number;
		while (true) {
			s = i2s(tmp % n) + s;
			if (tmp < n) {
				break;
			}
			tmp /= n;
		}
		return s;
	}

	public static String i2s(int i) {
		return String.valueOf(i);
	}
}

