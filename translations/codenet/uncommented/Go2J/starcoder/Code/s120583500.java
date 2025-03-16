package main;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		int count = 0;
		int[] counter = new int[1];
		counter[0] = 0;
		if (s.equals("")) {
			return;
		}
		for (int i = 0; i < s.length(); i++) {
			if (s.charAt(i) == 'A' || s.charAt(i) == 'C' || s.charAt(i) == 'G' || s.charAt(i) == 'T') {
				count++;
			} else {
				counter = new int[counter.length + 1];
				counter[counter.length - 1] = count;
				count = 0;
			}
		}
		counter = new int[counter.length + 1];
		counter[counter.length - 1] = count;
		Arrays.sort(counter);
		System.out.println(counter[counter.length - 1]);
	}
}

