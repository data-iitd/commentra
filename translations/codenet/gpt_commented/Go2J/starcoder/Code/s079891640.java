package main;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		sc.close();

		for (int i = 0; i < s.length(); i++) {
			if (s.substring(i + 1).contains(s.substring(i, i + 1))) {
				System.out.println("no");
				return;
			}
		}

		System.out.println("yes");
	}
}

