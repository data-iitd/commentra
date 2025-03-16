
package main;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String s1 = sc.next();
		String s2 = sc.next();
		String s3 = sc.next();
		sc.close();

		String[] s1s = s1.split("");
		String[] s2s = s2.split("");
		String[] s3s = s3.split("");

		System.out.println(s1s[0].toUpperCase() + s2s[0].toUpperCase() + s3s[0].toUpperCase());
	}
}

