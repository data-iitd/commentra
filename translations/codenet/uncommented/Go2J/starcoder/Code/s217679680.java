package main;

import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int[] arr = scanArrayInt(sc);
		int a = arr[0], b = arr[1];
		int tap = 0, consent = 1;
		while (consent < b) {
			consent += a - 1;
			tap++;
		}
		System.out.println(tap);
	}

	public static int[] scanArrayInt(Scanner sc) {
		String[] s = sc.nextLine().split(" ");
		int[] ret = new int[s.length];
		for (int i = 0; i < s.length; i++) {
			ret[i] = Integer.parseInt(s[i]);
		}
		return ret;
	}
}

