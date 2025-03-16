package main;

import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		// Step 3: Create a slice of integers with a length of 3
		int[] in = new int[3];
		
		// Step 4: Prompt the user to input three integers
		Scanner scanner = new Scanner(System.in);
		for (int i = 0; i < in.length; i++) {
			in[i] = scanner.nextInt();
		}
		
		// Step 5: Sort the slice of integers in ascending order
		Arrays.sort(in);
		
		// Step 6: Perform a calculation using the sorted integers and print the result
		System.out.println(in[2]*10 + in[1] + in[0]);
	}
}

