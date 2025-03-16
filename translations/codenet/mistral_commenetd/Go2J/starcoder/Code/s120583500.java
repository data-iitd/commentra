
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
		String[] li = s.split("");
		for (int i = 0; i < li.length; i++) {
			if (li[i].equals("A") || li[i].equals("C") || li[i].equals("G") || li[i].equals("T")) {
				count++;
			} else {
				counter = append(counter, count);
				count = 0;
			}
		}
		counter = append(counter, count);
		Arrays.sort(counter);
		System.out.println(counter[counter.length - 1]);
	}
}

