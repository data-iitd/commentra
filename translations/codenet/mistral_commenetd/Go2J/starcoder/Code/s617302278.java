
// Importing required packages
import java.util.*;
import java.io.*;

// Class declaration
public class Main {
	// Main function
	public static void main(String[] args) {
		// Reading integers from stdin as a line text
		Scanner sc = new Scanner(System.in);
		String[] tmp = sc.nextLine().split(" ");
		int x = Integer.parseInt(tmp[0]);
		// Initializing sum variable as zero
		int sum = 0;
		// Initializing index variable as one
		int i = 1;
		// Looping until the sum is greater than or equal to x
		while (true) {
			// Adding current index to sum
			sum += i;
			// Checking if sum is greater than or equal to x
			if (sum >= x) {
				// Breaking the loop
				break;
			}
			// Incrementing index
			i++;
		}
		// Printing the index
		System.out.println(i);
	}
}

