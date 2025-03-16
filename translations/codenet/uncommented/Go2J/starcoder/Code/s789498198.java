package main;

import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int[] AB = new int[2];
		AB[0] = sc.nextInt();
		AB[1] = sc.nextInt();
		int A = AB[0];
		int B = AB[1];
		if ((A + B) % 2 == 0) {
			System.out.println((A + B) / 2);
			return;
		}
		System.out.println("IMPOSSIBLE");
	}
}

