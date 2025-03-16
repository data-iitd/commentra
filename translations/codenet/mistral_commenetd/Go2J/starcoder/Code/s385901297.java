
package main;

import java.util.Arrays;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// Initialize a new scanner to read input from standard input
		Scanner scanner = new Scanner(System.in);

		// Read the first line of input containing 4 integers and store them in ns slice
		System.out.println("Reading input");
		scanner.nextLine();
		String[] ns = scanner.nextLine().split(" ");
		int[] ns_ = new int[ns.length];
		for (int i = 0; i < ns.length; i++) {
			ns_[i] = Integer.parseInt(ns[i]);
		}

		// Sort the ns slice in ascending order
		System.out.println("Sorting the numbers in ns slice");
		Arrays.sort(ns_);

		// Check if the sorted ns slice matches the specific condition (1, 4, 7, 9)
		System.out.println("Checking the condition");
		if (ns_[0] == 1 && ns_[1] == 4 && ns_[2] == 7 && ns_[3] == 9) {
			System.out.println("The condition is true, print YES");
			System.out.println("Output: YES");
			System.out.println();
			System.out.println("End of the program");
			return;
		} else {
			System.out.println("The condition is false, print NO");
			System.out.println("Output: NO");
			System.out.println();
			System.out.println("End of the program");
			return;
		}
	}
}

