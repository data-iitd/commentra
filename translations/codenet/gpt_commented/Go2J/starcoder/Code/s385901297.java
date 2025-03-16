package main;

import java.util.Arrays;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int[] ns = new int[4];
		scanner.nextLine();
		scanner.scanf("%d %d %d %d", ns);
		Arrays.sort(ns);
		if (ns[0] == 1 && ns[1] == 4 && ns[2] == 7 && ns[3] == 9) {
			System.out.println("YES");
		} else {
			System.out.println("NO");
		}
	}
}

