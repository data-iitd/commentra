package main;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String text = sc.next();
		int limit = text.length();

		int start = 0;
		int middle = 0;
		int end = 0;
		boolean firstPrinted = false;

		for (end = 0; end < limit; end++) {
			start = 0;
			middle = 0;
			for (start = 0; start < end; start++) {
				if (text.charAt(start)!= 'R') {
					middle = start;
					break;
				}
			}

			for (int i = middle; i < end; i++) {
				if (text.charAt(i)!= 'L') {
					end = i;
					break;
				}
			}

			int len1 = middle - start;
			int len2 = end - middle;

			for (int i = start; i < middle - 1; i++) {
				if (firstPrinted) {
					System.out.print(" ");
				}
				System.out.print("0");
				firstPrinted = true;
			}

			int count1 = (len1 + 1) / 2 + len2 / 2;
			int count2 = len1 / 2 + (len2 + 1) / 2;

			if (firstPrinted) {
				System.out.print(" ");
			}
			System.out.printf("%d %d", count1, count2);
			firstPrinted = true;

			for (int i = middle + 1; i < end; i++) {
				if (firstPrinted) {
					System.out.print(" ");
				}
				System.out.print("0");
				firstPrinted = true;
			}
			start = end;
			firstPrinted = true;
		}
		System.out.println();
	}
}

