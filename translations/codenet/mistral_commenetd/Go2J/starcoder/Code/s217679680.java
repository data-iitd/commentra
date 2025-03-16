
import java.util.*;
import java.io.*;

public class Main {

	// Function to read an array of integers from stdin and return it
	public static int[] scanArrayInt() {
		// Initialize an empty array to store the integers
		int[] ret = new int[0];
		// Read the input line from stdin
		Scanner stdin = new Scanner(System.in);
		stdin.nextLine();
		// Split the input line by space
		String[] input = stdin.nextLine().split(" ");
		// Iterate through each element in the input array and convert it to integer
		for (int i = 0; i < input.length; i++) {
			// Convert the string to integer and append it to the array
			ret = Arrays.copyOf(ret, ret.length + 1);
			ret[ret.length - 1] = Integer.parseInt(input[i]);
		}
		// Return the array of integers
		return ret;
	}

	// Function to initialize variables and start the main logic
	public static void main(String[] args) {
		// Read the array of integers from stdin
		int[] arr = scanArrayInt();
		// Initialize variables a and b with the first two elements of the array
		int a = arr[0], b = arr[1];
		// Initialize variables tap and consent with default values
		int tap = 0, consent = 1;
		// Loop until consent is greater than or equal to b
		while (consent < b) {
			// Increment consent by the sum of a and consent minus one
			consent = consent + a - 1;
			// Increment tap by one for each iteration
			tap++;
		}
		// Print the result, i.e., the number of taps required
		System.out.println(tap);
	}
}

