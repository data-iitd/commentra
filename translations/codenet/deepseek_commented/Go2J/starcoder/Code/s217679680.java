package main;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner stdin = new Scanner(System.in); // Initialize a new scanner to read from standard input
		int[] arr = scanArrayInt(stdin); // Call the function to get the input array of integers
		int a = arr[0], b = arr[1]; // Extract the two integers from the input array
		int tap = 0, consent = 1; // Initialize the tap counter and consent level
		while (consent < b) { // Loop until consent reaches or exceeds b
			consent += a - 1; // Increment consent by a - 1
			tap++; // Increment the tap counter
		}
		System.out.println(tap); // Print the number of taps needed
	}

	public static int[] scanArrayInt(Scanner stdin) {
		int[] ret = new int[0]; // Initialize an empty array to store the integers
		stdin.nextLine(); // Read a line of input
		for (String s : stdin.nextLine().split(" ")) { // Split the input by spaces
			int i = Integer.parseInt(s); // Convert each part to an integer
			ret = Arrays.copyOf(ret, ret.length + 1); // Append the integer to the array
			ret[ret.length - 1] = i;
		}
		return ret; // Return the array of integers
	}

}

