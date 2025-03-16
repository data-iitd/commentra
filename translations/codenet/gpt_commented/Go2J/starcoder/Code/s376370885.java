// by syu
package main;

import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int k = in.nextInt();
		if (n % k == 0) {
			System.out.println(0);
		} else {
			System.out.println(1);
		}
	}
}

