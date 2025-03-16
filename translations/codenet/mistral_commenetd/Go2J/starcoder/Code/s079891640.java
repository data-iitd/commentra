
package main;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		for (int i = 0; i < s.length(); i++) {
			if (s.contains(s.substring(i + 1, i + 2))) {
				System.out.println("no");
				return;
			}
		}
		System.out.println("yes");
	}
}

